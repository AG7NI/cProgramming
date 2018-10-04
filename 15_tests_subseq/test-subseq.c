#include <stdio.h>
#include <stdlib.h>
size_t maxSeq(int * array, size_t n);

int main(void){
  int a[] = { 1, 2, 1, 3, 5, 7, 2, 4, 6, 9};
  int b[] = {2, 2};
  int c[] = {-1, 3, 5, 7, 9};
  int d[] = {-4, -3, -2, -1, 0};
  int e[] = {};

  size_t a_size = maxSeq (a, 10); 
  size_t b_size = maxSeq (b, 2);
  size_t c_size = maxSeq (c, 5);
  size_t d_size = maxSeq (d, 5);
  size_t e_size = maxSeq (e, 0);
  //printf( "a=%lu, b=%lu, c=%lu, d=%lu, e=%lu\n",a_size,b_size, c_size, d_size, e_size);
  if (a_size != 4){
    return EXIT_FAILURE;
  }
  if (b_size != 1 ){
    return EXIT_FAILURE;
  }
  if (c_size != 5){
    return EXIT_FAILURE;
  }
  if (d_size != 5){
    return EXIT_FAILURE;
  }
  if (e_size != 0){
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS; 
}
