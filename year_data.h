#ifndef YEAR_DATA_H
#define YEAR_DATA_H

#include "projet.h"

#define START_YEAR 2005
#define END_YEAR 2024
#define NB_YEARS 20

/* Statistiques stockées pour UNE année (20 octets par case) */
typedef struct {
    uint32_t total_accidents;
    uint32_t unharmed;         /* severity == 1 : indemne */
    uint32_t killed;           /* severity == 2 : tué */
    uint32_t serious_injuries; /* severity == 3 : blessé grave */
    uint32_t light_injuries;   /* severity == 4 : blessé léger */
} YearStats;



/* Fonction principale appelée par main.c quand le mode est YEAR_DATA */
void run_year_data(FILE *file);

#endif
