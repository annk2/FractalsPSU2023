#include "FPToolkit.c"

void square(double p0[], double p1[], double p2[], double p3[])
{
    double x[4], y[4];
    double dx1 = p1[0] - p0[0];
    double dy1 = p1[1] - p0[1];
    p2[0] = p1[0] - dy1;
    p2[1] = p1[1] + dx1;

    double dx2 = p2[0] - p1[0];
    double dy2 = p2[1] - p1[1];
    p3[0] = p2[0] - dy2;
    p3[1] = p2[1] + dx2;

    x[0] = p0[0];
    y[0] = p0[1];
    x[1] = p1[0];
    y[1] = p1[1];
    x[2] = p2[0];
    y[2] = p2[1];
    x[3] = p3[0];
    y[3] = p3[1];

    // arrays
    G_rgb(0, 0, 0);
    G_fill_polygon(x, y, 4); //takes 2 arrays of x and y coordinates, 3rd arg is length
}

void triangle(double p0[2], double p1[2], double top[2])
{
    double dx = p1[0] - p0[0];
    double dy = p1[1] - p0[1];

    double fraction = 0.5; //0.3; // 0.5 for equal
    double g = sqrt((fraction * (1 - fraction)));

    double mx = p0[0] + fraction * dx;
    double my = p0[1] + fraction * dy;

    top[0] = mx - g * dy;
    top[1] = my + g * dx;

    G_line(top[0], top[1], p0[0], p0[1]);
    G_line(top[0], top[1], p1[0], p1[1]);
}

void pythagoras(double p0[2], double p1[2], double depth)
{
    double p2[2], p3[2], top[2];

    square(p0, p1, p2, p3);
    triangle(p3, p2, top);

    // children
    if (depth > 0)
    {
        pythagoras(p3, top, depth - 1);
        pythagoras(top, p2, depth - 1);
    }
}
