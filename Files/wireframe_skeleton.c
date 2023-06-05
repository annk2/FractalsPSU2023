#include "FPToolkit.c"

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
int N = 0 ;


int translate(double dx, double dy, double dz) 
{
  int i ;

  for (i = 0 ; i < N ; i++) {
    X[i] += dx ;
    Y[i] += dy ;
    Z[i] += dz ;    
  }
}



int rotate_x(double degrees)
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




int rotate_y(double degrees)
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



int rotate_z(double degrees)
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



int project(double observer_distance, double halfangle_degrees)
{

  // student work goes here
  
}


int draw()
{
  int i ;
  for (i = 0 ; i < N ; i=i+2) {
    G_line(Xplot[i],Yplot[i],  Xplot[i+1],Yplot[i+1]) ;
  }

}



int print_object()
{
  int i ;
  for (i = 0 ; i < N ; i=i+2) {
    printf("(%lf, %lf, %lf)   (%lf, %lf, %lf)\n", 
	   X[i],Y[i],Z[i],  X[i+1],Y[i+1],Z[i+1]) ;
  }

  printf("===============================\n") ;
  
  for (i = 0 ; i < N ; i=i+2) {
    printf("(%lf, %lf)   (%lf, %lf)\n", 
	   Xplot[i],Yplot[i],  Xplot[i+1],Yplot[i+1]) ;
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




int build_pyramid()
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

  yv = -1 ;
  for (k = 0; k < n ; k++) {
    save_line(0,2,0,  x[k],yv,z[k]) ;
    save_line(x[k],yv,z[k],    x[k+1],yv,z[k+1]) ;
  }  
  
}








int test_pyramid()
{
  G_init_graphics(Wsize,Wsize) ;
  G_rgb(0,0,0) ;
  G_clear() ;
  G_rgb(0,1,0) ;

  build_pyramid() ;
  project(3,45) ;
  draw() ;
  print_object() ;
  
  G_wait_key() ;
}




int test_pyramid_rotate()
{
  //  G_choose_repl_display() ; // not too bad as a repl movie
  G_init_graphics(Wsize,Wsize) ;

  build_pyramid() ;
  
  while (1) {
    G_rgb(0,0,0) ;
    G_clear() ;
    G_rgb(0,1,0) ;
    project(3,45) ;
    draw() ;
    rotate_y(2) ;  
    if (G_wait_key() == 'q') { break ; }
  }
  
}




int main()
{
  test_pyramid() ;
  //  test_pyramid_rotate() ;
}
