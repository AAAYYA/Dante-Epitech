/*
** EPITECH PROJECT, 2023
** maze solving
** File description:
** maze solving
*/

#include <stdio.h>
#include <stdlib.h>
#include "../includes/my.h"

void create_solution(dante_t *dante)
{
    if (dante->maze[0][0] == 'X'
    || dante->maze[dante->end[0] - 1][dante->end[1] - 1] == 'X') {
        printf("no solution found\n");
        exit(0);
    }

    int i = 0;
    dante->solution = malloc(sizeof(int *) * (dante->end[0] + 1));
    for (; i < dante->end[0]; i++) {
        dante->solution[i] = malloc(sizeof(int) * (dante->end[1]));
        for (int j = 0; j < dante->end[1]; j++) {
            dante->solution[i][j] = 0;
        }
    }
    dante->solution[i] = NULL;
}

int find_path(int x, int y, dante_t *dante)
{
    if (x == dante->end[0] - 1 && y == dante->end[1] - 1) {
        dante->solution[x][y] = 1;
        return 1;
    }
    if (x < 0 || y < 0 || x >= dante->end[0] || y >= dante->end[1]
    || dante->temp[x][y] == 1 || dante->solution[x][y] == 1)
        return 0;
    dante->solution[x][y] = 1;
    if (find_path(x + 1, y, dante) == 1)
        return 1;
    if (find_path(x, y + 1, dante) == 1)
        return 1;
    if (find_path(x - 1, y, dante) == 1)
        return 1;
    if (find_path(x, y - 1, dante) == 1)
        return 1;
    dante->solution[x][y] = 0;
    return 0;
}

void fill_temp(int x, dante_t * dante)
{
    for (int y = 0; y < dante->end[1]; y++) {
        if (dante->solution[x][y] == 1)
            dante->temp[x][y] = 2;
    }
}

void print_solved_maze(int i, dante_t * dante)
{
    for (int j = 0; j < dante->end[1]; j++) {
        if (dante->temp[i][j] == 0)
            printf("*");
        if (dante->temp[i][j] == 1)
            printf("X");
        if (dante->temp[i][j] == 2)
            printf("o");
    }
    if (i < dante->end[0] - 1)
        printf("\n");
}

int maze_solving(dante_t *dante)
{
    dante->end = malloc(sizeof(int) * 2);
    dante->end[0] = tablen(dante->maze);
    dante->end[1] = my_strlen(dante->maze[0]);
    create_solution(dante);

    if (find_path(0, 0, dante) == 1) {
        for (int x = 0; x < dante->end[0]; x++) {
            fill_temp(x, dante);
        }
        for (int i = 0; i < dante->end[0]; i++) {
            print_solved_maze(i, dante);
        }
    } else {
        printf("no solution found.\n");
    }
    return 0;
}
