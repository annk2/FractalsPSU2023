#include "FPToolkit.c"
#include <complex.h>

double Wsize;

void julia( double rcen, double icen, double rad, int mlimit, double Wsize )
{
    double delta, x, y, xp, yp;
    complex c = (-0.8) + 0.156 * I;
    complex z;
    int reps;

    int divisions = 4;

    delta = 2 * rad / Wsize;
    y = icen - rad;
    for (yp = 0; yp < Wsize; yp++)
    {
        x = rcen - rad;
        for (xp = 0; xp < Wsize; xp++)
        {

            //the julia iteration:
            // c = x + y * I;
            z = x + y * I;
            for (reps = 0; reps < mlimit; reps++)
            {
                if (cabs(z) > 2.0)
                { 
                //     if (reps < (0.5) * )
                //     {
                //         d1 = true;
                //     }
                    break; 
                }
                z = z * z + c;
            }

            //color scheme:
            if (reps == mlimit)
            {
                G_rgb(0, 0, 0);
            }
            else // diverge
            {
                // double gradient = 0;
                for (int i = 0; i < divisions; i++)
                {
                    double divisor = (double) mlimit / (double) divisions;
                    double gradient = i * (1.0 / (double) divisions);

                    if (reps < ( i * divisor ))
                    {
                        G_rgb(gradient, gradient, gradient);
                        break;
                    }
                }
                // else
                // {
                //     G_rgb(0, 0, 1);
                // }
            }

            G_point(xp, yp);
            x = x + delta;
        }

        y = y + delta;
    }
}

// void mandelbrot( double rcen, double icen, double rad, double cutoff, int mlimit )
void mandelbrot( double rcen, double icen, double rad, int mlimit, double Wsize )
{
    double delta, x, y, xp, yp;
    complex c;
    complex z;
    int reps;

    int divisions = 4;

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
                if (cabs(z) > 2.0)
                { 
                //     if (reps < (0.5) * )
                //     {
                //         d1 = true;
                //     }
                    break; 
                }
                z = z * z + c;
            }

            //color scheme:
            if (reps == mlimit)
            {
                G_rgb(0, 0, 0);
            }
            else // diverge
            {
                // double gradient = 0;
                for (int i = 0; i < divisions; i++)
                {
                    double divisor = (double) mlimit / (double) divisions;
                    double gradient = i * (1.0 / (double) divisions);

                    if (reps < ( i * divisor ))
                    {
                        G_rgb(gradient, gradient, gradient);
                        break;
                    }
                }
                // else
                // {
                //     G_rgb(0, 0, 1);
                // }
            }

            G_point(xp, yp);
            x = x + delta;
        }

        y = y + delta;
    }
}