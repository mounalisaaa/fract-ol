#include "fractol.h"

int get_color(int it)
{
    int colors[6];

    colors[0] = 0x0b232a;
    colors[1] = 0x0f3642;
    colors[2] = 0x106575;
    colors[3] = 0x4babb1;
    colors[4] = 0xa2d5dd;
    colors[5] = 0;

    // Determine the color based on the iteration count
    int index = it % (sizeof(colors) / sizeof(colors[0]));
    return colors[index];
}
