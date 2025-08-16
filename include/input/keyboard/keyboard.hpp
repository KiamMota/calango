#ifndef _KEYBOARD_HPP_
#define _KEYBOARD_HPP_

#ifdef __linux__
#include "input/keyboard/internal/linux_keyboard.hpp"
#endif

#ifdef _WIN32
#include "input/keyboard/internal/windows_keyboard.hpp"
#endif

namespace Keyboard {
IKeyboard *GetBackend() {
#ifdef __linux__
  Backend::LinuxKeyboard *lnx_kb_instance = new Backend::LinuxKeyboard();
  return lnx_kb_instance;
#endif
#ifdef _WIN32
  Backend::WindowsKeyboard *win_kb_instance = new Backend::WindowsKeyboard();
  return win_kb_instance;
#endif
}
} // namespace Keyboard

#endif
