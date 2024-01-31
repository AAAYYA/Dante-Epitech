/*
** EPITECH PROJECT, 2023
** generate
** File description:
** main
*/

#include "includes/my.h"
#include <stdlib.h>
#include <string.h>

void prints(maze_t *maze, int i, int j)
{
    if (maze->maze[i][j] == 1)
        my_putchar('X');
    else
        my_putchar('*');
}

void print_maze(maze_t *maze)
{
    int j = 0;
    for (int i = 0; i < maze->ROWS; i++) {
        for (j = 0; j < maze->COLS; j++) {
            prints(maze, i, j);
        }
        if (!(i + 1 == maze->ROWS))
            my_putchar('\n');
    }
}

void test_optimization(maze_t *maze)
{
    while (maze->maze[maze->rands][maze->randss] != 1) {
        maze->rands++;
        if (maze->rands == maze->ROWS) {
            maze->rands = 0;
            maze->randss++;
        }
        if (maze->randss == maze->COLS)
            maze->randss = 0;
    }
}

int test_imperfect(maze_t *maze, int ac, char **av)
{
    maze->rands = rand() % maze->ROWS;
    maze->randss = rand() % maze->COLS;

    if (ac == 3 || strcmp(av[3], "perfect")) {
        maze->maze[maze->rands][maze->randss] = 0;
        test_optimization(maze);
    }
    return 0;
}

int main(int ac, char **av)
{
    maze_t *maze = (maze_t *)malloc(sizeof(maze_t));
    if (maze == NULL)
        return 84;
    if (ac != 3 && ac != 4)
        return 84;
    maze->ROWS = atoi(av[1]);
    maze->COLS = atoi(av[2]);
    maze->maze = (int **)malloc(sizeof(int *) * (maze->ROWS + 1));
    srand(time(NULL));
    init_maze(maze);
    while (maze->maze[maze->ROWS - 1][maze->COLS - 1] == 1) {
        init_maze(maze);
        Cell start = {0, 0};
        generate_maze(start, maze);
    }
    test_imperfect(maze, ac, av);
    print_maze(maze);
    ineurolaser(maze->maze);
    free(maze);
    return 0;
}
