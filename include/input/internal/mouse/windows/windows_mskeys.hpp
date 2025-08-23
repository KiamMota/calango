#ifdef _WIN32

#ifndef _WINDOWSMSKEYS_HPP_
#define _WINDOWSMSKEYS_HPP_

#include "input/internal/mouse/mskeys.hpp"

namespace Mouse {
enum MS_BUTTONS : int {
  MSB_LEFT = 0x01,
  MSB_RIGHT = 0x02,
  MSB_MIDDLE = 0x04,
  MSB_X1 = 0x05,
  MSB_X2 = 0x06,

  // Additional Buttons (may not be supported on all mice)
  MSB_BACK = 0x08,   // Typically the "Back" button on some mice
  MSB_FORWARD = 0x09 // Typically the "Forward" button on some mice
};
} // namespace Mouse
#endif

#endif // _WIN32