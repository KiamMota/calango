#ifndef _KEYBOARD_HH_
#define _KEYBOARD_HH_

#include "cppinput/internal/ikeyboard.hh"
#include "cppinput/internal/linux_keyboard.hh"
#include <cstdlib>
#include <fcntl.h>

class Keyboard {
public:
  static IKeyboard *Init() {
#ifdef __linux__
    LinuxKeyboard *linux_instance = new LinuxKeyboard();
    return linux_instance;
#endif
  }

private:
  Keyboard();
};

#endif // _KEYBOARD_HH_
