#include <stdlib.h>
#include <stdio.h>

size_t maxSeq (int * array, size_t n){
  int incLength = 1;
  int max = 0;
  if (n == 0){
    //printf("continuous increment length =0\n");
    return 0;
  }
  else if (n == 1){
    //printf("continuous increment length =1\n");
    return 1;
  }
  else{
    for (int i = 1; i < n; i++){
      if (array[i-1] < array[i]){
	incLength += 1;
      }
      else{
	if (incLength > max){
	  max=incLength;
	  incLength = 1; 
	}
	else{
	  incLength = 1;
	}
      }
    }
  }
  if ( max > incLength){
    //printf("continuous increment length =%d\n", max);
    return max;
  }
  else{
    //printf("continuous increment length =%d\n", incLength);
    return incLength;
  }
}
	
	
