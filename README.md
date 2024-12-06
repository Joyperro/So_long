# So_long
My code for the so_long project from 42 school.

In this project, we have to create a small videogame where you have to get all the collectibles (the golden key textures and the C letter in the .ber maps) to be able to exit the game through the door (glass door texture and E in the maps).
In the base project, we just load the textures using the mlx library from 42 and then we code the collectibles, the player and the exit (there can only be one player and one exit). We also need to check the maps to see if they fit the criteria and have a valid path to the exit (in my case, as the exit is coded so it immediately spawns, every path where the exit is between a collectible and the player wiith no alternative paths is considered invalid). I´m using the flood fill algorithm to check the paths.

If you want to try it yourself, just download the git and then do make to use the base project and then ./so_long ./maps/map1.ber or make bonus and ./so_long_bonus ./bonus/maps/map1.ber
