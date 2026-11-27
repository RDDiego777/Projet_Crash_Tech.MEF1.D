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

AgeNode *insertAge(AgeNode *head, const Row *row) {
  if (row->birth_year <=0) {
    return head ;
  }

int ut = 0 ;
if (row->user_type >= 1 && row->user_type <= 3) {
        ut = row->user_type;
    }

    int g = 0;
    if (row->gender == 1 || row->gender == 2) {
        g = row->gender;
    }

if (head == NULL || age < head->age) {
        AgeNode *new = create_age(age);
        new->tab[u][g]++;
        new->next = head;
        return new;
    }

if (head->age == age) {
        head->tab[u][g]++;
        return head;
   }

AgeNode *current = head;
    while (current->next != NULL && current->next->age < age) {
        current = current->next;
    }

    if (current->next != NULL && current->next->age == age) {
        current->next->tab[ut][g]++;
    } else {
        AgeNode *new_age = create_age(age);
        new_age->tab[ut][g]++;
        new_age->next = current->next;
        current->next = new_age;
    }

    return head;
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
