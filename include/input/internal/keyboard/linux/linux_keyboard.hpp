#include <cstring>
#include <functional>
#include <linux/input-event-codes.h>
#ifdef __linux__

#ifndef _LINUXKEYBOARD_HH_
#define _LINUXKEYBOARD_HH_

/* local headers */
#include "input/internal/keyboard/ikeyboard.hpp"
#include "input/internal/keyboard/linux/linux_kbkeys.hpp"

#include <iostream>
/* linux definitions */
#define LINUX_GLOBAL_KBFD "/dev/input/by-id/"
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

  ~LinuxKeyboard() { Stop(); }

  bool Listen() override { return read(file_descriptor, &ev, sizeof(ev)) > 0; }

  void Stop() override {
    close(file_descriptor);
    file_descriptor = -1;
    memset(&ev, 0, sizeof(ev));
  }

  bool IsPressed() override {
    if (ev.type == EV_KEY && ev.value == 1)
      return true;
    return false;
  }

  bool IsReleased() override {
    if (ev.type == EV_KEY && ev.value == 0)
      return true;
    return false;
  }

  void IsPressed(std::function<void()> callback) override {
    while (Listen()) {
      if (IsPressed()) {
        callback();
        return;
      }
    }
  }

  void IsReleased(std::function<void()> callback) override {
    while (Listen()) {
      if (IsReleased()) {
        callback();
        return;
      }
    }
  }

  bool IsKeyPressed(Keyboard::KB_KEYS kb) override {
    if (ev.type == EV_KEY && ev.value == 1) {
      if (ev.code == kb)
        return true;
    }
    return false;
  }

  bool IsKeyReleased(Keyboard::KB_KEYS kb) override {
    if (ev.type == EV_KEY && ev.value == 0) {
      return (ev.code == kb) ? true : false;
    }
    return false;
  }

  Keyboard::KB_KEYS GetKey() override { return (Keyboard::KB_KEYS)ev.code; }

private:
  std::string file_name_descriptor;
  int file_descriptor;
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

#endif // _LINUXKEYBOARD_HH_
#endif // __linux__
