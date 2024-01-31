/*
** EPITECH PROJECT, 2023
** generate
** File description:
** maze
*/

#include "../includes/my.h"

void init_maze(maze_t *maze)
{
    int i = 0;
    for (i = 0; i < maze->ROWS; i++) {
        maze->maze[i] = (int *)malloc(sizeof(int) * (maze->COLS));
        for (int j = 0; j < maze->COLS; j++) {
            maze->maze[i][j] = 1;
        }
    }
    maze->maze[i] = NULL;
}

int is_valid(Cell c, int last, maze_t *maze)
{
    return c.row >= 0 && c.row < maze->ROWS
    && c.col >= 0 && c.col < maze->COLS
    && maze->maze[c.row][c.col]
    && (last == NORTH || c.row == 0 || maze->maze[c.row - 1][c.col]) &&
    (last == SOUTH || c.row == maze->ROWS - 1 || maze->maze[c.row + 1][c.col])
    && (last == EAST || c.col == maze->COLS - 1 || maze->maze[c.row][c.col + 1])
    && (last == WEST || c.col == 0 || maze->maze[c.row][c.col - 1]);
}

int has_unvisited_neighbor(Cell c, maze_t *maze)
{
    int row = c.row;
    int col = c.col;
    Cell neighbors[4] = {{row - 1, col}, {row, col + 1},
    {row + 1, col}, {row, col - 1}};
    for (int i = 0; i < 4; i++) {
        if (is_valid(neighbors[i], (2 + i) % 4, maze)) {
            return 1;
        }
    }
    return 0;
}

int get_random_neighbor(Cell c, maze_t *maze)
{
    int row = c.row;
    int col = c.col;
    Cell neighbors[4] = {{row - 1, col}, {row, col + 1},
    {row + 1, col}, {row, col - 1}};
    int indices[4] = {0, 1, 2, 3};
    int tmp, randIndex, numIndices = 4;
    while (numIndices) {
        randIndex = rand() % numIndices;
        tmp = indices[randIndex];
        indices[randIndex] = indices[numIndices - 1];
        indices[numIndices - 1] = tmp;
        numIndices--;
        if (is_valid(neighbors[tmp], (2 + tmp) % 4, maze)) {
            return tmp;
        }
    }
    return -1;
}

void remove_wall(Cell c1, Cell c2, maze_t *maze)
{
    int row1 = c1.row;
    int col1 = c1.col;
    int row2 = c2.row;
    int col2 = c2.col;
    if (row1 == row2) {
        if (col1 < col2) {
            maze->maze[row1][col1 + 1] = 0;
        } else {
            maze->maze[row1][col1 - 1] = 0;
        }
    } else {
        if (row1 < row2) {
            maze->maze[row1 + 1][col1] = 0;
        } else {
            maze->maze[row1 - 1][col1] = 0;
        }
    }
}
