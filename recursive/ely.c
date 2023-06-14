#include "FPToolkit.c"

void ely(double p[2], double size)
{
    G_fill_circle(p[0], p[1], size);

    double body_height, body_width, start[2], end[2];
    body_height = size * 3.0;
    body_width = size * 2.0;
    start[0] = p[0] - (body_width / 2.0);
    start[1] = p[1] - body_height;
    end[0] = p[0] + (body_width / 2.0);
    end[1] = p[1] - body_height;
    G_fill_triangle(start[0], start[1],     p[0], p[1],    end[0], end[1]);

    double glasses_sep, glasses_size, glasses_left[2], glasses_right[2];
    glasses_sep = size / 2.0;
    glasses_size = size / 5.0;
    glasses_left[0] = p[0] - glasses_sep;
    glasses_left[1] = p[1];
    glasses_right[0] = p[0] + glasses_sep;
    glasses_right[1] = p[1];
    G_rgb(1, 1, 1);
    G_fill_circle(glasses_left[0], glasses_left[1], glasses_size);
    G_fill_circle(glasses_right[0], glasses_right[1], glasses_size);
}

// void ely_walk()
// {}

// void ely_glasses_flash()