/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-clement.schobert
** File description:
** collisions.c
*/

#include "../include/rpg.h"
#include "../include/my.h"

int **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int **grid = NULL;
    int i = 0;

    grid = malloc(sizeof(int *) * nb_rows);
    while (i < nb_rows) {
        grid[i] = malloc(sizeof(int) * nb_cols);
        i++;
    }
    return (grid);
}

int s_index(int x, int y)
{
    int indexes[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

    return (indexes[y][x]);
}

void set_array(int fd, int **grid, int rows, int cols)
{
    char temp = 0;
    int i = 0;
    int j = 0;

    while (read(fd, &temp, 1) != 0) {
        if (temp == 'X') {
            grid[i][j] = 1;
            j++;
        } else if (temp == '*') {
            grid[i][j] = 0;
            j++;
        }
        if (temp == '\n'){
            i++;
            j = 0;
        }
    }
}

int **load_col(int i)
{
    int fd = 0;
    char path[11] = "txt/1.txt";
    int **col = mem_alloc_2d_array(10, 17);

    path[4] = i + 48;
    fd = open(path, O_RDONLY);
    if (fd <= 0)
        return (NULL);
    set_array(fd, col, 9, 16);
    return (col);
}

void load_txts(data_t *data)
{
    for (int i = 0; i < 10; i++) {
        data->scenes[i].col = load_col(i+1);
    }
}