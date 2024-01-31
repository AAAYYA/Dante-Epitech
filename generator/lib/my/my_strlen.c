/*
** EPITECH PROJECT, 2022
** my strlen
** File description:
** my strlen
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;
    if (str == NULL)
        return 0;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}
