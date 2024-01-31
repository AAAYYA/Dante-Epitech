/*
** EPITECH PROJECT, 2023
** my putstr
** File description:
** my putstr
*/

#include <unistd.h>

int my_strlen(char const *str);

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
