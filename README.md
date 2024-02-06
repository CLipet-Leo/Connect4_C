# Connect4_C-
A training for my C++ exams to come ;)

## Install SDL :
Go to Project -> package NuGet -> search for sdl2.nuget

All you have to do now is `#include <SDL.h>` and you are ready to go !!!

## Install SFML :
Download the "Visual C++ 15 (2017) - 64-bit" directory in : https://www.sfml-dev.org/download/sfml/2.6.1/index-fr.php
and move it to your project directory.

Then in Visual Studio :

Go to Debug -> "name of your project" Debug Properties

Debugging -> Environment -> type : `PATH=%PATH%;$(ProjectDir)..\SFML-2.6.1\bin`

C/C++ -> General -> Additional Include Directories -> <Edit... > -> type : `$(ProjectDir)..\SFML-2.6.1\include` 
and then clic on OK

Linker -> input -> Additional Library Directories -> <Edit... > -> type : `$(ProjectDir)..\SFML-2.6.1\include`
and then clic on OK

Linker -> input -> Additional Dependencies -> <Edit... > -> type : 
```
sfml-graphics-d.lib
sfml-window-d.lib
sfml-audio-d.lib
sfml-system-d.lib
``` 
and then clic on OK

Finally you can apply changes and WAIT for the loading, then quit this window.

## Code sample for test SFML :
```
#include <SFML/Graphics.hpp>

int main( int argc, char** argv )
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow( sf::VideoMode( 640, 480 ), "SFML" );
   
    //Création d'un cercle de radius 100
    sf::CircleShape oCircle( 100.f );
    //A la position 0, 0
    oCircle.setPosition( 0.f, 0.f );
    //Et de couleur verte
    oCircle.setFillColor( sf::Color::Green );


    //Création d'un rectangle de taille 50, 50
    sf::RectangleShape oRectangle( sf::Vector2f( 50.f, 50.f ) );
    //A la position 100, 100
    oCircle.setPosition( 100.f, 100.f );
    //Et de couleur rouge
    oRectangle.setFillColor( sf::Color::Red );

    //GameLoop
    while( oWindow.isOpen() )
    {
        //EVENT
        sf::Event oEvent;
        while( oWindow.pollEvent( oEvent ) )
        {
            if( oEvent.type == sf::Event::Closed )
                oWindow.close();
        }

        //UPDATE

        //DRAW
        oWindow.clear();

        oWindow.draw( oCircle );
        oWindow.draw( oRectangle );
       
        oWindow.display();
    }

    return 0;
}
```
