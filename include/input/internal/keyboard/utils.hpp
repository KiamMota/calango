#ifndef _KEYBOARD_UTILS_HPP_
#define _KEYBOARD_UTILS_HPP_

#include "input/internal/keyboard/ikeyboard.hpp"
namespace Keyboard {
static void Free(Keyboard::IKeyboard **kb) {
  if (!kb || !*kb)
    return;
  (*kb)->Stop();
  delete *kb;
  *kb = nullptr;
}

} // namespace Keyboard

#endif
