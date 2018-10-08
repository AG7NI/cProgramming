#include <stdio.h>
#include <stdlib.h>
unsigned power (unsigned x, unsigned y);

int main(void){
  if (power(2,0) != 1){
    exit(EXIT_FAILURE);;
  }
  else if (power(2,1) != 2){
    return EXIT_FAILURE;
  }
  else if (power(0,0) != 1){
    return EXIT_FAILURE;
  }
  else if (power(-2,1)!= 4294967294){
    return EXIT_FAILURE;
  }
  else if (power(2,31) != 2147483648){
    return EXIT_FAILURE;
  }
  else if (power(-1,-1) != 4294967295){
    return EXIT_FAILURE;
  }
  else if (power(2,32) != 0){
    return EXIT_FAILURE;
  }
  else{
    return EXIT_SUCCESS;
  }
}
 
