#ifndef _BASE_HPP_
#define _BASE_HPP_

namespace Base {
class IButton {
public:
  virtual void Run() = 0;
  virtual void Stop() = 0;
  virtual bool IsPressed() = 0;
  virtual bool IsReleased() = 0;
};
} // namespace Base

#endif
