#include"age_data.h"

AgeNode *createAge(int age) {
  AgeNode* new =malloc(sizeof(AgeNode)) ;
  if (new==NULL) {
  printf("Erreur d'allocation de mémoire.\n");
  exit(1) ;
  }

new->age =age ;
new->next = NULL ;
 for (int i= 0; i <4 ; i++) {
   for (int j=0 ; j < 3; j++) {
     new->tab[i][j]=0 ;
   }
 }
return new ;
}


AgeNode *findAge(AgeNode *head, int age){
  if(head==NULL){
    return NULL;
  }
  AgeNode* current=head;
  while(current!=NULL){
    if(current->age==age){
      return current;
    }
    current = current->next;
  }
  return NULL;
}
