/*
** EPITECH PROJECT, 2023
** second str to arraay
** File description:
** secondary functions for str to array
*/

#include <stdlib.h>

int my_strlen(char const *str);

int word_len(char const *str, char delim, int index)
{
    int j = 0;
    while (str[index] != delim) {
        index++, j++;
    }
    return j;
}

int find_last_delim(char const *str, char delim, int index)
{
    int pos = 0;
    while (str[index] != '\0') {
        if (str[index] == delim)
            pos = index;
        index++;
    }
    return pos;
}

int delim_count(char const *str, char delim, int index)
{
    int compteur = 0;
    for (int i = index; str[i] != '\0'; i++)
        if (str[i] == delim)
            compteur++;
    return compteur;
}

char **allocate_tab(char const *str, char delim, int last_delim, int i)
{
    int m_value = delim_count(str, delim, i);
    m_value += (my_strlen(str) - 1 == last_delim ? 1 : 2);
    char **tab = malloc(sizeof(char *) * m_value);
    return tab;
}
