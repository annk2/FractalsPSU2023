
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

int n = 5000000;
double x = 0;
double y = 0;

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

void full_to_light(double swidth)
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

void full_to_dark(double swidth)
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

        G_rgb(0, 0, 0);
        G_point(x * swidth, y * swidth);
        if (i % 1000 == 0)
        {
          G_display_image();
        }
    }
}

void fern(double swidth)
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

        G_rgb(0, 1, y);
        // G_point(x * swidth, y * swidth);
        G_fill_circle(x * swidth, y * swidth, 2.0);
        if (i % 100000 == 0)
        {
            G_display_image();
        }
    }
}

void ifs() {

//     double swidth = 1000.0;
//     double sheight = 1000.0;
//   // must do this before you do 'almost' any other graphical tasks
//   G_init_graphics(swidth, sheight); // interactive graphics

  // clear the screen in a given color
  G_rgb(1, 1, 1); // dark gray
  G_clear();

  //===============================================
  double p[2];
  double p_ely[2];
  double p_textx, p_texty;
  double size_ely = 60.0;
  double size_text = 50.0;
  double size_text_large = 100.0;


  char text[100];

  p_ely[0] = 200.0;
  p_ely[1] = size_ely * 5;

  p_textx = 200.0;
  p_texty = 700.0;

  G_rgb(0, 0, 0);

  p[0] = 0;
  p[1] = 500.0;


  ely(p_ely, size_ely);
  usleep(700000);

  double p_fern[2], t1[2], t2[2];
  p_fern[0] = 50.0;
  p_fern[1] = p_ely[1] - size_ely * 3.0;

  for (int j = 0; j < 200; j++)
    {
        t1[0] = p_fern[0] + (drand48() * 100);
        t1[1] = p_fern[1] + (drand48() * 100);
        t2[0] = p_fern[0] + (drand48() * 100);
        t2[1] = p_fern[1] ; 
        if (j % 2 == 0)
        {
            G_rgb(0, 1, 0.25);
        }
        else
        {
            G_rgb(0, 1, 0.5);
        } 
        G_fill_triangle(p_fern[0], p_fern[1], t1[0], t1[1], t2[0], t2[1]);
        G_display_image();
        usleep(10000);
        p_fern[0] += 5.0;
    }
    usleep(700000);

  G_rgb(1, 0, 0);
  strcpy(text, "!");
  write_text(p_ely[0], p_ely[1] + 100.0,  text, size_text_large);
  usleep(700000);

  G_rgb(0, 0, 0);
  strcpy(text, "...LOOK CLOSER!");
  write_text(p_textx, p_texty, text, size_text);
  usleep(1000000);

  ely_eyes_closed(p_ely, size_ely);
  G_display_image();
  usleep(400000);
  ely_look_down(p_ely, size_ely);
  G_display_image();
  usleep(1000000);

  G_rgb(1, 1, 1);
  G_clear();


    for (int k = 0; k < 1; k++)
    {
        double width = swidth;
        x = 0;
        y = 0;
        for (int i = 0 ; i < 3; i++)
        {
            fern(width);
            usleep(20000);
            width += 200.0;
            G_rgb(1, 1, 1);
            G_clear();
        }
    }

    ely_clear(p_ely, size_ely);
  p_fern[0] = 50.0;
  p_fern[1] = p_ely[1] - size_ely * 3.0;
    for (int j = 0; j < 200; j++)
    {
        t1[0] = p_fern[0] + (drand48() * 100);
        t1[1] = p_fern[1] + (drand48() * 100);
        t2[0] = p_fern[0] + (drand48() * 100);
        t2[1] = p_fern[1] ; 
        if (j % 2 == 0)
        {
            G_rgb(0, 1, 0.25);
        }
        else
        {
            G_rgb(0, 1, 0.5);
        } 
        G_fill_triangle(p_fern[0], p_fern[1], t1[0], t1[1], t2[0], t2[1]);
        p_fern[0] += 5.0;
    }
    usleep(400000);

  G_rgb(1, 0, 0);
  strcpy(text, "WAIT..");
  write_text(p_textx, p_texty, text, size_text_large);
  usleep(500000);

  ely_clear(p_ely, size_ely * 2.0);
  G_rgb(0, 0, 0);
  strcpy(text, "DID YOU JUST.. ");
  write_text(p_textx, p_texty, text, size_text);
strcpy(text, "EAT ONE..");
  write_text(p_textx, p_texty - (size_text * 2.0), text, size_text);
  usleep(800000);

  ely_clear(p_ely, size_ely * 3.0);
  G_rgb(0, 0, 0);
  strcpy(text, "OH NO...");
  write_text(p_textx, p_texty, text, size_text_large);
  usleep(500000);

    ely_clear(p_ely, size_ely * 5.0);
  G_rgb(0, 0, 0);
  strcpy(text, "YOU MIGHT START");
  write_text(p_textx, p_texty, text, size_text);
  strcpy(text, "HAVING SOME");
  write_text(p_textx, p_texty - (size_text * 2.0), text, size_text);
  G_rgb(1, 0, 0);
  strcpy(text, "VISIONS...");
  write_text(p_textx, p_texty - (size_text * 4.0), text, size_text);
  usleep(1000000);

    double p_ely_zoom[2];
    p_ely_zoom[0] = p_ely[0] * 4.0;
    p_ely_zoom[1] = p_ely[1] * 2.0;
    ely_clear(p_ely_zoom , size_ely * 10.0);
    for (int l = 0; l < 20; l++)
    {
        ely_eyes_flash(p_ely_zoom, size_ely * 10.0);
        G_display_image();
        usleep(50000);
    }

    full_to_dark(swidth);
      G_rgb(0, 0, 0);
      G_clear();


//   int key;
//   key = G_wait_key(); // pause so user can see results

//   //   G_save_image_to_file("demo.xwd") ;
//   G_save_to_bmp_file("demo.bmp");

}
