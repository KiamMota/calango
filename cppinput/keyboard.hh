#ifndef _KEYBOARD_HH_
#define _KEYBOARD_HH_

#include <filesystem>
#include <iostream>
#include <vector>

#ifdef __linux__
#include <linux/input.h>

class Keyboard {
private:
  int file_descriptor;
  input_event ev;

public:
  Keyboard() { FindKeyboardDevice(); }

private:
  void FindKeyboardDevice() {
    std::filesystem::path linux_input_descriptor = "/dev/input/by-id/";
    std::vector<std::string> devices;
    for (auto &v :
         std::filesystem::directory_iterator(linux_input_descriptor)) {
      devices.push_back(v.path().filename().string());
    }
    for (int i = 0; i < devices.size(); i++) {
      std::cout << "devices" << devices.at(i) << std::endl;
    }
  }
};

#endif

#endif // _KEYBOARD_HH_
