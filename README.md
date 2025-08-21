# Calango (calango-lib)

**Calango** is a cross-platform bloat-free library for capturing operating system inputs.

the central part which is the capture of inputs and is completely header only, because it only needs the calls from the respective operating system.

## Input Modes

Calango works in two different ways: **Global Mode** and **Local Mode**.  

---

## Global Mode

In this mode, the library hooks directly into the operating system and captures input events system-wide.  
It does not matter which application is in focus — all keyboard and mouse activity is detected.  

**Key points:**
- Input is captured from the entire system.  
- Works even if your application is not the active window.  
- Useful for hotkeys, automation, or monitoring tools.  
- Risky for games or apps because it may also react to inputs made in other programs.  

---

## Local Mode

In this mode, the library attaches itself to a specific application window.  
Only the inputs that belong to that window are captured, and anything typed or clicked outside is ignored.  

**Key points:**
- Input is captured only from the chosen window.  
- Events from other applications are ignored.  
- Safer for games or GUI applications.  
- Requires a valid window handle from the system or a windowing library.  

---

## Comparison

| Mode       | Scope of Capture            | Typical Use Case                 |
|------------|-----------------------------|----------------------------------|
| **Global** | Entire operating system     | Hotkeys, automation, monitoring  |
| **Local**  | Specific application window | Games, desktop applications      |

to work with handle system, you should check the `Handle::` namespace (comming soon).

the exposed classes of cpp input-lib are virtual classes (starting with 'I') that inherit from another class that has common denominators.
an example with the IMouse and IKeyboard classes:

the library never exposes concrete classes, only interfaces (abstract classes) and you can use, 
through the backend of your system, the method `GetBackend(...);`
## Base::IButton

the `Base` namespace is responsible for exposing common denominators internally in the application.

the `IButton` interface exposes all the methods that any device containing a button should have. The signatures are as follows:

`virtual void Listen() = 0;`

responsible for polling the internal structures and descriptors of the device.

`virtual bool IsPressed() = 0;`

`virtual bool IsReleased() = 0;`

`virtual void IsPressed(std::function<void()>) = 0;`

`virtual void IsReleased(std::function<void()>) = 0;`

`virtual void Stop() = 0;`

The lib, in turn, can capture callbacks in addition to standard polling, with the Listen() and Stop() methods, which allow it to repeatedly listen to the system, and stop to stop listening.

To delete the pointer to the specific class, simply use the Button::Free(Base::IButton **) function.
