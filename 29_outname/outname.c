#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  char *outname = malloc((strlen(inputName)+8)*sizeof(*outname));
  strcpy(outname, inputName);
  char extension[8];
  strcpy(extension, ".counts");
  strcat(outname,extension);
  return outname;
}
