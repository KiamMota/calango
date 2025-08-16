#ifndef _IKEYBOARD_HH_
#define _IKEYBOARD_HH_

#include "input/internal/base.hpp"
#include "input/internal/keyboard/kbkeys.hpp"

#include "input/internal/pch.hpp"

namespace Keyboard {

class IKeyboard : public Base::IButton {
public:
  virtual bool IsKeyPressed(Keyboard::KB_KEYS kb) = 0;
  virtual int GetCode() = 0;
};

} // namespace Keyboard

#endif
