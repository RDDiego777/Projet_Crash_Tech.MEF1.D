#ifndef CSV_H
#define CSV_H

#include <stdio.h>

#define NB_COLUMNS 9      
#define LINE_SIZE  256    


typedef struct {
    short year;
    int collision_id;
    char vehicle_id[16];
    int location;
    int user_type;
    int severity;
    int gender;
    int birth_year;
    int purpose;
} Row;


int read_row(FILE *file, Row *row);

#endif
