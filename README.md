# cppinput-lib

**cppinput-lib** is a high-level, cross-platform library for capturing operating system inputs.

the central part which is the capture of inputs and is completely header only, because it only needs the calls from the respective operating system.

the exposed classes of cpp input-lib are virtual classes (starting with 'I') that inherit from another class that has common denominators.
an example with the IMouse and IKeyboard classes:

```
           Base::IButton          
           //          \\          
          //            \\         
         //              \\        
        //                \\       
Keyboard::IKeyboard  Mouse::IMouse 
│                    │             
│                    │             
▼                    ▼             
Concrete Class       COncrete Class

```

this ensures that any input system that contains buttons can have uniqueness in its methods.

## Base::IButton

the `Base` namespace is responsible for exposing common denominators internally in the application.

the `IButton` interface exposes all the methods that any device containing a button should have. The signatures are as follows:

`virtual void Run = 0;`

responsible for initializing the internal structures and descriptors of the device.

`virtual bool IsPressed() = 0;`

checks the press activity of any button on the device and returns `true` if there was.

`virtual bool IsReleased() = 0;`

checks if the activity has stopped on the device, returning `true` if it has stopped.

`virtual void Stop = 0;`

responsible for closing descriptors and resetting internal structures of the implementation. (it only resets, it does not delete)

and any interface that implements IButton contains these methods.
