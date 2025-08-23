#ifndef _MOUSEBACKEND_HPP_
#define _MOUSEBACKEND_HPP_

#include "input/internal/mouse/imouse.hpp"
#ifdef __linux__
#include "input/internal/mouse/linux/linux_mouse.hpp"
#endif
#ifdef _WIN32
#include "input/internal/mouse/windows/windows_mouse.hpp"
#endif 

namespace Mouse {
static IMouse *GetBackend() {
#ifdef __linux__
  Backend::LinuxMouse *lnx_mouse_instance = new Backend::LinuxMouse();
  return lnx_mouse_instance;
#endif
#ifdef _WIN32
  Backend::WindowsMouse *win_mouse_instance = new Backend::WindowsMouse();
  return win_mouse_instance;
}

} // namespace Mouse

#endif
#endif 