#include"year_data.h"
void add_victim(YearStats *stats, const Row *row) { // constante (lecture seule pas de modif)
    switch (row->severity) {
        case 1:
            stats->unharmed++;       
            break;
        case 2:
            stats->killed++;        
            break;
        case 3:
            stats->serious_injuries++; 
            break;
        case 4:
            stats->light_injuries++; 
            break;
        default:
            break;
    }
}




  

  












void run_year_data(FILE *file){

  YearStats* years[NB_YEARS-1];
  for(int i=0; i<NB_YEARS-1; i++){
    years->total_accidents=0;
    years->killed=0;
    years->unharmed=0;
    years->serious_injuries=0;
    years->light_injuries=0;
  }

  
