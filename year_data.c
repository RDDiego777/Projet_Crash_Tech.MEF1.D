#include"year_data.h"



  

  












void run_year_data(FILE *file){

  YearStats* years[NB_YEARS-1];
  for(int i=0; i<NB_YEARS-1; i++){
    years->total_accidents=0;
    years->killed=0;
    years->unharmed=0;
    years->serious_injuries=0;
    years->light_injuries=0;
  }

  
