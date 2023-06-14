
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

typedef struct GRAMMAR
{
  double angle;
  double start_angle;
  double length;
  int rule_num;
  char axiom;
  char value;
  char rule[100];
} GRAMMAR;

typedef struct STATE
{
    double x;
    double y;
    double angle;
} STATE;

char u[1000000];
char v[1000000];
char rule[100];
// GRAMMAR grammar[10];
STATE my_stack[1000000];

void set_plant(GRAMMAR grammar[10])
{
  grammar[0].angle = 20; // 22.5;
  grammar[0].start_angle = 0;
  grammar[0].length = 10.0;
  grammar[0].axiom = 'A';

  grammar[1].value = 'A';
  strcpy(grammar[1].rule, "F-[[A]+A]+F[+FA]-A");

  grammar[2].value = 'F';
  strcpy(grammar[2].rule, "FF");

  grammar[0].rule_num = 3;
}

void set_koch(GRAMMAR grammar[10])
{
  grammar[0].angle = 30;
  grammar[0].start_angle = 0;
  grammar[0].length = 1.0; 
  grammar[0].axiom = 'B';

  grammar[1].value = 'A';
  strcpy(grammar[1].rule, "+A-C-A+");

  grammar[2].value = 'B';
  strcpy(grammar[2].rule, "B+C+B");

  grammar[3].value = 'C';
  strcpy(grammar[2].rule, "A-C-A");

  grammar[0].rule_num = 4;
}

int find_rule(GRAMMAR grammar[10], char value)
{
  int num = grammar[0].rule_num;
  for(int i = 0; i < num; i++)
  {
      if(grammar[i].value == value)
      {
        strcpy(rule, grammar[i].rule);
        return 1;
      }
  } 
  return 0;
}

void string_builder(GRAMMAR grammar[10], int depth)
{
  char cur;
  int len;

  u[0] = grammar[0].axiom;
  u[1] = '\0';

  for(int i = 0; i < depth; i++)
  {
    v[0] = '\0';
    len = strlen(u);

    for(int j = 0; j < len; j++)
    {
      cur = u[j];

      if (find_rule(grammar, cur) == 1)
      {
        strcat(v, rule);
      }
      else
      {
        char temp[2];
        temp[0] = cur;
        temp[1] = '\0';
        strcat(v, temp);
      }
    }

    strcpy(u, v);
  }
}

void string_builder_koch(GRAMMAR grammar[10], char u[1000000], int depth)
{
  char cur;
  int len;

  u[0] = grammar[0].axiom;
  u[1] = '\0';

  for(int i = 0; i < depth; i++)
  {
    v[0] = '\0';
    len = strlen(u);

    for(int j = 0; j < len; j++)
    {
      cur = u[j];

      if (find_rule(grammar, cur) == 1)
      {
        strcat(v, rule);
      }
      else
      {
        char temp[2];
        temp[0] = cur;
        temp[1] = '\0';
        strcat(v, temp);
      }
    }

    strcpy(u, v);
  }
}

void string_interpreter_koch(GRAMMAR grammar[10], char u[1000000], double p[2])
{
    int len = strlen(u);
    char cur;
    double x, y, hold_x, hold_y;
    int top = -1;

    x = p[0];
    y = p[1];

    double angle = grammar[0].start_angle;
    double delta = grammar[0].angle;
    double length = grammar[0].length;

    for (int i = 0; i<len; i++)
    {
        cur = u[i];

        if(cur >= 'A' && cur <= 'Z')
        {
            hold_x = x + length * cos(angle * (M_PI / 180.0));
            hold_y = y + length * sin(angle * (M_PI / 180.0));
            G_line(hold_x, hold_y, x, y);
            if (i % 10 == 0)
            {
              G_display_image();
            }
            x = hold_x;
            y = hold_y;
        }
        else if(cur == '+')
        {
            angle += delta;
        }
        else if(cur == '-')
        {
            angle -= delta;
        }
    }
}

void string_interpreter_plant(GRAMMAR grammar[10], double p[2])
{
    int len = strlen(u);
    char cur;
    double x, y, hold_x, hold_y;
    char koch_string[1000000];
    int top = -1;

    GRAMMAR koch_grammar[10];
    set_koch(koch_grammar);
    string_builder_koch(koch_grammar, koch_string, 7);

    x = p[0];
    y = p[1];

    double angle = grammar[0].start_angle;
    double delta = grammar[0].angle;
    double length = grammar[0].length;

    for (int i = 0; i<len; i++)
    {
        cur = u[i];
        G_rgb(0.647, 0.165, 0.165);

        if(cur >= 'A' && cur <= 'Z')
        {
            hold_x = x + length * cos(angle * (M_PI / 180.0));
            hold_y = y + length * sin(angle * (M_PI / 180.0));
            G_line(hold_x, hold_y, x, y);
            if (i % 2 == 0)
            {
              G_display_image();
            }

            x = hold_x;
            y = hold_y;
        }
        else if(cur == '+')
        {
            angle += delta;
        }
        else if(cur == '-')
        {
            angle -= delta;
        }
        else if(cur == '[')
        {
            // push state
            top++;
            my_stack[top].x = x;
            my_stack[top].y = y;
            my_stack[top].angle = angle;
        }
        else if(cur == ']')
        {
            // pop state
              double q[2];
              q[0] = x;
              q[1] = y;
              if(i % 2 == 0)
              {
                G_rgb(0.8, 0.5, 0.8);
              }
              else
              {
                G_rgb(1, 0.753, 0.796);
              }
              string_interpreter_koch(koch_grammar, koch_string, q);
            x = my_stack[top].x;
            y = my_stack[top].y;
            angle = my_stack[top].angle;
            top--;
        }
    }
}



void lsystem() {
  int swidth, sheight;

  swidth = 1000;
  sheight = 1000;
  G_init_graphics(swidth, sheight); // interactive graphics

  // clear the screen in a given color
  G_rgb(1, 1, 1);
  G_clear();


  //===============================================
  double p[2];
  GRAMMAR grammar[10];
  double p_ely[2];
  double p_textx, p_texty;
  double size_ely = 60.0;
  double size_text = 50.0;
  double size_text_large = 100.0;
  int depth = 5;

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

  double p_tree[2];
  p_tree[0] = 700.0;
  p_tree[1] = p_ely[1] - size_ely * 3.0;
  for (int j = 0; j < 2; j++)
  {
    G_rgb(0.647, 0.165, 0.165);
    G_fill_rectangle(p_tree[0], p_tree[1], 5.0, swidth * 2.0);
    G_display_image();
    usleep(700000);
    ely_clear(p_ely, size_ely);
    p_tree[0] -= 100.0;
  }

  G_rgb(0.647, 0.165, 0.165);
  G_fill_rectangle(p_tree[0], p_tree[1], 5.0, swidth * 2.0);
  G_display_image();
  usleep(700000);
  G_rgb(1, 0, 0);
  strcpy(text, "!");
  write_text(p_ely[0], p_ely[1] + 100.0,  text, size_text_large);
  usleep(700000);

  ely_clear(p_ely, size_ely);
  G_rgb(0, 0, 0);
  strcpy(text, "...LOOK UP!");
  write_text(p_textx, p_texty, text, size_text);
  usleep(700000);

  ely_eyes_closed(p_ely, size_ely);
  G_display_image();
  usleep(400000);
  ely_look_up(p_ely, size_ely);
  G_display_image();
  usleep(400000);

  G_rgb(1, 1, 1);
  G_clear();

  set_plant(grammar);

  string_builder(grammar, depth);
  string_interpreter_plant(grammar, p);
  usleep(800000);

  ely_clear(p_ely, size_ely);
  G_rgb(0, 0, 0);
  strcpy(text, "NEXT...");
  write_text(p_textx, p_texty, text, size_text_large);
  usleep(500000);

  int key;
  key = G_wait_key(); // pause so user can see results

  // //   G_save_image_to_file("demo.xwd") ;
  // G_save_to_bmp_file("demo.bmp");

}