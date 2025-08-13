#ifndef __IKEYBOARD_HH_
#define __IKEYBOARD_HH_

#include "cppinput/keyboard/kb_keys.hh"
#include "cppinput/keyboard/options.hh"
#include <iostream>
#include <string>
#include <vector>

namespace Backend {

class IKeyboard {
public:
  virtual void Options(Keyboard::Options opt) = 0;
  virtual bool IsPressed() = 0;
  virtual bool IsReleased() = 0;
  virtual bool IsRepeated() = 0;
  virtual bool IsKeyPressed(Keyboard::KB_KEYS kb) = 0;
  virtual int GetCode() = 0;
};
} // namespace Backend
#endif
