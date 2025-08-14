#ifndef _KEYBOARD_HH_
#define _KEYBOARD_HH_

#include "input/keyboard/ikeyboard.hpp"
#ifdef __linux__

#include "input/keyboard/backend/linux_keyboard.hh"

#endif

namespace Keyboard {

#ifdef __linux__

typedef Backend::LinuxKeyboard KeyboardObject;

#endif

IKeyboard *GetBackend() {
#ifdef __linux__
  Backend::LinuxKeyboard *linux_instance = new Backend::LinuxKeyboard();
  return linux_instance;
#endif
} // namespace Keyboard

} // namespace Keyboard
#endif // _KEYBOARD_HH_
