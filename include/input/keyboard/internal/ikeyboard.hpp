#ifndef _IKEYBOARD_HH_
#define _IKEYBOARD_HH_

#include "input/base.hpp"
#include "input/keyboard/kbkeys.hpp"

#include "input/pch.hpp"

namespace Keyboard {

class IKeyboard : public Base::IButton {
public:
  virtual bool IsKeyPressed(Keyboard::KB_KEYS kb) = 0;
  virtual int GetCode() = 0;
};

} // namespace Keyboard

#endif
