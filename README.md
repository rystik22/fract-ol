# Fract-ol

Fract-ol is a fractal exploration program developed as part of the 42 Abu Dhabi curriculum. It visualizes complex mathematical sets with interactive controls, allowing zoom, movement, color changes, and dynamic transformations.

## Fractals Implemented
- **Mandelbrot Set:** Zoom and navigate through the intricate patterns of the Mandelbrot set.
- **Julia Set:** Experience real-time transformations of the Julia set by moving the mouse, with options to pause and resume.
- **Tricorn (Bonus):** A variant of the Mandelbrot set with inverted iterations, offering unique patterns.

## Controls
- **Zoom:** Scroll up/down to zoom in and out.
- **Navigation:** Use arrow keys to move the fractal view.
- **Color Modes:** Press `1`, `2`, or `3` to switch color schemes.
- **Julia Dynamic Mode:** Move the mouse to dynamically alter the Julia set.
  - Press `Space` to pause mouse interaction.
  - Press `Enter` to resume.

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/rystik22/fractol.git
   cd fractol
   ```
2. Ensure MiniLibX is in the root directory. This project is compatible with macOS MiniLibX. Linux compatibility may require additional adjustments.
3. Compile the project:
   ```bash
   make
   ```

## Usage
Run the program with the following options:
```bash
./fractol 1                # Mandelbrot Set
./fractol 0                # Julia Set (default parameters)
./fractol -0.6 0.125       # Julia Set with custom points (range: -2 to 2)
./fractol 2                # Tricorn Set
```
If invalid arguments are provided, an error message will guide you through the options.

## Learning Resources
Understanding MiniLibX is crucial for this project. A great resource is available at [42docs MiniLibX Guide](https://harm-smits.github.io/42docs/libs/minilibx).

## Notes
- No dynamic memory allocation is used, simplifying memory management.
- The project is built for macOS and may not run on Linux without changes to the MiniLibX setup.

## Credits
- **Author:** rradin-m
- **School:** 42AD

Enjoy exploring the mesmerizing world of fractals!

