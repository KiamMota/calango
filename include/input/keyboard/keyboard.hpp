#ifndef _KEYBOARD_HPP_
#define _KEYBOARD_HPP_

#include "input/keyboard/internal/ikeyboard.hpp"
#ifdef __linux__
#include "input/keyboard/internal/linux_keyboard.hpp"
#endif

namespace Keyboard {
IKeyboard *GetBackend() {
#ifdef __linux__
  Backend::LinuxKeyboard *lnx_kb_instance = new Backend::LinuxKeyboard();
  return lnx_kb_instance;
#endif
}
} // namespace Keyboard

#endif
