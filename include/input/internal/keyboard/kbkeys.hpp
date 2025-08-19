#ifndef _KBKEYS_HPP_
#define _KBKEYS_HPP_

#ifdef __linux__
#include "input/internal/keyboard/back/linux_kbkeys.hpp"
#endif
#ifdef _WIN32
#include "input/internal/keyboard/back/windows_kbkeys.hpp"
#endif

namespace Keyboard
{
    enum KB_KEYS : int;
}

#endif //_KBKEYS
