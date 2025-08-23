#ifdef _WIN32

#ifndef _WIN_KBKEYS_HPP_
#define _WIN_KBKEYS_HPP_

#include "input/internal/keyboard/kbkeys.hpp"

namespace Keyboard {

enum KB_KEYS : int {
  KBB_ESC = 0x1B,
  KBB_CAPSLOCK = 0x14,
  KBB_LEFTALT = 0xA4,
  KBB_RIGHTALT = 0xA5,
  KBB_LEFTSHIFT = 0xA0,
  KBB_RIGHTSHIFT = 0xA1,
  KKB_LEFTCTRL = 0xA2,
  KKB_RIGHTCTRL = 0xA3,
  KBB_SPACE = 0x20,
  KBB_ENTER = 0x0D,
  KBB_KPENTER = 0x0D, /* same key in windows */
  KBB_BACKSPACE = 0x08,
  KBB_TAB = 0x09,
  KBB_1 = 0x31,
  KKB_2 = 0x32,
  KKB_3 = 0x33,
  KKB_4 = 0x34,
  KKB_5 = 0x35,
  KKB_6 = 0x36,
  KKB_7 = 0x37,
  KKB_8 = 0x38,
  KKB_9 = 0x39,
  KKB_0 = 0x30,

  /* keys definition in querty pattern */

  KKB_Q = 0x51,
  KKB_W = 0x57,
  KKB_E = 0x45,
  KKB_R = 0x52,
  KKB_T = 0x54,
  KKB_Y = 0x59,
  KKB_U = 0x55,
  KKB_I = 0x49,
  KKB_O = 0x4F,
  KKB_P = 0x50,
  KKB_A = 0x41,
  KKB_S = 0x53,
  KKB_D = 0x44,
  KKB_F = 0x46,
  KKB_G = 0x47,
  KKB_H = 0x48,
  KKB_J = 0x4A,
  KKB_K = 0x4B,
  KKB_L = 0x4C,
  KKB_Z = 0x5A,
  KKB_X = 0x58,
  KKB_C = 0x43,
  KKB_V = 0x56,
  KKB_B = 0x42,
  KKB_N = 0x4E,
  KKB_M = 0x4D,
  KKB_F1 = 0x70,
  KKB_F2 = 0x71,
  KKB_F3 = 0x72,
  KKB_F4 = 0x73,
  KKB_F5 = 0x74,
  KKB_F6 = 0x75,
  KKB_F7 = 0x76,
  KKB_F8 = 0x77,
  KKB_F9 = 0x78,
  KKB_F10 = 0x79,
  KKB_F11 = 0x7A,
  KKB_F12 = 0x7B,

  /* arrows */

  KKB_UP = 0x26,
  KKB_DOWN = 0x28,
  KKB_LEFT = 0x25,
  KKB_RIGHT = 0x27,

  // Navigation Keys

  KKB_HOME = 0x24,
  KKB_END = 0x23,
  KKB_PAGEUP = 0x21,
  KKB_PAGEDOWN = 0x22,
  KKB_INSERT = 0x2D,
  KKB_DELETE = 0x2E,

  // System Keys

  KKB_MACRO = 0, /* does not exist */
  KKB_MUTE = 0xAD,
  KKB_VOLUMEDOWN = 0xAE,
  KKB_VOLUMEUP = 0xAF,
  KKB_POWER = 0, 
  KKB_KPEQUAL = 0, // não existe
  KKB_KPPLUSMINUS = 0, // não existe
  KKB_PAUSE = 0x13,
  KKB_SCALE = 0, // não existe
  KKB_KPCOMMA = 0, // não existe

  // International Keys
  KKB_HANGEUL = 0x15,
  KKB_HANGUEL = 0x15, // Alias for KKB_HANGEUL
  KKB_HANJA = 0x19,
  KKB_YEN = 0, // só em layouts específicos (pode ser OEM)
  KKB_LEFTMETA = 0x5B,
  KKB_RIGHTMETA = 0x5C,
  KKB_COMPOSE = 0, // não existe

  // CD/Media Control
  KKB_CLOSECD = 0, 
  KKB_EJECTCD = 0, 
  KKB_EJECTCLOSECD = 0,
  KKB_NEXTSONG = 0xB0,
  KKB_PLAYPAUSE = 0xB3,
  KKB_PREVIOUSSONG = 0xB1,
  KKB_STOPCD = 0xB2,
  KKB_RECORD = 0, 
  KKB_REWIND = 0,
  KKB_PHONE = 0, 

  // Additional System Keys
  KKB_ISO = 0,
  KKB_CONFIG = 0,
  KKB_HOMEPAGE = 0xAC,
  KKB_REFRESH = 0xA8,
  KKB_EXIT = 0,
  KKB_MOVE = 0,
  KKB_EDIT = 0,
  KKB_SCROLLUP = 0,
  KKB_SCROLLDOWN = 0,
  KKB_KPLEFTPAREN = 0,
  KKB_KPRIGHTPAREN = 0,
  KKB_NEW = 0,
  KKB_REDO = 0,

  // Extended Function Keys
  KKB_F13 = 0x7C,
  KKB_F14 = 0x7D,
  KKB_F15 = 0x7E,
  KKB_F16 = 0x7F,
  KKB_F17 = 0x80,
  KKB_F18 = 0x81,
  KKB_F19 = 0x82,
  KKB_F20 = 0x83,
  KKB_F21 = 0x84,
  KKB_F22 = 0x85,
  KKB_F23 = 0x86,
  KKB_F24 = 0x87
};

}
#endif // _WIN_KBKEYS_HPP_
#endif // _WIN32