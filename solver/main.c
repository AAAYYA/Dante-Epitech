/*
** EPITECH PROJECT, 2023
** Dante's solver
** File description:
** Dante's solver
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "./includes/my.h"

int map_error(char const *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] != 'X' && buffer[i] != '*'
        && buffer[i] != '\n')
            return 0;
        i++;
    }
}

void my_array_to_int_array(dante_t *dante)
{
    int i = 0;
    int j = 0;
    int size = my_strlen(dante->maze[0]);
    dante->temp = malloc(sizeof(int *) * (tablen(dante->maze) + 1));
    while (dante->maze[i] != NULL) {
        j = 0;
        dante->temp[i] = malloc(sizeof(int) * (size + 1));
        while (dante->maze[i][j] != '\0') {
            dante->temp[i][j] = dante->maze[i][j] == '*' ? 0 : 1;
            j++;
        }
        dante->temp[i][j] = -1;
        i++;
    }
    dante->temp[i] = NULL;
}

int opening(char const *filepath, dante_t *dante)
{
    int fd = open(filepath, O_RDONLY);
    if (fd < 2)
        exit(84);
    struct stat st;
    stat(filepath, &st);
    if (st.st_size < 1)
        exit(84);
    char *buffer = malloc(sizeof(char) * (st.st_size + 2));
    int rd = read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\n';
    buffer[st.st_size + 1] = '\0';
    if (map_error(buffer) == 84)
        exit(84);
    dante->maze = my_str_to_array(buffer, '\n', 0);
    my_array_to_int_array(dante);
    free(buffer);
}

int main (int ac, char **av)
{
    if (ac != 2) {
        return 84;
    }
    dante_t *dante = malloc(sizeof(dante_t));
    opening(av[1], dante);
    maze_solving(dante);
    free(dante->end);
    neurolaser(dante->maze);
    ineurolaser(dante->temp);
    ineurolaser(dante->solution);
    free(dante);
    return 0;
}
