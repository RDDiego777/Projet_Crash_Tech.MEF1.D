#include <stdio.h>
#include "csv.h"

int read_row(FILE *file, Row *row){
    int c, i;
    int nb_read;

    if (fscanf(file, "%d;%d;", &row->year, &row->collision_id) != 2) {
        return 0;
    }

    i = 0;
    c = fgetc(file);
    while (c != ';' && c != EOF && i < 15) {
        row->vehicle_id[i] = c;
        i++;
        c = fgetc(file);
    }
    row->vehicle_id[i] = '\0';

    nb_read = fscanf(file, "%d;%d;%d;%d;%d;%d", &row->location, &row->user_type, &row->severity, &row->gender, &row->birth_year, &row->purpose);
    if (nb_read != 6) {
        return 0;
    }

    return 1;
}
