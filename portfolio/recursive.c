
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
#include "ifs.c"

void recursive() {
  // int swidth, sheight;

  // swidth = 1000;
  // sheight = 1000;
  // G_init_graphics(swidth, sheight); // interactive graphics

  // clear the screen in a given color
  G_rgb(0, 0, 0);
  G_clear();

  //===============================================
  double p1[2], p2[2];
  double p_ely[2];
  double p_textx, p_texty;
  double depth = 7.0;
  double size_pythagoras = 70.0;
  int num_trees = 5;
  int layers = 4;
  double size_ely = 60.0;
  double size_text = 50.0;
  double size_text_large = 100.0;
  double grad = 0.4;

  p1[0] = 5.0;
  p1[1] = 900.0;


  char text[100];

  p_ely[0] = 200.0;
  p_ely[1] = size_ely * 5;

  p_textx = 200.0;
  p_texty = 700.0;

  sleep(1);
  full_to_light(swidth);
  G_rgb(1, 1, 1);
  G_clear();
  G_rgb(0, 0, 0);
  ely_eyes_closed(p_ely, size_ely);

  G_rgb(1, 0, 0);
  strcpy(text, "WAKE");
  write_text(p_textx, p_texty, text, size_text_large);
  strcpy(text, "UP!");
  write_text(p_textx, p_texty - size_text_large - 10.0, text, size_text_large);

  for (int i = 0; i < 3; i++)
  {
    ely_eyes_closed(p_ely, size_ely);
    G_display_image();
    usleep(300000);
    ely(p_ely, size_ely);
    G_display_image();
    usleep(300000);
  }

  ely_clear(p_ely, size_ely);
  G_rgb(1, 0, 0);
  strcpy(text, "!");
  write_text(p_ely[0], p_ely[1] + 100.0,  text, size_text_large);
  usleep(400000);

  ely_clear(p_ely, size_ely);
  G_rgb(0, 0, 0);
  strcpy(text, "ITS TIME TO");
  write_text(p_textx, p_texty, text, size_text);
  strcpy(text, "EXPLORE");
  write_text(p_textx, p_texty - (size_text * 2.0),  text, size_text);
  G_rgb(1, 0, 0);
  strcpy(text, "FRACTALS!");
  write_text(p_textx, p_texty - (size_text * 4.0),  text, size_text);
  usleep(1000000);

  ely_clear(p_ely, size_ely);

  double p_tree[2];
  p_tree[0] = 500.0;
  p_tree[1] = 900.0;
  for (int j = 0; j < 2; j++)
  {
    pythagoras_grow(p_tree);
    G_rgb(1, 1, 1);
    G_rgb(1, 0, 0);
    strcpy(text, "!");
    write_text(p_ely[0], p_ely[1] + 100.0,  text, size_text_large);
    usleep(300000);
    ely_clear(p_ely, size_ely);
    p_tree[0] -= 300.0;
  }

  pythagoras_grow(p_tree);
  G_rgb(1, 0, 0);
  strcpy(text, "!!!!!");
  write_text(p_ely[0], p_ely[1] + 100.0,  text, size_text_large);
  usleep(300000);

  ely_clear(p_ely, size_ely);
  G_rgb(0, 0, 0);
  strcpy(text, "OOPS SORRY...");
  write_text(p_textx, p_texty, text, size_text);
  usleep(800000);

  ely_clear(p_ely, size_ely);
  G_rgb(0, 0, 0);
  strcpy(text, "NEXT...");
  write_text(p_textx, p_texty, text, size_text_large);
  usleep(500000);

  // int key;
  // key = G_wait_key(); // pause so user can see results
}
