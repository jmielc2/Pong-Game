# PONG GAME - Developer Log

## 9/6/2022 - Jacob Mielczarek
<p>
Finished implementing scene switching. Have it roughly working but may need to incorporate changes in the future.
Switched the Factory class to a Manager class that houses the scenes. No need for a factory that only needs
to create something once.
<br>
Now I need to start figuring out how to manage rendering. For example, lets say I want to render text. It would
be a waste to read and initialize a sf::Text object for each page, so I feel it'd be better to have the App control general assets such as font. I need to think of a way to communicate between the two that doesn't complicate things.
</p>

## 9/2/2022 - Jacob Mielczarek
<p>
Started implementing the scene switching. Created a Factory class that abstracts the creation of the different scenes. At the moment, I've only added three scenes: Main Menu, Game Scene, and End Scene (once the game is over). All three inherit from the abstract class Scene.
<br>
At the moment, the way I see this working is that a call can be made to the App class to the switch the scene. All the pages are created and loaded when the application initializes, so all that's left to do is to run the close and open functions for the scenes as they switch, then switch the Scene pointer to the new scene. That way, we can avoid having to worry about switch statements choosing which scene to update, close, render, reset, etc. I believe the design patterns being used here are Factory and Strategy.
<br>
Oh, and I also found a font that feels similar to the original Pong.
</p>

## 8/29/2022 - Jacob Mielczarek
<p>
Created and implemented the app icon and tested the current framerate.
</p>

## 8/26/2022 - Jacob Mielczarek
<p>
Began UML design of App class. Goal is to allow for easy scene management and updating with minimal use of switch and if/else blocks.
<br>
The App class will follow the Singleton Design pattern and incorporate the use of the Strategy Design pattern to allow for changes in App behavior during run time.
</p>

## 8/25/2022 - Jacob Mielczarek
<p>
Started project. Set up git repo, folder structure, and initial CMake build system. Implemented the SFML library through gitmodules.
<br>
Next will begin designing the Application class and page management. Will try implementing various Design Patterns to achieve modular and reliable program
<br>
At the moment, my plan is for the game to allow for, at least, one player vs an AI. Depending on the amount of time, I may expand to local 2 player and maybe even remote 2 player. I still don't know how ambitious I want to get with this, so it will be something that I will decide as I go along and whether this still interests me once I reach each milestone in development.
</p>