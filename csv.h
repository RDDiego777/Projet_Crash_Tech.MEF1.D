#ifndef CSV_H
#define CSV_H

#include <stdio.h>

#define NB_COLUMNS 9      /* nombre de colonnes dans le fichier */
#define LINE_SIZE  256    /* taille max d'une ligne             */

/* Une ligne du fichier = une victime d'un accident */
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

/* Lit la ligne suivante du fichier et remplit row.
   Retourne 1 si une ligne a été lue, 0 à la fin du fichier. */
int read_row(FILE *file, Row *row);

#endif
