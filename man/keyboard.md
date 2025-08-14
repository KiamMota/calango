# Keyboard (0.01)

The `Keyboard` namespace is the central location for all keyboard-related properties and functions. This system leverages the `cppinput-lib`, which utilizes various backends to ensure a consistent and reliable keyboard input experience across different operating systems.

### The `IKeyboard` Interface

To begin working with keyboard input, you must instantiate the `IKeyboard` interface, located at `Keyboard::IKeyboard`. This is an abstract class that standardizes keyboard patterns across all supported platforms, providing the following core methods:

- **`void Stop()`** This method is used to stop the keyboard input polling process.

- **`bool IsPressed()`** Checks if any key on the keyboard is currently in a pressed state.

- **`bool IsReleased()`** Checks if any key on the keyboard has just been released.

- **`bool IsRepeated()`** Checks if keys are being repeated on the keyboard, typically when a key is held down.

- **`bool IsKeyPressed(KB_KEY kb)`** Checks if a specific key, identified by the `KB_KEY` argument, is currently being pressed.

### Instantiating the `IKeyboard` Interface

To instantiate your `IKeyboard *kb` pointer, you must use the `Keyboard::GetBackend()` function.

```cpp
IKeyboard* Keyboard::GetBackend();
```

 This function automatically provides a concrete implementation of the abstract class based on the current operating system, allowing for seamless cross-platform functionality.

Example:

```cpp
#include "input/keyboard/keyboard.hpp"

int main()
{
    
    Keyboard::IKeyboard* myKeyboard = Keyboard::GetBackend();
    while(1)
    {
        if(myKeyboard->IsPressed())
        {
            std::cout << "IsPressed!" << std::endl;
        }
    }

}
```



### Instantiating with typedefs

Another, more **idiomatic** way to do this is by using typedefs `KeyboardObject` provided in the namespace. It offers a concise name for the backend implementation based on your operating system. 

Example:

```cpp
#include "input/keyboard/keyboard.hpp"

int main(){
    // Instantiating with KeyboardObject handle typedef.
    Keyboard::KeyboardObject kb; 
    
    while(1)
    {
        if(kb.IsPressed())
        {
        std::cout << "Pressing!" << std::endl;
        }
    }
// ... a implementacao para o objeto
}
```

However, this approach is not advisable, except for a small scope, as it does not directly handle pointers.


















