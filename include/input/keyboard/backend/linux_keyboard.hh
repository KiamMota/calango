
#include <functional>
#include <linux/input-event-codes.h>
#include <thread>
#ifdef __linux__

#ifndef _UNIXKBD_HH_
#define _UNIXKBD_HH_

#define LINUX_GLOBAL_KBFD "/dev/input/by-id/"
#include "input/keyboard/ikeyboard.hh"
#include "input/keyboard/kb_keys.hh"
#include "input/keyboard/options.hh"
#include <fcntl.h>
#include <filesystem>
#include <linux/input.h>
#include <unistd.h>

namespace Backend {

class LinuxKeyboard : public Keyboard::IKeyboard {

public:
  LinuxKeyboard() {
    FindKeyboardDevice();
    file_descriptor = open(file_name_descriptor.c_str(), O_RDONLY);
    if (file_descriptor == -1) {
      std::cerr << "error: cant open file descriptor." << std::endl;
      return;
    }
  }

  bool IsPressed() override {
    if (ReadFd())
      if (ev.type == EV_KEY && ev.value == 1)
        return true;
    return false;
  }

  bool IsReleased() override {
    if (ReadFd())
      if (ev.type == EV_KEY && ev.value == 0)
        return true;
    return false;
  }

  bool IsRepeated() override {
    if (ReadFd())
      if (ev.type == EV_KEY && ev.value == 2)
        return true;
    return false;
  }

  bool IsKeyPressed(Keyboard::KB_KEYS kb) override {
    if (ev.type == EV_KEY && ev.value == 1) {
      if (ev.code == kb)
        return true;
    }
    return false;
  }

  int GetCode() override { return ev.code; }

private:
  bool ReadFd() {
    return_read = read(file_descriptor, &ev, sizeof(ev));
    if (return_read == -1)
      return false;
    return true;
  }

  std::string file_name_descriptor;
  int file_descriptor;
  int return_read;
  input_event ev;

  void FindKeyboardDevice() {
    const char *trigger = "event-kbd";

    std::filesystem::path linux_input_descriptor = LINUX_GLOBAL_KBFD;
    std::vector<std::string> devices;
    for (auto &v :
         std::filesystem::directory_iterator(linux_input_descriptor)) {
      devices.push_back(v.path().filename().string());
    }

    for (int i = 0; i < devices.size(); i++) {
      if (devices.at(i).find(trigger) != std::string::npos) {
        file_name_descriptor = LINUX_GLOBAL_KBFD + devices.at(i);
      }
    }
  }
};

} // namespace Backend

#endif // _UNIXKBD_HH_
#endif // __linux__
