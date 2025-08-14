#ifndef _IMOUSE_HPP_
#define _IMOUSE_HPP_

#include "input/base.hpp"
namespace Mouse {

class IMouse : Base::IButton {
public:
  virtual bool IsMoving() = 0;
  virtual bool IsStopped() = 0;
};
} // namespace Mouse
#endif
