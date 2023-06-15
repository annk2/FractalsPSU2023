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

void C(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + space + font_width;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[0] = p[0] + space + font_width;
    A[1] = p[1] + size_tall;
    G_fill_rectangle(A[0], A[1], horiz, font_width);
}

void D(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + space + font_width;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[0] = p[0] + space + font_width;
    A[1] = p[1] + size_tall;
    G_fill_rectangle(A[0], A[1], horiz - (font_width * 3.0), font_width);

    A[0] += horiz - (font_width * 3.0);
    for (int i = 0; i < 2; i++)
    {
        A[0] += font_width;
        A[1] -= font_width;
        G_fill_rectangle(A[0], A[1], font_width, font_width);
    }

    A[0] = p[0] + horiz + font_width;
    A[1] = p[1] ;
    G_fill_rectangle(A[0], A[1], font_width, (size_tall/2.0) + (font_width * 2.0));
}

void E(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[1] = p[1] + (size_tall - font_width);
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[1] = p[1] + (size_tall / 2.0);
    G_fill_rectangle(A[0], A[1], horiz, font_width);
}

void F(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[1] = p[1] + (size_tall - font_width);
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[1] = p[1] + (size_tall / 2.0);
    G_fill_rectangle(A[0], A[1], horiz, font_width);
}

void G(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + space + font_width;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[0] = p[0] + space + font_width;
    A[1] = p[1] + size_tall;
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[0] = p[0] + size_tall/2.0;
    A[1] = p[1] + size_tall/2.0;
    G_fill_rectangle(A[0], A[1], horiz/2.0, font_width);
}

void H(double p[2], double size)
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

    A[0] = p[0] + (size_tall / 2.0);
    A[1] = p[1] + (font_width * 2.0);
    G_fill_rectangle(A[0], A[1], font_width, size_tall);
}

void J(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size - space;
    double horiz = size - (space * 2.0);

    A[0] = p[0] + (size - (space * 2.0));
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + space;
    G_fill_rectangle(A[0], A[1], horiz + font_width, font_width);

    G_fill_rectangle(A[0], A[1], font_width, size_tall/2.0);
}

void K(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0);

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

void L(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    G_fill_rectangle(A[0], A[1], horiz, font_width);
}

void M(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + (size - (space * 2.0));
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + space + font_width;
    A[1] = p[1] + size_tall;
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[0] = p[0] + (size / 2.0) - font_width;
    A[1] = p[1] + (size_tall / 2.0);
    G_fill_rectangle(A[0], A[1], font_width, size_tall / 2.0);
}

void Nn(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + (size - (space * 2.0));
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + space + font_width;
    A[1] = p[1] + size_tall - (font_width * 2.0);
    G_fill_rectangle(A[0], A[1], font_width, font_width);

    for (int i = 0; i < 5; i++)
    {
        A[0] += font_width;
        A[1] -= font_width;
        G_fill_rectangle(A[0], A[1], font_width, font_width);
    }
}

void O(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + (size - (space * 2.0));
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + space + font_width;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[0] = p[0] + space + font_width;
    A[1] = p[1] + size_tall;
    G_fill_rectangle(A[0], A[1], horiz, font_width);
}

void P(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0);

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

void R(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0);

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

    for (int i = 0; i < 6; i++)
    {
        A[0] += font_width;
        A[1] -= font_width;
        G_fill_rectangle(A[0], A[1], font_width, font_width);
    }
}

void S(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);

    A[0] = p[0] + space;
    A[1] = p[1] + (size_tall) + font_width;
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[0] = p[0] + space;
    A[1] = p[1] + (size_tall / 2.0) + font_width;
    G_fill_rectangle(A[0], A[1], font_width, size_tall / 2.0);

    A[0] = p[0] + space;
    A[1] = p[1] + (size_tall / 2.0) + font_width;
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[0] = p[0] + space + horiz;
    A[1] = p[1] + font_width;
    G_fill_rectangle(A[0], A[1], font_width, size_tall / 2.0);

    A[0] = p[0] + space;
    A[1] = p[1] + font_width;
    G_fill_rectangle(A[0], A[1], horiz, font_width);
}

void T(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0);

    A[0] = p[0] + (size_tall / 2.0) - font_width;
    A[1] = p[1] + font_width;
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + space;
    A[1] = p[1] + (size_tall) + font_width;
    G_fill_rectangle(A[0], A[1], horiz, font_width);
}

void U(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);

    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + (size - (space * 2.0));
    G_fill_rectangle(A[0], A[1], font_width, size_tall);

    A[0] = p[0] + space + font_width;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], horiz, font_width);
}

void V(double p[2], double size)
{
    double A[2], B[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0);

    A[0] = p[0] + space;
    A[1] = p[1] + size_tall - font_width;

    B[0] = p[0] + space + horiz;
    B[1] = p[1] + size_tall - font_width;

    for (int i = 0; i < 9; i++)
    {
        G_fill_rectangle(A[0], A[1], font_width, font_width);
        G_fill_rectangle(B[0], B[1], font_width, font_width);
        A[0] += font_width/3.0;
        A[1] -= font_width;
        B[0] -= font_width/3.0;
        B[1] -= font_width;
    }

}

void W(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);

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

void Xx(double p[2], double size)
{
    double A[2], B[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0);

    A[0] = p[0] + space;
    A[1] = p[1];

    B[0] = p[0] + space;
    B[1] = p[1] + size_tall;

    for (int i = 0; i < 9; i++)
    {
        G_fill_rectangle(A[0], A[1], font_width, font_width);
        G_fill_rectangle(B[0], B[1], font_width, font_width);
        A[0] += font_width;
        A[1] += font_width;
        B[0] += font_width;
        B[1] -= font_width;
    }

}

void Yy(double p[2], double size)
{
    double A[2], B[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0);

    A[0] = p[0] + (size_tall / 2.0) - font_width;
    A[1] = p[1] + font_width;
    G_fill_rectangle(A[0], A[1], font_width, size_tall / 2.0);

    A[0] = p[0] + space;
    A[1] = p[1] + size_tall - font_width;

    B[0] = p[0] + space + horiz;
    B[1] = p[1] + size_tall - font_width;

    for (int i = 0; i < 5; i++)
    {
        G_fill_rectangle(A[0], A[1], font_width, font_width);
        G_fill_rectangle(B[0], B[1], font_width, font_width);
        A[0] += font_width;
        A[1] -= font_width;
        B[0] -= font_width;
        B[1] -= font_width;
    }

}

void PER(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);

    A[0] = p[0] + (size_tall / 2.0);
    A[1] = p[1] ;
    G_fill_rectangle(A[0], A[1], font_width, font_width);
}

void EXCL(double p[2], double size)
{
    double A[2];
    double font_width = size / 10.0;
    double space = size / 8.0;
    double size_tall = size;
    double horiz = size - (space * 2.0) - (font_width * 2.0);

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

    A[0] = p[0] + space;
    A[1] = p[1] + (size_tall - font_width);
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    A[0] = p[0] + (size_tall - space - font_width);
    A[1] = p[1] + (size_tall / 2.0) - font_width;
    G_fill_rectangle(A[0], A[1], horiz, font_width);

    G_fill_rectangle(A[0], A[1], font_width, size_tall / 2.0);
}


void write_text(double px, double py, char string[1000], double size)
{
    char cur;
    double q[2];
    int len = strlen(string);
    // G_rgb(0, 0, 0);

    q[0] = px;
    q[1] = py;

    for (int i = 0; i < len; i++)
    {
        cur = string[i];

        if (cur == 'A')
        {
            A(q, size);
        }
        if (cur == 'C')
        {
            C(q, size);
        }
        if (cur == 'D')
        {
            D(q, size);
        }
        else if (cur == 'E')
        {
            E(q, size);
        }
        else if (cur == 'F')
        {
            F(q, size);
        }
        else if (cur == 'G')
        {
            G(q, size);
        }
        else if (cur == 'H')
        {
            H(q, size);
        }
        else if (cur == 'I')
        {
            I(q, size);
        }
        else if (cur == 'J')
        {
            J(q, size);
        }
        else if (cur == 'K')
        {
            K(q, size);
        }
        else if (cur == 'L')
        {
            L(q, size);
        }
        else if (cur == 'N')
        {
            Nn(q, size);
        }
        else if (cur == 'M')
        {
            M(q, size);
        }
        else if (cur == 'O')
        {
            O(q, size);
        }
        else if (cur == 'P')
        {
            P(q, size);
        }
        else if (cur == 'R')
        {
            R(q, size);
        }
        else if (cur == 'S')
        {
            S(q, size);
        }
        else if (cur == 'T')
        {
            T(q, size);
        }
        else if (cur == 'U')
        {
            U(q, size);
        }
        else if (cur == 'V')
        {
            V(q, size);
        }
        else if (cur == 'W')
        {
            W(q, size);
        }
        else if (cur == 'X')
        {
            Xx(q, size);
        }
        else if (cur == 'Y')
        {
            Yy(q, size);
        }
        else if (cur == '.')
        {
            PER(q, size);
        }
        else if (cur == '!')
        {
            EXCL(q, size);
        }
        else if (cur == '?')
        {
            QUEST(q, size);
        }

        usleep(200000);
        G_display_image();
        q[0] += size;
    }
}

