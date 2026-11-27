
#ifndef AGE_DATA_H
#define AGE_DATA_H
#include "csv.h"

typedef struct AgeNode {
int age ;
int tab[4][3] ; // ligne i = usertype (0,1,2,3) et colonne j = gender (0,1,2)
struct AgeNode* next ;
}AgeNode ;

void run_age_data(FILE *file);
AgeNode *createAge(int age);
AgeNode *insertAge(AgeNode *head, const Row *row);
int get_age_count(const AgeNode *node,int filter_type, int filter_gender);
void pyramid(AgeNode *head, int filter_type, int filter_gender);

#endif
