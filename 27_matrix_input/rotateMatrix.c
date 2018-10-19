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
  char line[100];
  int n_row = 0;
  char matrix[10][10];
  char *p_matrix=&matrix[0][0];
  while(1){
    char *l = fgets(line, 100, f);
    if (l == NULL && n_row == 10){
      break;
    }
    if (l == NULL && n_row < 10){
	printf("Less row than expected\n");
	fclose(f);
	return EXIT_FAILURE;
    }
    //size_t line_size=strlen(l);
    //printf("the size of line=%lu", line_size);
    char *l_end;
    char *p_line = &line[0];
    l_end = strchr(line, '\n');
    int n= 0;
    while( p_line != l_end){
      //printf("%c", *p_line);
      *p_matrix = *p_line;
      p_line++;
      p_matrix++;
      n++;
    }
    if (n != 10){
      printf("Wrong number of elements in a row\n");
      fclose(f);
      return EXIT_FAILURE;
    }
    if (n_row == 10){
      printf("Too many rows\n");
      fclose(f);
      return EXIT_FAILURE;
    }
    n_row++;
    //printf("elements=%d\n",n);
  }
  rotate(matrix);
  fclose(f);
  return EXIT_SUCCESS;
}
  
      
  
