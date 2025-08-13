#ifndef __IKEYBOARD_HH_
#define __IKEYBOARD_HH_

#include "input/keyboard/kb_keys.hh"
#include "input/keyboard/options.hh"
#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace Keyboard {

class IKeyboard {
public:
  virtual void Options(Keyboard::Options opt) = 0;
  virtual bool IsPressed() = 0;
  virtual void IsPressed(std::function<void()> callback);
  virtual bool IsReleased() = 0;
  virtual void IsReleased(std::function<void()> callback) = 0;
  virtual bool IsRepeated() = 0;
  virtual bool IsRepeated(std::function<void()> callback) = 0;
  virtual bool IsKeyPressed(Keyboard::KB_KEYS kb) = 0;
  virtual int GetCode() = 0;
};
} // namespace Keyboard
#endif
