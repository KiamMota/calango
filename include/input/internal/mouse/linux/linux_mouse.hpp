#ifdef __linux__
#ifndef _LINUXMOUSE_HPP_
#define _LINUXMOUSE_HPP_

#include "input/internal/mouse/imouse.hpp"
#include <cstring>
#include <fcntl.h>
#include <filesystem>
#include <functional>
#include <iostream>
#include <linux/input.h>
#include <string>
#include <unistd.h>
#include <vector>
#define LINUX_GLOBAL_KBFD "/dev/input/by-id/"

namespace Backend {

class LinuxMouse : public Mouse::IMouse {
private:
  int main_descriptor;
  int x;
  int y;
  input_event ev;
  std::string fileNameDescriptor;
  void FindKeyboardDevice() {
    const char *trigger = "event-mouse";

    std::filesystem::path linux_input_descriptor = LINUX_GLOBAL_KBFD;
    std::vector<std::string> devices;
    for (auto &v :
         std::filesystem::directory_iterator(linux_input_descriptor)) {
      devices.push_back(v.path().filename().string());
    }

    for (int i = 0; i < devices.size(); i++) {
      if (devices.at(i).find(trigger) != std::string::npos) {
        fileNameDescriptor = LINUX_GLOBAL_KBFD + devices.at(i);
      }
    }
  }

  bool ReadFd() {
    if (read(main_descriptor, &ev, sizeof(ev)) == -1)
      return false;
    return true;
  }

public:
  LinuxMouse() {
    FindKeyboardDevice();
    main_descriptor = open(fileNameDescriptor.c_str(), O_RDONLY);
    if (main_descriptor == -1) {
      std::cerr << "error: cant open mouse file descriptor." << std::endl;
    }
  }

  bool Listen() override { return read(main_descriptor, &ev, sizeof(ev)) > 0; }

  void Stop() override {
    close(main_descriptor);
    memset(&main_descriptor, 0, sizeof(main_descriptor));
    memset(&ev, 0, sizeof(ev));
  }

  bool IsMoving() override {
    if (ev.type == EV_REL) {
      return true;
    }
    return false;
  }

  bool IsButtonPressed(Mouse::MS_BUTTONS mouse) override {
    if (ev.type == EV_KEY && ev.value == 1)
      return (ev.code == mouse) ? true : false;
    return false;
  }

  bool IsButtonReleased(Mouse::MS_BUTTONS ms) override {
    if (ev.type == EV_KEY && ev.code == ms)
      return (ev.value == 0) ? true : false;
    return false;
  }

  bool IsScrollingVertical() override {
    if (ev.type == EV_REL && ev.code == REL_WHEEL) {
      return (ev.value != 0) ? true : false;
    }
    return false;
  }

  bool IsScrollingHorizontal() override {
    if (ev.type == EV_REL && ev.code == REL_HWHEEL) {
      return (ev.value != 0) ? true : false;
    }
    return false;
  }

  short GetScrollAmount() override {
    if (ev.type == EV_REL)
      if (ev.code == REL_WHEEL || ev.code == REL_HWHEEL)
        return ev.value;
    return 0;
  }

  bool IsPressed() override {
    if (ev.type == EV_KEY) {
      switch (ev.code) {
      default:
        return false;
      case BTN_RIGHT:
        if (ev.value == 1)
          return true;
      case BTN_LEFT:
        if (ev.value == 1)
          return true;
      case BTN_MIDDLE:
        if (ev.value == 1)
          return true;
      }
    }
    return false;
  }

  bool IsReleased() override {
    if (ev.type == EV_KEY) {
      switch (ev.code) {
      default:
        return false;
      case BTN_RIGHT:
        if (ev.value == 0)
          return true;
      case BTN_LEFT:
        if (ev.value == 0)
          return true;
      case BTN_MIDDLE:
        if (ev.value == 0)
          return true;
      }
    }
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
};
} // namespace Backend
#endif // _LINUXMOUSE_HPP_

#endif // __linux__
