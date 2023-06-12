#include "FPToolkit.c"
#include <stdbool.h>

/*

       Y+
       |
       |    * (y,z)
       |  
<------+--------Z+
   D   |
       |
       |


y'    y
- =  ---
D    D+z

H = D*tan(halfangle) ;

with the x-axis perpendicular to this plane.

*/

#define M 700000
double Wsize = 1000  ; // window size ... choose 600 for repl
double X[M],Y[M],Z[M] ;
double Xplot[M],Yplot[M] ;
double Xplot0[M],Yplot0[M] ;
int N = 0 ;


void translate(double dx, double dy, double dz) 
{
  int i ;

  for (i = 0 ; i < N ; i++) {
    X[i] += dx ;
    Y[i] += dy ;
    Z[i] += dz ;    
  }
}



void rotate_x(double degrees)
// Y[] and Z[] will change but X[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*Y[i] - s*Z[i] ;
    Z[i] =  s*Y[i] + c*Z[i] ;
    Y[i] = temp ;
  }
}




void rotate_y(double degrees)
// X[] and Z[] will change but Y[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*X[i] + s*Z[i] ;
    Z[i] = -s*X[i] + c*Z[i] ;
    X[i] = temp ;
  }
}

void expand(double degrees)
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    double n = drand48();
    temp =  c*X[i] + s*Z[i] ;

    if (n < 0.5) // (i % 100 == 0)
    {
      // Z[i] = temp; //-s*X[i] + c*Z[i] ;
      Z[i] -= 0.006 ;
      // X[i] += 0.01 ;
      // Y[i] -= 0.01 ;
      X[i] = temp ;
      // Y[i] = temp ;
    }
    else
    {
      Z[i] += 0.006 ;
      // X[i] -= 0.01 ;
      X[i] = temp ;
      // Y[i] -= 0.001 ;
    }
  }
}

void contract(double degrees)
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    if (i % 100 == 0)
    {
      // temp =  c*X[i] + s*Z[i] ;
      // Z[i] = -s*X[i] + c*Z[i] ;
      // Z[i] += 0.006 ;
      // X[i] -= 0.01 ;
      // X[i] = temp ;
      Y[i] -= 0.05 ;
    }
    // else
    // {
    //   // Z[i] -= 0.006 ;
    //   X[i] += 0.01 ;
    //   // X[i] = temp ;
    //   Y[i] += 0.001 ;
    // }
  }
}

void rotate_y_expand(double degrees)
// X[] and Z[] will change but Y[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*X[i] + s*Z[i] ;
    Z[i] = -s*X[i] + c*Z[i] ;
    X[i] = temp ;
    expand(degrees);
  }
}

void rotate_z(double degrees)
// X[] and Y[] will change but Z[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*X[i] - s*Y[i] ;
    Y[i] =  s*X[i] + c*Y[i] ;
    X[i] = temp ;
  }
}



void project(double observer_distance, double halfangle_degrees, bool original)
{
  double angle_radians, H, scale;

  angle_radians = halfangle_degrees*(M_PI/180.0);
  H = observer_distance*tan(angle_radians);
  scale = (Wsize/2.0)/H;

  if (original)
  {
    for (int i = 0; i < N; i++)
    {
      Xplot0[i] = scale*( (observer_distance*X[i]) / (observer_distance + Z[i]) ) + (Wsize/2.0);
      Yplot0[i] = scale*( (observer_distance*Y[i]) / (observer_distance + Z[i]) ) + (Wsize/2.0);
    }
  }

  else
  {
    for (int i = 0; i < N; i++)
    {
      Xplot[i] = scale*( (observer_distance*X[i]) / (observer_distance + Z[i]) ) + (Wsize/2.0);
      Yplot[i] = scale*( (observer_distance*Y[i]) / (observer_distance + Z[i]) ) + (Wsize/2.0);
    }
  }
}


void draw(bool original)
{
  int i ;

  if (original)
  {
    for (i = 0 ; i < N ; i=i+2) 
    {
      G_rgb(drand48(), drand48(), drand48());
      G_line(Xplot0[i],Yplot0[i],  Xplot0[i+1],Yplot0[i+1]) ;
    }
  }

  else
  {
    for (i = 0 ; i < N ; i=i+2) 
    {
      G_rgb(drand48(), drand48(), drand48());
      G_line(Xplot[i],Yplot[i],  Xplot[i+1],Yplot[i+1]) ;
    }
  }
}


int save_line(double xs, double ys, double zs,
	      double xe, double ye, double ze)
{
  // about to add items at slots N and N+1 :
  if (N+1 >= M) {
    printf("full\n") ;
    return 0 ;
  }
  
  X[N] = xs ; Y[N] = ys ; Z[N] = zs ; N++ ;
  X[N] = xe ; Y[N] = ye ; Z[N] = ze ; N++ ;

  return 1 ;
}

void sierpinski(double p1[3], double p2[3], double p3[3], double depth)
{
    double m1[3], m2[3], m3[3];

    save_line(p1[0], p1[1], p1[2],  p2[0], p2[1], p2[2]);
    save_line(p2[0], p2[1], p2[2],  p3[0], p3[1], p3[2]);
    save_line(p3[0], p3[1], p3[2],  p1[0], p1[1], p1[2]);  

    m1[0] = p1[0] + ((p2[0] - p1[0]) * 0.5);
    m1[1] = p1[1] + ((p2[1] - p1[1]) * 0.5);
    m1[2] = p1[2] + ((p2[2] - p1[2]) * 0.5);

    m2[0] = p2[0] + ((p3[0] - p2[0]) * 0.5);
    m2[1] = p2[1] + ((p3[1] - p2[1]) * 0.5);
    m2[2] = p2[2] + ((p3[2] - p2[2]) * 0.5);

    m3[0] = p1[0] + ((p3[0] - p1[0]) * 0.5);
    m3[1] = p1[1] + ((p3[1] - p1[1]) * 0.5);
    m3[2] = p1[2] + ((p3[2] - p1[2]) * 0.5);

    if (depth > 0)
    {
        sierpinski(p1, m1, m3, depth - 1);
        sierpinski(m1, p2, m2, depth - 1);
        sierpinski(m3, m2, p3, depth - 1);
    }
}

void build_sierpinski_pyramid()
{
  int n,k ;
  double a,x[100],z[100],yv ;

  N = 0 ; // global
  
  n = 4 ;
  for (k = 0; k <= n ; k++) {
    a = k * 2*M_PI/n ; 
    x[k] = cos(a) ;
    z[k] = sin(a) ;
  }

  double depth = 5.0;
  yv = -1 ;
  for (k = 0; k < n ; k++) {
    double p1[3], p2[3], p3[3];
    p1[0] = 0;
    p1[1] = 1;
    p1[2] = 0;

    p2[0] = x[k];
    p2[1] = yv;
    p2[2] = z[k];

    p3[0] = x[k+1];
    p3[1] = yv;
    p3[2] = z[k+1];
    sierpinski(p1, p2, p3, depth);
    save_line(0,1,0,  x[k],yv,z[k]) ;
    save_line(x[k],yv,z[k],    x[k+1],yv,z[k+1]) ;
  }  
  
}

// void test_sierpinski_pyramid()
// {
//   G_init_graphics(Wsize,Wsize) ;
//   G_rgb(0,0,0) ;
//   G_clear() ;
//   G_rgb(0,1,0) ;

//   build_sierpinski_pyramid() ;
//   project(3,45) ;
//   draw() ;
  
//   G_wait_key() ;
// }

void test_sierpinski_pyramid_rotate()
{
  //  G_choose_repl_display() ; // not too bad as a repl movie
  G_init_graphics(Wsize,Wsize) ;

  build_sierpinski_pyramid() ;
  
  while (1) {
    G_rgb(0,0,0) ;
    G_clear() ;
    G_rgb(0,1,0) ;
    project(3,45, false) ;
    draw(false) ;
    rotate_y(2) ;  
    if (G_wait_key() == 'q') { break ; }
    // can have different keys be different axis rotations
  }
}

void test_sierpinski_pyramid_rotate_expand()
{
  //  G_choose_repl_display() ; // not too bad as a repl movie
  G_init_graphics(Wsize,Wsize) ;

  build_sierpinski_pyramid() ;
  project(3,45, true) ;
  draw(true) ;

  for (int i = 0; i < 1000; i++)
  {
    G_rgb(0,0,0) ;
    G_clear();
    if( i % 100 == 0)
    {
      draw(true);
      G_display_image();
      sleep(1);
    }

    else
    {
      expand(2);
      project(3,45, false) ;
      draw(false) ;
      G_display_image();
    }
  }

    int key;
    key = G_wait_key();
  
  // while (1) {
  //   G_rgb(0,0,0) ;
  //   G_clear() ;
  //   G_rgb(0,1,0) ;
  //   // rotate_y_expand(2) ;  
  //   if (G_wait_key() == 'q') { break ; }
  //   else if (G_wait_key() == 'e') 
  //   {  
  //     expand(2);
  //     project(3,45, false) ;
  //     draw(false) ;
  //   }
  //   else if (G_wait_key() == 'c') 
  //   {  
  //     draw(true) ;
  //   }
  // }
}

int main()
{
  //  test_sierpinski_pyramid_rotate() ;
   test_sierpinski_pyramid_rotate_expand() ;
   return 0;
}
