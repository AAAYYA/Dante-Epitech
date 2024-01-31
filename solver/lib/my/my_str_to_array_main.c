/*
** EPITECH PROJECT, 2022
** My str to word array
** File description:
** str to word array
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int tablen(char *const *tab);

int my_strlen(char const *str);

int delim_count(char const *str, char delim, int index);

int word_len(char const *str, char delim, int index);

int find_last_delim(char const *str, char delim, int index);

char **allocate_tab(char const *str, char delim, int last_delim, int i);

char **first_part_of_tab(char const *str, char delim, int pos[3])
{
    int last_delim = find_last_delim(str, delim, pos[2]);
    char **tab = allocate_tab(str, delim, last_delim, pos[2]);
    while (pos[2] < last_delim) {
        tab[pos[0]] = malloc(sizeof(char) * (word_len(str, delim, pos[2]) + 1));
        pos[1] = 0;
        while (str[pos[2]] != delim) {
            tab[pos[0]][pos[1]] = str[pos[2]];
            pos[2]++, pos[1]++;
        }
        tab[pos[0]][pos[1]] = '\0';
        pos[0]++;
        while (str[pos[2]] == delim)
            pos[2]++;
    }
    return tab;
}

char **create_tab(char const *str, char delim, int start)
{
    int pos[3];
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = str[start] == delim ? start + 1 : start;
    int last_delim = find_last_delim(str, delim, pos[2]);
    char **tab = first_part_of_tab(str, delim, pos);
    if (my_strlen(str) - 1 == last_delim) {
        tab[pos[0]] = NULL;
    } else {
        pos[1] = 0;
        tab[pos[0]] = malloc(sizeof(char) * (word_len(str, '\0', pos[2]) + 1));
        while (str[pos[2]] != '\0') {
            tab[pos[0]][pos[1]] = str[pos[2]];
            pos[2]++, pos[1]++;
        }
        tab[pos[0]][pos[1]] = '\0';
        tab[pos[0] + 1] = NULL;
    }
    return tab;
}

char **my_str_to_array(char const *str, char delim, int start)
{
    while (str[start] == delim) {
        start += 1;
    }
    char **tab = create_tab(str, delim, start);
    return tab;
}
