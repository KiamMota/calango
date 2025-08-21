#ifndef _IKEYBOARD_HH_
#define _IKEYBOARD_HH_

#include "input/internal/base.hpp"
#include "input/internal/keyboard/linux/linux_kbkeys.hpp"

namespace Keyboard {

class IKeyboard : public Base::IButton {
public:
  virtual bool IsKeyPressed(Keyboard::KB_KEYS kb) = 0;
  virtual bool IsKeyReleased(Keyboard::KB_KEYS kb) = 0;
  virtual KB_KEYS GetKey() = 0;
};

} // namespace Keyboard

#endif
