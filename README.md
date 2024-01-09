# Connect4_C-
A training for my C++ exams to come ;)

## Install SDL :
Go to Project -> package NuGet -> search for sdl2.nuget

## Install SFML :
Go to Debug -> "name of your project" Debug Properties

Debugging -> Environment -> type : `PATH=%PATH%;$(ProjectDir)..\SFML-2.5.1\bin`

C/C++ -> General -> Additional Include Directories -> <Edit... > -> type : `$(ProjectDir)..\SFML-2.5.1\include` 
and then clic on OK

Linker -> input -> Additional Dependencies -> <Edit... > -> type : 
`sfml-graphics-d.lib
sfml-window-d.lib
sfml-audio-d.lib
sfml-system-d.lib` 
and then clic on OK

Finally you can apply changes and quit this window

All you have to do now is `#include <SDL.h>` and you are ready to go !!!
