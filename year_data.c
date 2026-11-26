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

void display_year_stats(int year, const YearStats *stats) {
    unsigned int total_victims = stats->unharmed + stats->killed + stats->serious_injuries + stats->light_injuries;
    
    printf("\n=== Statistiques pour l'annee %d ===\n", year);
    printf("Nombre total d'accidents : %u\n", stats->total_accidents);
    printf("Nombre total de victimes  : %u\n", total_victims);
    printf("  - Indemnes       : %u\n", stats->unharmed);
    printf("  - Tues           : %u\n", stats->killed);
    printf("  - Blesses graves : %u\n", stats->serious_injuries);
    printf("  - Blesses legers : %u\n", stats->light_injuries);
    printf("=====================================\n");
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

  
