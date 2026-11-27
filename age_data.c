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

  int age = row->year - row->birth_year;
    if (age < 0 || age > 123) {
        return head;
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
        AgeNode *new = createAge(age);
        new->tab[ut][g]++;
        new->next = head;
        return new;
    }

if (head->age == age) {
        head->tab[ut][g]++;
        return head;
   }

AgeNode *current = head;
    while (current->next != NULL && current->next->age < age) {
        current = current->next;
    }

    if (current->next != NULL && current->next->age == age) {
        current->next->tab[ut][g]++;
    } else {
        AgeNode *new_age = createAge(age);
        new_age->tab[ut][g]++;
        new_age->next = current->next;
        current->next = new_age;
    }

    return head;
}



int get_age_count(const AgeNode *node,int filter_type, int filter_gender) {
    int sum = 0 ;
    for (int ut= 0 ; ut < 4 ; ut++) {
     for (int g=0 ; g<3 ; g++) {
      if (filter_type==0 || filter_type == ut) { // 0 = not filter
       if (filter_gender==0 || filter_gender = ut) {
        sum+= node->tab[ut][g] ;
       }
      }
     }
    }
return sum ;
}



void pyramid(AgeNode *head, int filter_type, int filter_gender){
  int sum=0;
  AgeNode* current=head;
  while(current!=NULL){
    sum=sum+get_age_count(current, filter_type, filter_gender);
    current=current->next;
  }
  if(sum==0){
    printf("Aucune victime pour ce filtre ! \n");
    return;
  }

    float percent;
    int count;

    current = head;
    while (current != NULL) {
        count = get_age_count(current, filter_type, filter_gender);
        percent = count * 100.0 / sum;

        printf("%d ans | ", current->age);
        for (int k = 0; k < (int)(percent * 10); k++) {
            printf("#");
        }
        printf(" %f\n", percent);

        current = current->next;
    }
}



void run_age_data(FILE *file){
  AgeNode *head = NULL;
  Row row;
  while (read_row(file, &row) == 1){
    head = insertAge(head, &row);
  }


int choice = -1 ;
char c ;
while (choice!=0) {
printf("\n--- Menu AGE_DATA ---\n");
        printf("1. Pyramide par genre (Hommes / Femmes)\n");
        printf("2. Pyramide par type d'usager (Conducteur / Passager / Pieton)\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");

      if (scanf("%d", &choice) != 1) {
            printf("Erreur : veuillez entrer un nombre valide.\n");
            c = getchar();
            while (c != '\n' && c != EOF) {
                c = getchar();
            }
            choice = -1;
        }
     else if (choice==0) {
      printf("Fin du mode AGE_DATA.\n") ;
    }
    else if (choice==1 || choice==2) {
      int filter_type = 0; 
      int filter_gender = 0 ;
      printf("Filtrer par type d'usager ? (0 = Tous, 1 = Conducteur, 2 = Passager, 3 = Pieton) : ");
            if (scanf("%d", &filter_type) != 1 || filter_type < 0 || filter_type > 3) {
                filter_type = 0;
                c = getchar();
                while (c != '\n' && c != EOF) {
                    c = getchar();
                }
            }

      printf("Filtrer par genre ? (0 = Tous, 1 = Homme, 2 = Femme) : ");
            if (scanf("%d", &filter_gender) != 1 || filter_gender < 0 || filter_gender > 2) {
                filter_gender = 0;
                c = getchar();
                while (c != '\n' && c != EOF) {
                    c = getchar();
                }
            }
 pyramid(head, filter_type, filter_gender)
}
        else {
            printf("Choix invalide.\n");
        }
    }


