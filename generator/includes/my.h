/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-benjamin.buisson
** File description:
** my
*/

#ifndef MY_H
    #define MY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>

    typedef struct maze_s {
        int ROWS;
        int COLS;
        int **maze;
        int rands;
        int randss;
    } maze_t;

    typedef struct {
        int row;
        int col;
    } Cell;

    enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

    void init_maze(maze_t *maze);

    int is_valid(Cell c, int last, maze_t *maze);

    int has_unvisited_neighbor(Cell c, maze_t *maze);

    int get_random_neighbor(Cell c, maze_t *maze);

    void remove_wall(Cell c1, Cell c2, maze_t *maze);

    void generate_maze(Cell current, maze_t *maze);

    void print_maze(maze_t *maze);

    void my_putchar(char c);

    void my_putstr(char const *str);

    void my_show_array(char **array, char d);

    int my_strlen(char const *str);

    void generate_maze(Cell current, maze_t *maze);

    void neurolaser(char **tab);

    void ineurolaser(int **tab);

#endif /* !MY_H */
