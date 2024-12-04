
SDL Circle Animation Program

This program is a simple yet dynamic demonstration of using SDL2 for creating an animated application where multiple circles move across the screen. It showcases how to handle basic user inputs, animate objects, manage text rendering, and manipulate colors in an SDL2 environment.

 Features

- **Multiple Animated Circles**: The program creates and animates multiple circles moving horizontally across the screen.
- **User Interaction**: Press the **Space Bar** to reset the animation, and **A** to increase the speed of the animation.
- **Speed Control**: The speed of the circles' movement increases as they complete iterations, simulating a more complex and engaging animation.
- **Color Change**: The color of the circles changes after a certain speed threshold is reached, adding variety and visual interest to the animation.
- **Text Rendering**: The program uses SDL_ttf to render text on the screen to display the current animation state and speed.

### How It Works

- **Initialization**: The program initializes the SDL2 library, creates a window, and sets up a renderer for drawing.
- **Event Handling**: It continuously polls for user events to handle input like quitting the application or changing the animation speed.
- **Animation Logic**: Circles are moved based on a fixed speed value. Once a circle reaches the edge of the window, it reappears on the opposite side, creating a looping effect.
- **Speed and Iteration Management**: The animation speed can be dynamically increased by pressing **A**, and when a circle completes a full pass across the window, the speed is incremented, and iteration counts are tracked.
- **Color Change Logic**: Once the speed of the animation surpasses a set threshold, the color of the circles changes to indicate a new animation stage.

### Technologies Used

- **Programming Language**: C++
- **Graphics Library**: SDL2 (Simple DirectMedia Layer)
- **Text Rendering**: SDL_ttf
- **Additional Libraries**: SDL2_gfx for advanced drawing operations
- **Audio Library**: SDL_mixer (if needed in future extensions)


### Contributing

Feel free to fork this repository and contribute by submitting issues or pull requests. Contributions are always welcome to enhance the functionality or improve the program further!

### License

This project is licensed under the [MIT License](LICENSE).


