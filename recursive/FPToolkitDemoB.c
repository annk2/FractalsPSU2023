
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
#include "sierpinski.c"
#include "pythagoras.c"
#include "ely.c"
#include "write_text.c"

int main() {
  int swidth, sheight;

  swidth = 1000;
  sheight = 1000;
  G_init_graphics(swidth, sheight); // interactive graphics

  // clear the screen in a given color
  G_rgb(1, 1, 1);
  G_clear();

  // sierpinski
  //===============================================
  // double p1[2], p2[2], p3[2], m[0];
  // double depth = 4.0;

  // p1[0] = 100.0;
  // p1[1] = 10.0;
  // p3[0] = 900.0;
  // p3[1] = 10.0;

  // m[0] = p1[0] + (p3[0] - p1[0]) * 0.5; 
  // m[1] = p1[1] + (p3[1] - p1[1]) * 0.5; 

  // p2[0] = p1[0] + (p3[0] - p1[0]) * 0.5; 
  // p2[1] = p1[1] + ((sqrt(3) / 2) * (p3[0] - p1[0]));
  // p2[1] = m[1] + ((sqrt(3) / 2) * (p3[0] - p1[0]));

  // G_rgb(1, 1, 1);
  // sierpinski(p1, p2, p3, depth);

  // pythagoras
  //===============================================
  double p1[2], p2[2];
  double p_ely[2], p_text[2];
  double depth = 7.0;
  // double size_pythagoras = 100.0;
  double size_pythagoras = 70.0;
  int num_trees = 5;
  int layers = 4;
  double size_ely = 50.0;
  double size_text = 50.0;
  double grad = 0.4;

  p1[0] = 5.0;
  p1[1] = 900.0;


  char text[100];
  strcpy(text, "WAKE UP!");

  p_ely[0] = swidth / 2.0;
  p_ely[1] = size_ely * 5;

  p_text[0] = swidth / 2.0;
  p_text[1] = 900.0;

  for (int i = 1; i <= layers; i++)
  {
    p1[0] = 10.0;

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

    // p1[0] += size_pythagoras;
    grad += 0.2;
    // --num_trees;
  }

  // G_rgb(0, 0, 0);
  // ely(p_ely, size_ely);
  // write_text(p_text, text, size_text);

 

  int key;
  key = G_wait_key(); // pause so user can see results

  G_save_to_bmp_file("demo.bmp");

}
