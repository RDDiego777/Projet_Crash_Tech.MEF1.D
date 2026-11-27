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

void add_accident(YearStats *stats, const Row *row, int *last_year, int *last_collision_id) {
    if (row->year != *last_year || row->collision_id != *last_collision_id) {
    stats->total_accidents++;
        *last_year = row->year ;
        *last_collision_id = row->collision_id ;
    }
}

void display_year_stats(int year, const YearStats *stats) {
    int total_victims = stats->unharmed + stats->killed + stats->serious_injuries + stats->light_injuries;
    
    printf("\n=== Statistiques pour l'annee %d ===\n", year);
    printf("Nombre total d'accidents : %d\n", stats->total_accidents);
    printf("Nombre total de victimes  : %d\n", total_victims);
    printf("  - Indemnes       : %d\n", stats->unharmed);
    printf("  - Tues           : %d\n", stats->killed);
    printf("  - Blesses graves : %d\n", stats->serious_injuries);
    printf("  - Blesses legers : %d\n", stats->light_injuries);
    printf("=====================================\n");
}


void run_year_data(FILE *file){

    Row row;

  YearStats years[NB_YEARS];
  for(int i=0; i<NB_YEARS; i++){
    years[i].total_accidents=0;
    years[i].killed=0;
    years[i].unharmed=0;
    years[i].serious_injuries=0;
    years[i].light_injuries=0;
  }
    while(read_row(file, row)==1){
        if(row.year>=START_YEAR && row.year<=END_YEAR){
            add_victim(&years[row.year - START_YEAR], &row);
        }
    }
int chosen_year = -1;
char c;

    while (chosen_year != 0) {
        printf("\nEntrez une annee entre %d et %d (ou 0 pour quitter) : ", START_YEAR, END_YEAR);

        if (scanf("%d", &chosen_year) != 1) {
            printf("Erreur : veuillez entrer un nombre valide.\n");
            c = getchar();
            while (c != '\n' && c != EOF) {
                c = getchar();
            }
            chosen_year = -1;
        }
        else if (chosen_year == 0) {
            printf("Fin du mode YEAR_DATA.\n");
        }
        else if (chosen_year < START_YEAR || chosen_year > END_YEAR) {
            printf("Annee invalide. Veuillez hoisir entre %d et %d.\n", START_YEAR, END_YEAR);
        }
        else {
            display_year_stats(chosen_year, &years[chosen_year - START_YEAR]);
        }
    }

  
