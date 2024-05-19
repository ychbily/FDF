# FDF - 3D Wireframe Viewer

![FDF Screenshot](./images/img1)

## Overview

FDF is a simple 3D wireframe viewer designed to render landscapes in the form of heightmaps. It reads input files containing coordinates and displays the corresponding 3D representation using the MiniLibX graphics library.

## Features

- **Simple Interface:** FDF provides an easy-to-use interface for viewing 3D wireframe models.
- **Heightmap Rendering:** Utilizes heightmaps to generate 3D landscapes.
- **Color Gradient:** Supports color gradient mapping for better visualization of terrain.
- **Zoom and Rotation:** Allows users to zoom in/out and rotate the rendered model for better inspection.

## Usage

1. Clone the repository:

```bash
git clone https://github.com/ychbily/FDF.git

2. Compile the project:
make
or
make bonus

3. Run the program with a provided map file:
./fdf <map_file>
./fdf_bonus <map_file>

## Control for bonus part:

+ Zoom: Scroll wheel or '+' and '-' keys.
+ Rotation: z, x , y or c , q, w
+ Move: WASD keys or Arrow keys.
+ Parallel Projection: 'p' key.
+ Isometric projection: 'i' key.
+ Reset: 'R' key.
+ Exit: ESC key or click the close button.
