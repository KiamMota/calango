#ifndef _KEYBOARD_HH_
#define _KEYBOARD_HH_

#include "cppinput/backend/ikeyboard.hh"
#include "cppinput/backend/linux_keyboard.hh"
#include <cstdlib>
#include <fcntl.h>

namespace Keyboard {

IKeyboard *GetKeyboard() {
#ifdef __linux__
  Backend::LinuxKeyboard *linux_instance = new Backend::LinuxKeyboard();
  return linux_instance;
#endif
} // namespace Keyboard

} // namespace Keyboard
#endif // _KEYBOARD_HH_
