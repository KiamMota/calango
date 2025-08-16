#ifndef _KEYBOARD_HPP_
#define _KEYBOARD_HPP_

#include "input/internal/keyboard/kbkeys.hpp"

#ifdef __linux__
#include "input/internal/keyboard/linux_keyboard.hpp"
#endif

#ifdef _WIN32
#include "input/keyboard/internal/windows_keyboard.hpp"
#endif

namespace Keyboard {
static IKeyboard *GetBackend() {
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
