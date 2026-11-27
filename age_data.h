
#ifndef AGE_DATA_H
#define AGE_DATA_H
#include "crash_tech.h"

typedef struct AgeNode {
int age ;
int tab[4][3] ; // ligne i = usertype (0,1,2,3) et colonne j = gender (0,1,2)
struct AgeStats* next ;
}AgeNode ;

void run_age_data(FILE *file);

#endif
