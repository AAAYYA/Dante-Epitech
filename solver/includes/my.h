/*
** EPITECH PROJECT, 2023
** my h
** File description:
** my
*/

#ifndef MY_H
    #define MY_H

    typedef struct dante_s {
        char **maze;
        int **temp;
        int **solution;
        int *end;
    } dante_t;

    int tablen(char *const *tab);

    int my_strlen(char const *str);

    char **my_str_to_array(char const *str, char delim, int start);

    void neurolaser(char **tab);

    void ineurolaser(int **tab);

    int maze_solving(dante_t *dante);

#endif /* !my */
