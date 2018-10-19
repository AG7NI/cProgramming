#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void rotate (char matrix[10][10]){
  char *p = &matrix[0][0];
  char tempMatrix[10][10];
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      tempMatrix[j][9-i]= *p;
      p++;
    }
  }
  for (int k = 0; k < 10; k++){
    for (int l = 0; l <10; l++){
      matrix[k][l]= tempMatrix[k][l];
      printf("%c",matrix[k][l]);
      if (l == 9){
	printf("\n");
      }
    }
  }
}


int main(int argc, char ** argv){
  if (argc != 2){
    fprintf(stderr,"Usage: No File Name\n");
    return EXIT_FAILURE;
  }
  FILE *f=fopen(argv[1],"r");
  if (f == NULL){
    perror("Could not open file\n");
    return EXIT_FAILURE;
  }
  int count = 0;
  char matrix[10][10];
  char *p = &matrix[0][0];
  char line[20];
  int size;
  while (1){
    char *l = fgets(line, 20, f);
    if (l == NULL && count < 100){
      fclose(f);
      printf("not enough element\n");
      return EXIT_FAILURE;
    }
    if (l == NULL && count ==100){
      break;
    }
    size=strlen(line);
    //printf("size of the line=%d\n", size);
    if (size != 11){
      printf("Too many elements\n");
      fclose(f);
      return EXIT_FAILURE;
    }
    else if (line[10] == '\n'){
      for (int i = 0; i<10; i++){
      *p = line[i];
      // printf ("%c",*p);
      p++;
      count++;
      }
      //printf("%c", line[10]);
    }
    else if (line[10] != '\n'){
      printf("Too much elements\n");
      fclose(f);
      return EXIT_FAILURE;
    }
    else if (count > 100){
      printf("Too much elements\n");
      fclose(f);
      return EXIT_FAILURE;
    }
    /*else if (size > 10){
      printf("too much elements");
      fclose(f);
      return EXIT_FAILURE;
    }
    else if (count < 10){
      printf("too much raws");
      fclose(f);
      return EXIT_FAILURE;
      }*/
  }
  rotate(matrix);
  fclose(f);
  return EXIT_SUCCESS;
}
  
      
  
