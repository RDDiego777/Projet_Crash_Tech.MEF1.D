/* Maillon de la liste chaînée des victimes d'un véhicule */
typedef struct Victim {
    unsigned char age;       /* Âge lors de l'accident : year - birth_year (0 à 255) */
    signed char user_type;   /* 1: conducteur, 2: passager, 3: piéton */
    signed char gender;      /* 1: masculin, 2: féminin, autre */
    signed char severity;    /* 1: indemne, 2: tué, 3: blessé grave, 4: blessé léger */
    struct Victim *next;     /* Pointeur vers la victime suivante du même véhicule */
} Victim;

/* declaration de la fonction */
Victim *add_victim(Victim *head, const Row *row);
