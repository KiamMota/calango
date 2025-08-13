#ifndef _KEYBOARD_HH_
#define _KEYBOARD_HH_

#include "cppinput/internal/ikeyboard.hh"
#include "internal/linux_keyboard.hh"
#include <cstdlib>
#include <fcntl.h>

enum KB_KEYS { KB_W, KB_A, KB_D, KB_S };

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
