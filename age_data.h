
#ifndef AGE_DATA_H
#define AGE_DATA_H
#include "crash_tech.h"

typedef struct AgeStats {
int age ;
int counts[4][3] ;
struct AgeStats* next ;
}AgeStats ;

void run_age_data(FILE *file);

#endif
