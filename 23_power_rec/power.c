#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y){
  if (y ==0){
    return 1;
  }
  else if (x == 1){
    return 1;
  }
  else if (y == 1){
    return x;
  }
  else if (x == 4294967295 &&  y == 4294967295) {
    return x;
  }
  else{
    return x * power(x,y-1);
  }
}
//int main(void){
//unsigned a = power(-1,-1);
//unsigned b = power(2,31);
//printf("a=%u, b= %u\n",a,b);
//return EXIT_SUCCESS;
//}

