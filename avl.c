#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

Victim *add_victim(Victim *head, const Row *row) { // const = constant (seulement lire les infos mais pas les modifier)
    // 1. Allocation dynamique du nouveau maillon victime
    Victim *new_victim = malloc(sizeof(Victim));
    if (new_victim == NULL) {
        fprintf(stderr, "Erreur : echec d'allocation memoire pour une victime.\n");
        exit(EXIT_FAILURE);
    }

// 2. Calcul de l'âge au moment de l'accident (sécurisé)
    if (row->birth_year > 0 && row->year >= row->birth_year) {
        new_victim->age = (unsigned char)(row->year - row->birth_year); // annee actu - date naissance
    } else {
        new_victim->age = 0; // cas où l'année de naissance n'est pas renseignée
    }
// 3. Copie des données depuis la ligne CSV (row)
    new_victim->user_type = row->user_type;
    new_victim->gender    = row->gender;
    new_victim->severity  = row->severity;

    new_victim->next = head;

    return new_victim;
}
