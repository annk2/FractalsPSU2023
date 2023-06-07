
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

int main() {
  int swidth, sheight;

  swidth = 1000;
  sheight = 1000;
  G_init_graphics(swidth, sheight); // interactive graphics

  // clear the screen in a given color
  G_rgb(0, 0, 0);
  G_clear();

  //===============================================
  double p1[2], p2[2], p3[2], m[0];
  double depth = 4.0;

  p1[0] = 100.0;
  p1[1] = 10.0;
  p3[0] = 900.0;
  p3[1] = 10.0;

  // m[0] = p1[0] + (p3[0] - p1[0]) * 0.5; 
  // m[1] = p1[1] + (p3[1] - p1[1]) * 0.5; 

  p2[0] = p1[0] + (p3[0] - p1[0]) * 0.5; 
  p2[1] = p1[1] + ((sqrt(3) / 2) * (p3[0] - p1[0]));
  // p2[1] = m[1] + ((sqrt(3) / 2) * (p3[0] - p1[0]));

  G_rgb(1, 1, 1);
  sierpinski(p1, p2, p3, depth);

  int key;
  key = G_wait_key(); // pause so user can see results

  G_save_to_bmp_file("demo.bmp");

}
