#include "year_data.h"
#include "crash_data.h"
#include "age_data.h"

#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

int main(){
    FILE *file = NULL;
    char header[200];
    Row row;
    int nb_rows = 0;

    file = fopen("cy_crash_tech_small_sorted.csv", "r");                            //TEST 
    if (file == NULL) {
        printf("Ouverture du fichier impossible\n");
        exit(1);
    }

    fgets(header, 200, file);

    run_age_data(file);
    
    fclose(file);
    return 0;
}
