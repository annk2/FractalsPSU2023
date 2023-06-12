#include "FPToolkit.c"

void pythagoras(double p1[2], double p2[2], double depth)
{
    double m[2];
    // does this end w squares or start w squares?

    m[0] = p1[0] + (p2[0] - p1[0]) * 0.5; 
    m[1] = p1[1] + ((sqrt(3) / 2) * (p2[0] - p1[0]));

    G_fill_triangle(p1[0], p1[1],   m[0], m[1],    p2[0], p2[1]);

    // square
    // G_line(p1[0], p1[1], p2[0], p2[1], p3[0], p3[1]);

    // triangles
    // p2[0] = p1[0] + (p3[0] - p1[0]) * 0.5; 
    // p2[1] = p1[1] + ((sqrt(3) / 2) * (p3[0] - p1[0]));

    // if (depth > 0)
    // {
    //     pythagoras()
    // }
}