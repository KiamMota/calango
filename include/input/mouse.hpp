#ifndef _MOUSEBACKEND_HPP_
#define _MOUSEBACKEND_HPP_

#include "input/internal/mouse/imouse.hpp"
#ifdef __linux__
#include "input/internal/mouse/linux_mouse.hpp"
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
