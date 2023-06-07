
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

struct GRAMMAR
{
  char[3] axiom;
  char [3] value;
  char [100] rule;
};

void set_fern()
// FERN GRAMMAR
// Axiom: A
// A-> F-[[A]+A]+F[+FA]-A
// F-> FF

// angle: 22.5

// struct
// axiom
// rules
// start angle
// delta

int main() {
  int swidth, sheight;
  struct GRAMMAR[5] grammar;

  swidth = 1000;
  sheight = 1000;
  G_init_graphics(swidth, sheight); // interactive graphics

  // clear the screen in a given color
  G_rgb(0, 0, 0);
  G_clear();

  //===============================================
  char string[100000];
  string[0] = '\0';
  double start_angle = 0;

  double delta = M_PI/6; // koch

  scanf("%s", string);

  // strcpy()

  G_rgb(1, 1, 1);
  string_interpreter(grammar, string, angle);

  int key;
  key = G_wait_key(); // pause so user can see results

  //   G_save_image_to_file("demo.xwd") ;
  G_save_to_bmp_file("demo.bmp");

}
