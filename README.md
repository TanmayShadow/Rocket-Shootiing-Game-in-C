This project is a Rocket Shooting Game written in C language. Here's a brief overview of the project and how it works:

### Overview
- **Objective:** The game involves a rocket that the player controls to shoot at falling targets. The aim is to score points by hitting the targets and progress through levels by achieving a minimum score.

### How It Works
1. **Game Initialization:**
   - The game initializes various graphical settings using the Turbo C graphics library (`graphics.h`).
   - Variables are set to control the positions and movement of the rocket and targets.
   
2. **Start Screen:**
   - The `start()` function displays the start screen with options to start the game, get help, or exit.
   
3. **Help Screen:**
   - The `ghelp()` function displays instructions on how to play the game, including controls and objectives.

4. **Loading Screen:**
   - The `loading()` function shows a loading message before the game starts.

5. **Rocket Drawing:**
   - The `rocket()` function is responsible for drawing the rocket on the screen using graphical functions.

6. **Target Drawing:**
   - The `target()` and `target2()` functions draw different types of targets that the player needs to shoot.

7. **Game Loop:**
   - The `main()` function contains the main game loop where the game logic is executed.
   - The player can move the rocket left or right using arrow keys and shoot using the 'f' key.
   - Targets fall from the top, and the player must shoot them before they reach the bottom.
   - If the player hits a target, they score points based on the accuracy of the hit.
   - The game checks if the player has enough points to progress to the next level or if they have lost the game.
   - The loop continues until the player exits or the game ends.

### Controls
- **Move Left:** Left arrow key
- **Move Right:** Right arrow key
- **Shoot:** F key
- **Start Game:** S key
- **Help:** H key
- **Exit Game:** E key

This project uses the Turbo C graphics library, which means it is designed to be run in a DOS environment or an emulator that supports Turbo C.
