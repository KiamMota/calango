#ifndef _IMOUSE_HPP_
#define _IMOUSE_HPP_

#include "input/internal/mouse/mskeys.hpp"

#include "input/internal/base.hpp"


namespace Mouse {

class IMouse : public Base::IButton {
public:
  virtual bool IsMoving() = 0;
  virtual bool IsButtonPressed(Mouse::MS_BUTTONS ms) = 0;
  virtual bool IsButtonReleased(Mouse::MS_BUTTONS ms) = 0;
  virtual bool IsScrollingVertical() = 0;
  virtual short GetScrollAmount() = 0;
};
} // namespace Mouse
#endif