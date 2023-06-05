
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

int main() {
  int swidth, sheight;
  double lowleftx, lowlefty, width, height;
  double x[10], y[10];
  double numxy;
  double a[20], b[20];
  double numab;
  double gap;
  double cur_location;
  int row_col;
  int num_lines;

  printf("Enter a value for n (n = # of rows/columns in graph): ");
  scanf("%d", &row_col);
  // gap = swidth / row_col;
  // printf("%f", gap);

  // must do this before you do 'almost' any other graphical tasks
  swidth = 400;
  sheight = 400;
  G_init_graphics(swidth, sheight); // interactive graphics

  // clear the screen in a given color
  G_rgb(0.3, 0.3, 0.3); // dark gray
  G_clear();

  // draw a point
  // G_rgb (1.0, 0.0, 0.0) ; // red
  // G_point (200, 580) ; // hard to see

  // task 1: graph paper
  for (int i = 0; i < row_col; i++) {
    G_rgb(1.0, 1.0, 1.0); 
    cur_location = i * gap;
    G_line(0, cur_location, swidth - 1, cur_location);
    G_line(cur_location, 0, cur_location, sheight - 1);
  }

  // task 2: lines with n
  // (n = # of lines to draw)
  for (int i = 0; i < num_lines; i++) {
    G_rgb(1.0, 1.0, 1.0); 
    cur_location = i * gap;
    G_line(0, sheight - 1 - (cur_location), swidth - 1 - (cur_location), 0);
  }

  //===============================================

  int key;
  key = G_wait_key(); // pause so user can see results

  //   G_save_image_to_file("demo.xwd") ;
  G_save_to_bmp_file("demo.bmp");

  // double slope = dy/dx ;
  double iterator = 0.001;
  double current = [x, y]

  while (current <= end)
    {
      current[0] *= dx * iterator;
      current[1] *= dy * iterator;

      iterator += 0.001
    }
}
