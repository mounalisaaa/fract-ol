#include "fractol.h"

int get_color(int it)
{
    int colors[6];

    colors[] = {
        0x0b232a,  // (11, 35, 42)
        0x0f3642,  // (15, 54, 66)
        0x106575,  // (16, 101, 117)
        0x4babb1,  // (75, 171, 177)
        0xa2d5dd   // (162, 213, 221)
    };

    // Determine the color based on the iteration count
    int index = it % (sizeof(colors) / sizeof(colors[0]));
    return colors[index];
}
