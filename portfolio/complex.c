#include "FPToolkit.c"
#include <complex.h>

double Wsize;

void julia( double rcen, double icen, double rad, int mlimit, double Wsize, double var)
{
    double delta, x, y, xp, yp;
    // double var = drand48();
    // double complex c = (-0.8) + 0.156 * I;
    double complex c = (-0.8) + var * I;
    double complex z;
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
                G_rgb(0, 0.5 + var, 0.2 + var);
            }
            else if (reps == (0.5 * mlimit) )
            {
                G_rgb(1, 1, 1);
            }
            else if (reps == (0.3 * mlimit) )
            {
                G_rgb(0, 0.2 + var, 0.7 + var);
            }
            else
            {
                G_rgb(0, 0, 0);
            }

            // else // diverge
            // {
            //     // double gradient = 0;
            //     for (int i = 0; i < divisions; i++)
            //     {
            //         double divisor = (double) mlimit / (double) divisions;
            //         double gradient = i * (1.0 / (double) divisions);
            //         // double gradient = (double) divisions / (double) i ;
                    
            //         if (reps < ( i * divisor ))
            //         {
            //             G_rgb(gradient - 0.8, gradient, gradient - 0.1);
            //             break;
            //         }
            //     }
                
            // }

            G_point(xp, yp);
            x = x + delta;
        }

        y = y + delta;
    }
}

void complex_num()
{
//     double swidth = 1000.0;
//     double sheight = 1000.0;
//   // must do this before you do 'almost' any other graphical tasks
//   G_init_graphics(swidth, sheight); // interactive graphics

  // clear the screen in a given color
  G_rgb(0, 0, 0); // dark gray
  G_clear();
    double var = 0.16;

  for (int m = 0; m < 3; m++)
  {
     for (int i = 0; i < 7; i++)
    {
        var += 0.01;
        julia( 0, 0, 1, 100, swidth, var);
        G_display_image();
    }

    for (int i = 0; i < 7; i++)
    {
        var -= 0.01;
        julia( 0, 0, 1, 100, swidth, var);
        G_display_image();
    }   
  }

    full_to_dark(swidth);
    G_rgb(0, 0, 0);
    G_clear();
}

// void mandelbrot( double rcen, double icen, double rad, double cutoff, int mlimit )
// void mandelbrot( double rcen, double icen, double rad, int mlimit, double Wsize )
// {
//     double delta, x, y, xp, yp;
//     complex c;
//     complex z;
//     int reps;

//     int divisions = 4;

//     delta = 2 * rad / Wsize;
//     y = icen - rad;
//     for (yp = 0; yp < Wsize; yp++)
//     {
//         x = rcen - rad;
//         for (xp = 0; xp < Wsize; xp++)
//         {

//             //the mandelbrot iteration:
//             c = x + y * I;
//             z = 0;
//             for (reps = 0; reps < mlimit; reps++)
//             {
//                 if (cabs(z) > 2.0)
//                 { 
//                 //     if (reps < (0.5) * )
//                 //     {
//                 //         d1 = true;
//                 //     }
//                     break; 
//                 }
//                 z = z * z + c;
//             }

//             //color scheme:
//             if (reps == mlimit)
//             {
//                 G_rgb(0, 0, 0);
//             }
//             else // diverge
//             {
//                 // double gradient = 0;
//                 for (int i = 0; i < divisions; i++)
//                 {
//                     double divisor = (double) mlimit / (double) divisions;
//                     double gradient = i * (1.0 / (double) divisions);

//                     if (reps < ( i * divisor ))
//                     {
//                         G_rgb(gradient, gradient, gradient);
//                         break;
//                     }
//                 }
//                 // else
//                 // {
//                 //     G_rgb(0, 0, 1);
//                 // }
//             }

//             G_point(xp, yp);
//             x = x + delta;
//         }

//         y = y + delta;
//     }
// }