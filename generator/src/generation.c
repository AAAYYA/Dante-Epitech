/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-benjamin.buisson
** File description:
** generation
*/

#include "../includes/my.h"

void generate_maze(Cell current, maze_t *maze)
{
    maze->maze[current.row][current.col] = 0;
    while (has_unvisited_neighbor(current, maze)) {
        int randomDirection = get_random_neighbor(current, maze);
        if (randomDirection != -1) {
            Cell next = (Cell) {current.row +
            (randomDirection == SOUTH) - (randomDirection == NORTH),
                current.col + (randomDirection == EAST)
                - (randomDirection == WEST)};
            remove_wall(current, next, maze);
            generate_maze(next, maze);
        }
    }
}
