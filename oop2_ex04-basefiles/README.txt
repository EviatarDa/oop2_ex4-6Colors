EX4: "6colors"

Names:

Eviatar Davidyan  207259755
Shir Yadid  208327957

The goal of the game is to accumulate as much space as possible.
At the beginning of the game, the hexagons on the board are randomly colored, then the players automatically get the shape
in one of the corners: the human player starts in the lower left corner (that is, he controls the shape in this corner),
And the computer starts from the top right corner.

Each turn, the player chooses some color that borders on the area already belonging to him, thereby increasing his area to the tiles
The neighbors have this color. At each stage, it is allowed to choose one of the available colors, i.e. all colors except the two colors
which were chosen in the last two steps by the players (and are currently "occupied" by them). The winner is the first player
which controls more than 50% of the board surface.

Departments:
Graph class - keeps neighbors of some form - template class.
The board class is responsible for holding the relevant hexes and buttons
Game department - responsible for the window and the unification of all departments
Hexagon class - which produces its shape and color
singletone - a class that keeps all the texts
Algorithms department:
from which 3 different classes of algorithms inherit:
Random, easy and hard



Noteworthy algorithms -
Using the bfs algorithm to save neighbors

Known bugs -

Other notes -
