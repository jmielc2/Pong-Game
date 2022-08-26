# PONG GAME - Developer Log

## 8/25/2022 - Jacob Mielczarek
<p>
Started project. Set up git repo, folder structure, and initial CMake build system. Implemented the SFML library through gitmodules.
<br>
Next will begin designing the Application class and page management. Will try implementing various Design Patterns to achieve modular and reliable program
<br>
At the moment, my plan is for the game to allow for, at least, one player vs an AI. Depending on the amount of time, I may expand to local 2 player and maybe even remote 2 player. I still don't know how ambitious I want to get with this, so it will be something that I will decide as I go along and whether this still interests me once I reach each milestone in development.
</p>

## 8/26/2022 - Jacob Mielczarek
<p>
Began UML design of App class. Goal is to allow for easy scene management and updating with minimal use of switch and if/else blocks.
<br>
The App class will follow the Singleton Design pattern and incorporate the use of the Strategy Design pattern to allow for changes in App behavior during run time.
</p>