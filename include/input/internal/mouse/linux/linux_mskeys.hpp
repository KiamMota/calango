
#ifdef __linux__

#ifndef _MSKEYS_HPP_
#define _MSKEYS_HPP_

namespace Mouse {
enum MS_BUTTONS : int {
  MMS_LEFT = 0x110,    /* Primary button */
  MMS_RIGHT = 0x111,   /* Secondary button */
  MMS_MIDDLE = 0x112,  /* Middle button */
  MMS_SIDE = 0x113,    /* Side button (often back) */
  MMS_EXTRA = 0x114,   /* Extra button (often forward) */
  MMS_FORWARD = 0x115, /* Forward button */
  MMS_BACK = 0x116,    /* Back button */
  MMS_TASK = 0x117,    /* Task button */
};
} // namespace Mouse

#endif

#endif
