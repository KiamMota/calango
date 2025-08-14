#ifndef _IMOUSE_HPP_
#define _IMOUSE_HPP_

namespace Mouse {

class IMouse {
public:
  virtual void Stop() = 0;
  virtual bool IsMoving() = 0;
  virtual bool IsStopped() = 0;
  virtual bool IsClicked() = 0;
  virtual bool IsReleased() = 0;
  // virtual bool IsPressed() = 0;
  // virtual bool IsReleased() = 0;
};
} // namespace Mouse
#endif
