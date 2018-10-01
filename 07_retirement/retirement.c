#include <stdlib.h>
#include <stdio.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void retirement (int startAge, double initial, retire_info working, retire_info retired){
  /*startAge: in months, initial: initial saving in dollars, working: info about working, retired: info about being retired*/
  double saving = initial;
  printf("Age %3d month %2d you have $%.2lf\n", startAge/12, startAge%12, initial);
  for (int i = startAge + 1; i <= startAge + working.months; i++){
    saving = saving * (1 + working.rate_of_return) + working.contribution;
    printf("Age %3d month %2d you have $%.2lf\n", i/12, i%12, saving);
  }
  for (int j = startAge + working.months + 1; j< startAge + working.months + retired.months; j++){
    saving = saving *(1 + retired.rate_of_return) + retired.contribution;
    printf( "Age %3d month %2d you have $%.2lf\n", j/12, j%12, saving);
  }
}

int main(void){
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  int start_age = 327;
  double savings = 21345;
  retirement (start_age, savings, working, retired);
  return EXIT_SUCCESS;
}
  
