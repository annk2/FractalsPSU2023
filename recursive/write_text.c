#include "FPToolkit.c"

void A(double p[2], double size)
{
    double size_width = size / 10.0;
    double space = size / 8.0;
    // options for bold?
    double size_tall = size - (space);

    double A[2];
    A[0] = p[0] + space;
    A[1] = p[1];
    G_fill_rectangle(A[0], A[1], space, size_tall);

    A[0] = p[0] + (size - (space * 2.0));
    G_fill_rectangle(A[0], A[1], space, size_tall);
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

        p[0] += size;
    }
}

