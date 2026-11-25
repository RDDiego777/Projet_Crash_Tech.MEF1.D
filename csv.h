#ifndef CSV_H
#define CSV_H

#include <stdio.h>  


typedef struct {
    int year;
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
