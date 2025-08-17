#ifdef __linux__
#ifndef _LIN_KBKEYS_HPP_
#define _LIN_KBKEYS_HPP_

namespace Keyboard {

enum KB_KEYS : int {
  KBB_ESC = 1,
  KBB_CAPSLOCK = 58,
  KBB_LEFTALT = 56,
  KBB_RIGHTALT = 100,
  KBB_LEFTSHIFT = 42,
  KBB_RIGHTSHIFT = 44,
  KBB_SPACE = 57,
  KBB_ENTER = 28,
  KBB_KPENTER = 96,
  KBB_BACKSPACE = 14,
  KBB_TAB = 15,
  KBB_1 = 2,
  KKB_2 = 3,
  KKB_3 = 4,
  KKB_4 = 5,
  KKB_5 = 6,
  KKB_6 = 7,
  KKB_7 = 8,
  KKB_8 = 9,
  KKB_9 = 10,
  KKB_0 = 11,

  /* keys definition in querty pattern */

  KKB_Q = 16,
  KKB_W = 17,
  KKB_E = 18,
  KKB_R = 19,
  KKB_T = 20,
  KKB_Y = 21,
  KKB_U = 22,
  KKB_I = 23,
  KKB_O = 24,
  KKB_P = 25,
  KKB_A = 30,
  KKB_S = 31,
  KKB_D = 32,
  KKB_F = 33,
  KKB_G = 34,
  KKB_H = 35,
  KKB_J = 36,
  KKB_K = 37,
  KKB_L = 38,
  KKB_Z = 44,
  KKB_X = 45,
  KKB_C = 46,
  KKB_V = 47,
  KKB_B = 48,
  KKB_N = 49,
  KKB_M = 50,
  KKB_F1 = 59,
  KKB_F2 = 60,
  KKB_F3 = 61,
  KKB_F4 = 62,
  KKB_F5 = 63,
  KKB_F6 = 64,
  KKB_F7 = 65,
  KKB_F8 = 66,
  KKB_F9 = 67,
  KKB_F10 = 68,
  KKB_F11 = 87,
  KKB_F12 = 88,

  /* arrows */

  KKB_UP = 103,
  KKB_DOWN = 108,
  KKB_LEFT = 105,
  KKB_RIGHT = 106,

  // Navigation Keys

  KKB_HOME = 102,
  KKB_END = 107,
  KKB_PAGEUP = 104,
  KKB_PAGEDOWN = 109,
  KKB_INSERT = 110,
  KKB_DELETE = 111,

  // System Keys

  KKB_MACRO = 112,
  KKB_MUTE = 113,
  KKB_VOLUMEDOWN = 114,
  KKB_VOLUMEUP = 115,
  KKB_POWER = 116,
  KKB_KPEQUAL = 117,
  KKB_KPPLUSMINUS = 118,
  KKB_PAUSE = 119,
  KKB_SCALE = 120,
  KKB_KPCOMMA = 121,

  // International Keys
  KKB_HANGEUL = 122,
  KKB_HANGUEL = 122, // Alias for KKB_HANGEUL
  KKB_HANJA = 123,
  KKB_YEN = 124,
  KKB_LEFTMETA = 125,
  KKB_RIGHTMETA = 126,
  KKB_COMPOSE = 127,

  // CD/Media Control
  KKB_CLOSECD = 160,
  KKB_EJECTCD = 161,
  KKB_EJECTCLOSECD = 162,
  KKB_NEXTSONG = 163,
  KKB_PLAYPAUSE = 164,
  KKB_PREVIOUSSONG = 165,
  KKB_STOPCD = 166,
  KKB_RECORD = 167,
  KKB_REWIND = 168,
  KKB_PHONE = 169,

  // Additional System Keys
  KKB_ISO = 170,
  KKB_CONFIG = 171,
  KKB_HOMEPAGE = 172,
  KKB_REFRESH = 173,
  KKB_EXIT = 174,
  KKB_MOVE = 175,
  KKB_EDIT = 176,
  KKB_SCROLLUP = 177,
  KKB_SCROLLDOWN = 178,
  KKB_KPLEFTPAREN = 179,
  KKB_KPRIGHTPAREN = 180,
  KKB_NEW = 181,
  KKB_REDO = 182,

  // Extended Function Keys
  KKB_F13 = 183,
  KKB_F14 = 184,
  KKB_F15 = 185,
  KKB_F16 = 186,
  KKB_F17 = 187,
  KKB_F18 = 188,
  KKB_F19 = 189,
  KKB_F20 = 190,
  KKB_F21 = 191,
  KKB_F22 = 192,
  KKB_F23 = 193,
  KKB_F24 = 194
};

}

#endif // _LIN_KBKEYS_HPP_
#endif // --__linux__
