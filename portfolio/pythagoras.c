#include "FPToolkit.c"

void square(double p0[], double p1[], double p2[], double p3[], double grad)
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

    G_rgb(0, grad, 0);
    G_fill_polygon(x, y, 4); //takes 2 arrays of x and y coordinates, 3rd arg is length
}

void triangle(double p0[2], double p1[2], double top[2], double grad)
{
    double dx = p1[0] - p0[0];
    double dy = p1[1] - p0[1];

    double fraction = 0.6;
    while (fraction > 0.5 && fraction < 0.3)
    {
        fraction = drand48();
    }

    // fraction = 0.5;
    double g = sqrt((fraction * (1 - fraction)));

    double mx = p0[0] + fraction * dx;
    double my = p0[1] + fraction * dy;

    top[0] = mx - g * dy;
    top[1] = my + g * dx;

    // G_line(top[0], top[1], p0[0], p0[1]);
    // G_line(top[0], top[1], p1[0], p1[1]);

    G_rgb(0, grad, 0);
    G_fill_triangle(p0[0], p0[1], top[0], top[1], p1[0], p1[1]);

    G_rgb(0, grad + 0.1, 0);
    G_triangle(p0[0], p0[1], top[0], top[1], p1[0], p1[1]);

    G_rgb(0, grad + 0.1, 0);
    sierpinski(p0, top, p1, 4);
}

void pythagoras(double p0[2], double p1[2], double depth, double grad)
{
    double p2[2], p3[2], top[2];

    square(p0, p1, p2, p3, grad);
    triangle(p3, p2, top, grad);
    G_display_image();

    // children
    if (depth > 0)
    {
        pythagoras(p3, top, depth - 1, grad - 0.07);
        pythagoras(top, p2, depth - 1, grad - 0.07);
    }
}

void pythagoras_grow(double p[2])
{
  double p1[2], p2[2];
  double p_ely[2], p_text[2];
  double depth = 7.0;
  double size_pythagoras = 70.0;
  int num_trees = 5;
  int layers = 4;
  double size_ely = 50.0;
  double size_text = 50.0;
  double grad = 0.4;
  
  p1[0] = p[0];
  p1[1] = p[1];
//   p1[0] = 5.0;
//   p1[1] = 900.0;

  for (int i = 1; i <= layers; i++)
  {
    p1[0] = p[0]; // 10.0;

    if (i % 2 == 0)
    {
      p1[0] += (2.0 * size_pythagoras);
    }

    p1[1] -= (3.0 * size_pythagoras);
    p2[1] = p1[1];
    G_rgb(0, grad, 0);

    for (int j = 0; j < num_trees; j++)
    {
      // double r = drand48() * 10.0;
      p1[0] += (4.0 * size_pythagoras);
      p2[0] = p1[0] + size_pythagoras ;

      pythagoras(p1, p2, depth, grad);
    }

    grad += 0.2;
    size_pythagoras += 10.0;
  }
  }
