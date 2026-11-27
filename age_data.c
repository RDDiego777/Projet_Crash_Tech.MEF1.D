#include"age_data.h"

AgeStats *createAge(int age) {
  AgeStats* new =malloc(sizeof(AgeStats)) ;
  if (new==NULL) {
  printf("Erreur d'allocation de mémoire.\n");
  exit(1) ;
  }

new->age =a ge ;
new->next = NULL ;
 for (int i= 0; i <4 ; i++) {
   for (int j=0 ; j < 3; j++) {
     new->counts[i][j]=0 ;
   }
 }
return new ;
}
