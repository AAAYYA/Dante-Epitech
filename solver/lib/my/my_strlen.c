/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** my_strlen
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0' ) {
        i++ ;
    }
    return (i);
}

int tablen(char *const *tab)
{
    int i = 0;
    while (tab[i] != NULL)
        i++;
    return (i);
}
