#ifndef CSV_H
#define CSV_H

#include <stdio.h>  


typedef struct {
    int annee;
    int collision_id;
    char vehicule_id[16];
    int emplacement;
    int type_usager;
    int gravite;
    int genre;
    int annee_naissance;
    int type_trajet;
} Row;


int read_row(FILE *file, Row *row);

#endif
