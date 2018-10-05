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
    }
  }
}
