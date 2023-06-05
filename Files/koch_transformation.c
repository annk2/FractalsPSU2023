#include "FPToolkit.c"

double bx[5],by[5] ;
double x[5],y[5] ;
int n ;

void print_points()
{
  int k ;

  for(k=0;k<n;k++) {
    printf("x[%d] = %lf  ,  y[%d] = %lf\n",k,x[k],k,y[k]) ;
  }
  
}

void translate(double tx, double ty)
{
  int k ;

  for(k=0;k<n;k++) {
    x[k] = x[k] + tx ;
    y[k] = y[k] + ty ;
  }
  
}

void scale(double sfx, double sfy)
{
  int k ;

  for(k=0;k<n;k++) {
    x[k] = sfx*x[k] ;
    y[k] = sfy*y[k] ;
  }
  
}

void rotate(double a)
{
  int k ;
  double temp ;
  
  for(k=0;k<n;k++) {
    temp = x[k]*cos(a) - y[k]*sin(a) ;
    y[k] = x[k]*sin(a) + y[k]*cos(a) ;
    x[k] = temp ;
  }
  
}

void koch(double sx, double sy, double a, double len, int depth)
{
  int k ;
    
  for(k=0;k<n;k++) {
    x[k] = bx[k] ;
    y[k] = by[k] ;
  }
  //printf("len = %lf\n", len) ;
  scale(len,len) ;
  rotate(a) ;
  translate(sx,sy) ;
  //print_points() ;
  
  if(depth > 1) {
    double nl, da, h ;
    double tx[5],ty[5] ;
      
    nl = len/3.0 ;
    da = M_PI/3.0 ;
    h = sqrt(3)/2.0 ;

    //necessary to have tx, ty be local version of the global x,y for recursion
    for(k=0;k<n;k++) { 
      tx[k] = x[k] ;
      ty[k] = y[k] ;
    }
    
    koch(tx[0],ty[0],a,nl,depth-1) ;
    koch(tx[1],ty[1],a+da,nl,depth-1) ;
    koch(tx[2],ty[2],a-da,nl,depth-1) ;
    koch(tx[3],ty[3],a,nl,depth-1) ;
    
  }
  else if(depth == 1) {
    int k ;
    for(k=0;k<n-1;k++) {
      G_line(x[k],y[k] , x[k+1],y[k+1]) ;
    }
        
  }
  
}


int main()
{
  
  double scalex , scaley ;
  double swidth , sheight ;
  double sx, sy, angle, length ;
  int k,depth ;

  // make base, unit curve from origin using globals
  
  n = 5 ;
  bx[0] = 0 ;           by[0] = 0 ;
  bx[1] = 1.0/3 ;       by[1] = 0 ;
  bx[2] = 0.5 ;         by[2]= 1.0/3 * sqrt(3)/2.0 ;
  bx[3] = 2.0/3 ;       by[3] = 0 ;
  bx[4] = 1 ;           by[4] = 0 ;
  ///////////////////////////////////////////////////

  printf("Provide a fractal depth >= 1 :") ;
  scanf("%d", &depth) ;

  swidth = 800 ;   sheight = 800 ;
  G_init_graphics(swidth,sheight) ;

  /*
  // testing 
  scalex = 800 ; scaley = 800 ;
  scale(scalex,scaley) ;
  
  for(k=0;k<n-1;k++) {
    G_line(x[k],y[k] , x[k+1],y[k+1]) ;
  } 

  G_wait_key() ;
  /////////////////////
  */

  sx = 10 ;
  sy = 10 ;
  angle = 0 ;
  length = swidth - 2*sx ;
    
  koch(sx,sy,angle,length,depth) ;

  G_wait_key() ;

  
}
