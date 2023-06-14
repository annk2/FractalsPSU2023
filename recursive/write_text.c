#include "FPToolkit.c"

void A(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size - (space);
    double horiz = size - (space * 2.0) - (font_width * 2.0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + (size - (space * 2.0));
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + space + font_width;
    A[1] = p[1] + size_tall;
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[0] = p[0] + space + font_width;
    A[1] = p[1] + (size_tall / 2.0);
    G_fill_rectangle(A[0], A[1], horiz, font_width);
}

void E(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0);
    G_rgb(0, 0, 0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[1] = p[1] + (size_tall - font_width);
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[1] = p[1] + (size_tall / 2.0);
    G_fill_rectangle(A[0], A[1], horiz, font_width);
}

void I(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);
    G_rgb(0, 0, 0);

    A[0] = p[0] + (size_tall / 2.0);
    A[1] = p[1] + (font_width * 2.0);
    G_fill_rectangle(A[0], A[1], font_width, size_tall);
}

void K(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0);
    G_rgb(0, 0, 0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + (font_width * 2.0);
    A[1] = p[1] + (size_tall / 2.0);
    G_fill_rectangle(A[0], A[1], font_width, font_width);

    for (int i = 0; i < 4; i++)
    {
        A[0] += font_width;
        A[1] += font_width;
        G_fill_rectangle(A[0], A[1], font_width, font_width);
    }

    A[0] = p[0] + space;
    A[1] = p[1] + (size_tall / 2.0);
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[0] = p[0] + (size_tall - (space * 2.0));
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall / 2.0);
}

void P(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0);
    G_rgb(0, 0, 0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + (size_tall - space - font_width);
    A[1] = p[1] + (size_tall / 2.0);
    G_fill_rectangle(A[0], A[1], font_width, size_tall / 2.0);

    A[0] = p[0] + space;
    A[1] = p[1] + (size_tall - font_width);
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[0] = p[0] + space;
    A[1] = p[1] + (size_tall / 2.0);
    G_fill_rectangle(A[0], A[1], horiz, font_width);
}

void T(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);
    G_rgb(0, 0, 0);

    A[0] = p[0] + (size_tall / 2.0);
    A[1] = p[1] + (font_width * 2.0);
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + space;
    A[1] = p[1] + (size_tall - font_width);
    G_fill_rectangle(A[0], A[1], horiz, font_width);
}

void U(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);
    G_rgb(0, 0, 0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + (size - (space * 2.0));
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + space + font_width;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], horiz, font_width);
}

void W(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);
    G_rgb(0, 0, 0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + (size - (space * 2.0));
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + space + font_width;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[0] = p[0] + (size / 2.0) - font_width;
    A[1] = p[1] ;
    G_fill_rectangle(A[0], A[1], font_width, size_tall / 2.0);
}

void EXCL(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);
    G_rgb(0, 0, 0);

    A[0] = p[0] + (size_tall / 2.0);
    A[1] = p[1] + (font_width * 2.0);
    G_fill_rectangle(A[0], A[1], font_width, size_tall - (font_width * 2.0));

    A[0] = p[0] + (size_tall / 2.0);
    A[1] = p[1] ;
    G_fill_rectangle(A[0], A[1], font_width, font_width);
}

void QUEST(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);
    G_rgb(0, 0, 0);

    A[0] = p[0] + space;
    A[1] = p[1] + (size_tall - font_width);
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[0] = p[0] + (size_tall - space - font_width);
    A[1] = p[1] + (size_tall / 2.0) - font_width;
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    G_fill_rectangle(A[0], A[1], font_width, size_tall / 2.0);
}


void write_text(double p[2], char string[1000], double size)
{
    char cur;
    int len = strlen(string);
    G_rgb(0, 0, 0);

    for (int i = 0; i < len; i++)
    {
        cur = string[i];

        if (cur == 'A')
        {
            A(p, size);
        }
        else if (cur == 'E')
        {
            E(p, size);
        }
        else if (cur == 'I')
        {
            I(p, size);
        }
        else if (cur == 'K')
        {
            K(p, size);
        }
        else if (cur == 'P')
        {
            P(p, size);
        }
        else if (cur == 'T')
        {
            T(p, size);
        }
        else if (cur == 'U')
        {
            U(p, size);
        }
        else if (cur == 'W')
        {
            W(p, size);
        }
        else if (cur == '!')
        {
            EXCL(p, size);
        }
        else if (cur == '?')
        {
            QUEST(p, size);
        }

        usleep(200000);
        G_display_image();
        p[0] += size;
    }
}

