
/*
    FPToolkit.c : A simple set of graphical tools.
    FPToolkitDemo.c
    Copyright (C) 2018  Ely

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License (version 3)
    as published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/*

This code assumes an underlying X11 environment.

       Most freshly installed unbuntu environments do not have
       the X11 developr stuff they'll need to do graphics.
       To download X11 developer stuff, connect to the internet and
       issue the following two commands.  Each will ask for your password
       and each will take a few minutes.  At some point it might even
       look like nothing is happening....be patient :

sudo  apt-get  install  libx11-dev

sudo  apt-get  install  xorg-dev

*/

/*
If this file and the file, FPToolkit.c, are in the
same directory that you are trying to compile in,
do the following :

cc  FPToolkitDemoB.c   -lm  -lX11

note : the 'X' in -X11 is capitalized
*/

#include "FPToolkit.c"

int n = 50000000;
double x = 0;
double y = 0;
double swidth = 1000.0;
double sheight = 1000.0;

void rotate(double deg)
{
    double r, a;
    double t = deg * (M_PI/180);
    double temp;
    double c,s;
    c = cos(t);
    s = sin(t);

    //for?

    temp = (x * c) - (y * s);
    y = (y * c) + (x * s);
    x = temp;
}

void scale(double sfx, double sfy)
{
    x *= sfx;
    y *= sfy;
}

void translate(double dx, double dy)
{
    x += dx;
    y += dy;
}

void full()
{ 
    double r;

    for (int i = 0; i < n; i++)
    {
        r = drand48();

        if (r < 0.25)
        {
            scale(0.5, 0.5);
        }
        else if (r < 0.5)
        {
            scale(0.5, 0.5);
            translate(0.5, 0);
        }
        else if (r < 0.75)
        {
            scale(0.5, 0.5);
            translate(0, 0.5);
        }
        else
        {
            scale(0.5, 0.5);
            translate(0.5, 0.5);
        }

        G_rgb(1, 1, 1);
        G_point(x * swidth, y * swidth);
        if (i % 1000 == 0)
        {
          G_display_image();
        }
    }
}

void fern()
{ 
    double r;

    for (int i = 0; i < n; i++)
    {
        r = drand48();

        if (r < 0.25)
        {
            translate(-0.5, 0);

            rotate(14.715);
            scale(0, 0.156);

            translate(0.5, 0);
        }
        else if (r < 0.5)
        {
            translate(-0.5, 0);

            rotate(-2.678);
            scale(0.849, 0.849);

            translate(0.5, 0.16);
        }
        else if (r < 0.75)
        {
            translate(-0.5, 0);

            rotate(52.462);
            scale(-0.383, 0.383);

            translate(0.5, 0.04);
        }
        else
        {
            translate(-0.5, 0);

            rotate(51.418);
            scale(0.335, 0.335);

            translate(0.5, 0.16);
        }

        G_rgb(1, 1, 1);
        G_point(x * swidth, y * swidth);
    }
}

int main() {

  // must do this before you do 'almost' any other graphical tasks
  G_init_graphics(swidth, sheight); // interactive graphics

  // clear the screen in a given color
  G_rgb(0, 0, 0); // dark gray
  G_clear();

  //===============================================

  // fern();
  full();

  int key;
  key = G_wait_key(); // pause so user can see results

  //   G_save_image_to_file("demo.xwd") ;
  G_save_to_bmp_file("demo.bmp");

}
