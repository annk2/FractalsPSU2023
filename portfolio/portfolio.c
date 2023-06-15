double swidth = 1000.0;
double sheight = 1000.0;

#include "recursive.c"
#include "lsystem.c"
#include "complex.c"
#include "wireframe.c"

int main()
{
    G_init_graphics(swidth, sheight);

    recursive();
    lsystem();
    ifs();
    complex_num();
    wireframe();
}