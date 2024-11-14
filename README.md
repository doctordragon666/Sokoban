# Sokoban

It's a game of pushing boxes, a program developed based on Visual Studio and `EasyX`. All the code is process-oriented.

## Running

Download the project files, then click on the.sln solution file and click "Run".

Here are several running screenshots:

1. Initialization interface

![Start interface](start.png)

2. Running process

You can move by pressing WASD and quit by pressing Q.

![Running interface](run.png)

3. Ending animation

![End interface](end.png)

After the game ends, the program will close automatically.

## Principle Explanation

### Flowchart

```mermaid
flowchart TB
	subgraph graph_initmap
	a("Loading images") --> b("Initializing the window size") --> c("Setting the background image") --> d("Rendering the map blocks") --> e("Setting the counter board")
	end
	subgraph graph_gamecontrol
	m{Getting Keyboard Messages} -->|WASD| mt("Moving Task") -->|Continue to Get| m
	m ===>|Q| qtg("Quit the Game")
	end
	graph_initmap --- graph_gamecontrol --- ctm("Clearing the Map")
```

### Explanation of Key Algorithms

The key here is the algorithm for the moving task. A simple simulation is adopted. First, determine the direction, calculate the coordinates of the current task, and then update the textures of several points on the map according to the changes in the coordinates.

## License

This project has no license. 