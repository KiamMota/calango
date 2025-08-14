#ifndef _MOUSEBACKEND_HPP_
#define _MOUSEBACKEND_HPP_

#ifdef __linux__
#include "input/mouse/internal/linux_mouse.hpp"

#endif

namespace Mouse {
IMouse *GetBackend() {
#ifdef __linux__
  Backend::LinuxMouse *lnx_mouse_instance = new Backend::LinuxMouse();
  return lnx_mouse_instance;
#endif
}

} // namespace Mouse

#endif
