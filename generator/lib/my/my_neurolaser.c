/*
** EPITECH PROJECT, 2022
** My neurolaser
** File description:
** erase memory
*/

#include <stdlib.h>
#include <stddef.h>

void neurolaser(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}

void ineurolaser(int **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
