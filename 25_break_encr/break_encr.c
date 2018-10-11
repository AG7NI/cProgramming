#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int breakEncry (FILE *f){
  int c;
  int alpha[26]= {0};
  while ((c = fgetc(f)) != EOF) {        
    if (isalpha(c)) {            
      c = tolower(c);
      c -= 'a';
      // printf("%d\n",c);
      alpha[c]+= 1;
    }   
  }
  int maxFreq = 0;
  int e_index = 27;
  for (int i = 0; i < 26; i++){
    if (alpha[i] > maxFreq){
      maxFreq=alpha[i];
      e_index = i;
    }
    //printf("%d ", alpha[i]);
  }
  return e_index;
}
int main (int argc, char **argv){
  if (argc != 2){
    fprintf(stderr,"Usage: encrypt key inputFileName\n");    
    return EXIT_FAILURE;
  }
  FILE *f = fopen(argv[1], "r");
  if (f == NULL) {    
    perror("Could not open file");    
    return EXIT_FAILURE;  
  }  
  int e_pos = breakEncry(f);
  if (e_pos == 27){
    perror("The txt file does not contain letters");
    return EXIT_FAILURE;
  }
  //printf("max=%d\n",e_pos);
  e_pos -= 4;
  if (e_pos < 0){
    e_pos += 26;
  }
  printf("%d\n", e_pos);
  if (fclose(f) != 0) {    
    perror("Failed to close the input file!");    
    return EXIT_FAILURE;  
  }  
  return EXIT_SUCCESS;
}
  
