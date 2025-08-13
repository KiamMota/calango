#ifndef _IKEYBOARD_HH_
#define _IKEYBOARD_HH_

#include "input/keyboard/kb_keys.hh"
namespace Keyboard {

class IKeyboard {
public:
  virtual void Stop() = 0;
  virtual bool IsPressed() = 0;
  virtual bool IsReleased() = 0;
  virtual bool IsRepeated() = 0;
  virtual bool IsKeyPressed(Keyboard::KB_KEYS kb) = 0;
  virtual int GetCode() = 0;
};
} // namespace Keyboard
#endif
