#ifndef _KEYBOARD_HH_
#define _KEYBOARD_HH_

#include "input/keyboard/backend/linux_keyboard.hh"
#include "input/keyboard/ikeyboard.hh"
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
