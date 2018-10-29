#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) { 
 qsort(data, count, sizeof(char *), stringOrder);
}

int main(int argc, char ** argv) {
  char ** lines = NULL;
  char * curr = NULL;
  size_t sz;
  size_t i = 0;
  if (argc == 1){
    while (getline(&curr, &sz, stdin) >= 0){
      lines = realloc(lines, (i+1)*sizeof(*lines));
      lines[i]= curr; 
      curr = NULL;
      i++;
    }
    free(curr);
    sortData(lines, i);
    for (size_t j = 0; j < i; j++){
      printf("%s", lines[j]);
      free(lines[j]);
    }
    free(lines);
  }
  else if (argc > 1){
    int nFiles = argc - 1;
    for (int k = 0; k < nFiles; k++){
      FILE *f = fopen(argv[k+1], "r");
      if (f == NULL){
	perror("Could not open file");
	for (size_t j=0; j<i; j++){
	  free(lines[j]);
	}
	free(lines);
	return EXIT_FAILURE;
      }
      curr = NULL;
      while (getline(&curr, &sz, f) >= 0){
	lines = realloc(lines, (i+1)*sizeof(*lines));
	lines[i]= curr;
	curr = NULL;
	i++;
      }
      free(curr);
      if (fclose(f)!=0){
	perror ("Failed to close the input file!");
	return EXIT_FAILURE;
      }
    }
    sortData(lines, i);
    for (size_t j = 0; j < i; j++){
      printf("%s", lines[j]);
      free(lines[j]);
    }
    free(lines);
  }
  return EXIT_SUCCESS;
}
  
