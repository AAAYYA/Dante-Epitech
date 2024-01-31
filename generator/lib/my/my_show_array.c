/*
** EPITECH PROJECT, 2023
** my show array
** File description:
** my show array
*/

#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);

void my_putstr(char const *str);

void my_show_array(char **array, char d)
{
    int t_len = 0;
    while (array[t_len] != NULL) {
        t_len++;
    }
    for (int a = 0; a < t_len; a++) {
        my_putstr(array[a]);
        if (a != t_len - 1)
            my_putchar(d);
    }
    my_putchar('\n');
}
