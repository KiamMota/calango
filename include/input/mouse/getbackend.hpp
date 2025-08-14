#ifndef _MOUSEBACKEND_HPP_
#define _MOUSEBACKEND_HPP_

#ifdef __linux__
#include "input/mouse/backend/linux_mouse.hpp"

#endif

#include "input/mouse/imouse.hpp"
namespace Mouse {
IMouse *GetBackend() {
#ifdef __linux__
  Backend::LinuxMouse *lnx_mouse_instance = new Backend::LinuxMouse();
  return lnx_mouse_instance;
#endif
}

} // namespace Mouse

#endif
