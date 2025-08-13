# cppinput-lib

cppinput-lib is a minimalistic, header-only C++ library designed for low-level, cross-platform a input event capture. It provides a clean, unified interface to abstract away the platform-specific complexities of reading keyboard state from system APIs and device descriptors.

---

Features
**Header-Only**: Simplifies integration into projects, requiring no separate compilation or linking steps. Just include the header.

**Cross-Platform**: Provides native support for both Linux and Windows operating systems.

## **Operating Modes**: Offers two distinct modes for flexible event capture, managed via bitwise flags:

Global Mode: Reads events directly from low-level input devices, ideal for system-wide shortcuts or applications without a graphical context.

Window-Specific Mode: Integrates with the native windowing system's event loop (e.g., Wayland, X11, or Windows message loop) to capture events only when the application's window has focus.

Installation
As cppinput-lib is a header-only library, installation is straightforward:

Clone or download the repository.

Add the cppinput directory to your project's include paths.

Include keyboard.hh in your source files to access the library's functionality.

**Quick Usage Example**

The library's core is the Keyboard::IKeyboard interface. An instance can be initialized via a static factory method, and its behavior is configured using the Opt() method. The following example demonstrates how to set up a global key listener.

``` cpp
#include "cppinput/keyboard/keyboard.hh"
#include <iostream>

int main()
{
    // Obtain a handle to the IKeyboard interface.
    // The GetKeyboard::Init() factory method returns a concrete
    // implementation based on the host operating system.
    Keyboard::IKeyboard* k = Keyboard::GetKeyboard();

    // Configure the library to read keyboard events globally.
    // For window-specific input, use Keyboard::Options::WINDOW_READER.
    k->Opt(Keyboard::Options::GLOBAL_READER);

    k->IsPressed([](){std::cout << "Hello, world!" << std::endl;})

    while (true)
    {
        // Polling the keyboard state.
        if (k->IsPressed())
        {
            std::cout << "A key is currently being pressed!" << std::endl;
        }
    }


    // Important: Release the memory for the keyboard object.
    delete k;
    return 0;
}
```
API Reference
The IKeyboard interface provides the following public methods:

void Opt(Keyboard::Options opts):
Sets the operational mode of the library using bitwise flags.

Keyboard::Options::GLOBAL_READER: Activates low-level, system-wide keyboard event capture.

Keyboard::Options::WINDOW_READER: Activates window-focused event capture via the native windowing system API.

bool IsPressed():
Returns true if any key is currently in a pressed state.

bool IsReleased():
Returns true if any key has been released in the last polling cycle.

bool IsRepeated():
Returns true if a key is currently in a repeating state due to auto-repeat.

bool IsKeyPressed(KB_KEYS kb):
Checks if a specific key, identified by the KB_KEYS enum, is in a pressed state.

Contributing
Feel free to open issues or submit pull requests to improve cppinput-lib.
