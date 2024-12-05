#include "../../includes/cub3d.h"

int is_border(char **tab, int i, int j)
{
    int size;
    while(tab[size])
        size++;
    if ((i == size - 1  || tab[i + 1][j] == '\0' || tab[i + 1][j] == '\n') || (!tab[i][j + 1] || tab[i][j + 1] == '\n') || (!tab[i - 1][j] || tab[i - 1][j] == ' ' || i == 0) || (!tab[i][j - 1] || tab[i][j - 1] == ' '))
        return (1);
    return (0);

}