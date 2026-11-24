#ifndef CSV_H
#define CSV_H

#include <stdio.h>

#define NB_COLUMNS 9      
#define LINE_SIZE  256    


typedef struct {
    short year;
    unsigned int collision_id;
    char vehicle_id[16];
    signed char location;
    signed char user_type;
    signed char severity;
    signed char gender;
    short birth_year;
    signed char purpose;
} Row;


int read_row(FILE *file, Row *row);

#endif
