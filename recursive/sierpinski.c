#include "FPToolkit.c"

void sierpinski(double p1[2], double p2[2], double p3[2], double depth)
{
    double m1[2], m2[2], m3[2];

    G_triangle(p1[0], p1[1], p2[0], p2[1], p3[0], p3[1]);

    m1[0] = p1[0] + ((p2[0] - p1[0]) * 0.5);
    m1[1] = p1[1] + ((p2[1] - p1[1]) * 0.5);

    m2[0] = p2[0] + ((p3[0] - p2[0]) * 0.5);
    m2[1] = p2[1] + ((p3[1] - p2[1]) * 0.5);

    m3[0] = p1[0] + ((p3[0] - p1[0]) * 0.5);
    m3[1] = p1[1] + ((p3[1] - p1[1]) * 0.5);

    if (depth > 0)
    {
        sierpinski(p1, m1, m3, depth - 1);
        sierpinski(m1, p2, m2, depth - 1);
        sierpinski(m3, m2, p3, depth - 1);
    }
}