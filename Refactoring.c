#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double a=10, b=100, c=1000, d=10000, e=100000, f=1000000, g=10000000;
int step(){
   double x,y;
   x = (double)rand() / ( RAND_MAX);
   y = (double)rand() / ( RAND_MAX);
   if( x * x + y * y < 1 ) {
      return 1;
   } else {
    return 0;
   }
}
double expToScreen(num) {
  int i;
  double m = 0;
  for( i = 0 ; i < num ; i++ ){
    if( step() == 1 ){
      m++;
    }
  };
  printf("%f\n", m/num*4);
  return 0;
}

int main(void){
    expToScreen(a);
    expToScreen(b);
    expToScreen(c);
    expToScreen(d);
    expToScreen(e);
}           
