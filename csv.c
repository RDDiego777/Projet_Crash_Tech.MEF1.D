#include <stdio.h>
#include "csv.h"

int read_row(FILE *file, Row *row)
{
    char line[256];

    /* On lit le fichier ligne par ligne */
    while (fgets(line, 256, file) != NULL) {

        /* sscanf découpe la ligne et range chaque colonne dans row.
           Il renvoie le nombre de colonnes qu'il a réussi à lire. */
        int nb = sscanf(line, "%hd;%u;%15[^;];%hhd;%hhd;%hhd;%hhd;%hd;%hhd",
                &row->year, &row->collision_id, row->vehicle_id,
                &row->location, &row->user_type, &row->severity,
                &row->gender, &row->birth_year, &row->purpose);

        /* Les 9 colonnes ont été lues : la ligne est bonne */
        if (nb == 9) {
            return 1;
        }

        /* Sinon (en-tête, ligne vide ou incomplète) : on passe à la suivante */
    }

    return 0; /* fin du fichier */
}
