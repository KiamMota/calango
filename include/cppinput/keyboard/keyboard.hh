#ifndef _KEYBOARD_HH_
#define _KEYBOARD_HH_

#include "cppinput/backend/ikeyboard.hh"
#include "cppinput/backend/linux_keyboard.hh"
#include <cstdlib>
#include <fcntl.h>

namespace Keyboard {

class GetKeyboard {
public:
  static Backend::IKeyboard *Init() {
#ifdef __linux__
    Backend::LinuxKeyboard *linux_instance = new Backend::LinuxKeyboard();
    return linux_instance;
#endif
  }

private:
  GetKeyboard();
};
} // namespace Keyboard
#endif // _KEYBOARD_HH_
