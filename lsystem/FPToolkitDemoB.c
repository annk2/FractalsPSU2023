
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
  double angle;
  double start_angle;
  double length;
  char axiom;
  char value;
  char rule[100];
};

void set_fern(struct GRAMMAR grammar[5])
{
  grammar[0].angle = 22.5;
  grammar[0].start_angle = 90;
  grammar[0].length = 1.0; // idk
  grammar[0].axiom = 'A';

  grammar[1].value = 'A';
  strcpy(grammar[1].rule, "F-[[A]+A]+F[+FA]-A");

  grammar[2].value = 'F';
  strcpy(grammar[2].rule, "FF");
}

void find_rule(struct GRAMMAR grammar[5], char rule[100], char value)
{
  for(int i = 0; i < 5; i++)
  {
      if(grammar[i].value == value)
      {
        strcpy(rule, grammar[i].rule);
      }
  } 
}

void string_builder(struct GRAMMAR grammar[5], char string[1000000], int depth)
{
  char cur;
  int len;
  char rule[100];
  char hold_string[1000000];

  rule[0] = '\0';
  hold_string[0] = grammar[0].axiom;
  hold_string[1] = '\0';
  string[0] = grammar[0].axiom;
  string[1] = '\0';

  // strcat(hold_string, grammar[0].axiom);
  // printf("string1: %s\n", string);

  for(int i = 0; i < depth; i++)
  {
    printf("depth: %d\t string: %s\n", i, string);
    len = strlen(hold_string);

    for(int j = 0; j < len; j++)
    {
      cur = hold_string[j];
      find_rule(grammar, rule, cur);
      strcat(string, rule);
    }

    strcpy(hold_string, string);
  }
}

int main() {
  int swidth, sheight;
  struct GRAMMAR grammar[5];

  // swidth = 1000;
  // sheight = 1000;
  // G_init_graphics(swidth, sheight); // interactive graphics

  // clear the screen in a given color
  // G_rgb(0, 0, 0);
  // G_clear();

  //===============================================
  char string[100000];
  string[0] = '\0';
  double start_angle = 0;
  int depth = 3;

  double delta = M_PI/6; // koch
  // double delta = 22.5 // fern, in degrees

  set_fern(grammar);

  scanf("%s", string);

  // G_rgb(1, 1, 1);
  string_interpreter(string, grammar, p);
  // string_builder(grammar, string, depth);

  // int key;
  // key = G_wait_key(); // pause so user can see results

  // //   G_save_image_to_file("demo.xwd") ;
  // G_save_to_bmp_file("demo.bmp");

}