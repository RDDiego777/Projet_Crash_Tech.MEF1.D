#ifndef YEAR_DATA_H
#define YEAR_DATA_H

#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

#define START_YEAR 2005
#define END_YEAR   2024
#define NB_YEARS   20

//Une case du tableau = les statistiques d'une année (20 octets)
typedef struct {
    int total_accidents;
    int unharmed;         //severity == 1 : indemne 
    int killed;           // severity == 2 : tué 
    int serious_injuries; // severity == 3 : blessé grave 
    int light_injuries;   // severity == 4 : blessé léger 
} YearStats;


void add_victim(YearStats *stats, const Row *row);
void add_accident(YearStats *stats, const Row *row, int *last_year, int *last_collision_id)
void display_year_stats(int year, const YearStats *stats);
void run_year_data(FILE *file);

#endif
