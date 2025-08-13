#ifndef __IKEYBOARD_HH_
#define __IKEYBOARD_HH_

#include "cppinput/keyboard/kb_keys.hh"

class IKeyboard {
public:
  virtual bool IsPressed() = 0;
  virtual bool IsReleased() = 0;
  virtual bool IsKeyPressed(KB_KEYS kb) = 0;
};

#endif
