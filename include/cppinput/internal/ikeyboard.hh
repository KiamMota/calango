#ifndef __IKEYBOARD_HH_
#define __IKEYBOARD_HH_

#include "cppinput/keyboard/kb_keys.hh"
#include <iostream>
#include <string>
#include <vector>

class IKeyboard {
public:
  virtual bool IsPressed() = 0;
  virtual bool IsReleased() = 0;
  virtual bool IsKeyPressed(KB_KEYS kb) = 0;
  virtual int GetCode() = 0;
};

#endif
