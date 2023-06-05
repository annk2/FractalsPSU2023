#include "FPToolkit.c"
#include <complex.h>

double Wsize;

// void mandelbrot( double rcen, double icen, double rad, double cutoff, int mlimit )
void mandelbrot( double rcen, double icen, double rad, int mlimit, double Wsize )
{
    double delta, x, y, xp, yp;
    complex c;
    complex z;
    int reps;

    delta = 2 * rad / Wsize;
    y = icen - rad;
    for (yp = 0; yp < Wsize; yp++)
    {
        x = rcen - rad;
        for (xp = 0; xp < Wsize; xp++)
        {

            //the mandelbrot iteration:
            c = x + y * I;
            z = 0;
            for (reps = 0; reps < mlimit; reps++)
            {
                if (cabs(z) > 2.0) { break; }
                z = z * z + c;
            }

            //color scheme:
            if (reps == mlimit)
            {
                G_rgb(0, 1, 0);
            }
            else
            {
                G_rgb(0, 0, 1);
            }

            G_point(xp, yp);
            x = x + delta;
        }

        y = y + delta;
    }
}