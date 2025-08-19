#ifndef _BASE_HPP_
#define _BASE_HPP_

#include <functional>

namespace Base {
class IButton {
public:
  virtual bool Listen() = 0;
  virtual void Stop() = 0;
  virtual bool IsPressed() = 0;
  virtual void IsPressed(std::function<void()> callback) = 0;
  virtual bool IsReleased() = 0;
  virtual void IsReleased(std::function<void()> callback) = 0;
};
} // namespace Base

#endif
