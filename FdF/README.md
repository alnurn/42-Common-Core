This project has been created as part of the 42 curriculum by <anurmach>.

## Description

FDF is a 3D wireframe renderer written in C using the MiniLibX graphics library.
The goal of the project is to visualize a 3D landscape from a given height map file (.fdf) by rendering it as a wireframe model using various projection techniques.

The program reads a map file containing integer values representing elevations and displays a graphical representation of the terrain in a window.
It implements fundamental concepts of computer graphics such as:

- Coordinate transformations
- Rotation matrices (X, Y, Z axes)
- Scaling
- Translation
- Isometric, perspective and orthographic projection
- Event-driven programming
- Window and image buffer management

This project focuses on low-level graphics handling, mathematical transformations, and memory management.

## Instructions

To compile the project, run:
`make`

To remove object files:
`make clean`

To remove all generated files, including the executable:
`make fclean`

Recompile everything:
`make re`


Execution

Run the program with a valid .fdf map file:
`./fdf maps/test_maps/pyramide.fdf`


Controls

Exit program
`ESC` or `Clicking on the cross on the window’s frame`

Rotate model
`ESC` or `Right mouse button + drag`

Zoom
`Mouse wheel`

Move model
`Middle mouse drag`


Projection switch keys:

`I` - Isometric projection

`P` - Perspective projection

`O` - Orthographic projection

`1` - Top view

`2` - Front view

`2` - Right side view

## Resources

Minilibx:

- Minilibx manual (minilibx-linux / man)
- https://harm-smits.github.io/42docs/libs/minilibx

Bresenham's line algorithm:

- https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
- https://www.youtube.com/watch?v=CceepU1vIKo&t=669s
- https://www.youtube.com/watch?v=wJki7vbaVuc

Project Architecture Overview

- https://medium.com/@amehri_tarik/fdf-42-a-detailed-walkthrough-7184cca317fc