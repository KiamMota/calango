#ifndef _KEYBOARD_HH_
#define _KEYBOARD_HH_

#include "input/keyboard/ikeyboard.hpp"
#ifdef __linux__

#include "input/keyboard/backend/linux_keyboard.hh"

#endif

namespace Keyboard {

IKeyboard *Start() {
#ifdef __linux__
  Backend::LinuxKeyboard *linux_instance = new Backend::LinuxKeyboard();
  return linux_instance;
#endif
} // namespace Keyboard

} // namespace Keyboard
#endif // _KEYBOARD_HH_
