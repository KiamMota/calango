#ifndef _KEYBOARD_HPP_
#define _KEYBOARD_HPP_

#ifdef __linux__
#include "input/internal/keyboard/back/linux_keyboard.hpp"
#endif

#ifdef _WIN32
#include "input/internal/keyboard/back/windows_keyboard.hpp"
#endif 

#include "input/internal/keyboard/kbkeys.hpp"
#include "input/internal/keyboard/utils.hpp"
#include "input/internal/keyboard/ikeyboard.hpp"

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
