/*
** EPITECH PROJECT, 2020
** enemies
** File description:
** malloc enemies
*/

#include "../include/my.h"
#include "../include/rpg.h"

int count_enemies_in_map(char *map)
{
    int count = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'E')
            count++;
    }
    return (count);
}

void set_enemies_count_in_scene(data_t *data)
{
    char *file = my_strdup("txt/1.txt");
    char *buf = NULL;

    for (int i = 0; i < 9; i++) {
        file[4] = i + '0' + 1;
        buf = open_read_file(file);
        data->scenes[i].enemy_count = count_enemies_in_map(buf);
    }
}

void set_enemies_pos(data_t *data, int i, char *file)
{
    char *buf = open_read_file(file);
    int enemy_count = 0;
    sfVector2f pos = {0, 0};
    int line = 0;
    int col = 0;
    int setoff = 120;

    for (int k = 0; buf[k] != '\0'
        && enemy_count < data->scenes[i].enemy_count; k++, col++) {
        if (buf[k] == 'E') {
            pos.x = col * setoff;
            pos.y = line * setoff;
            data->scenes[i].enemies[enemy_count++].pos = pos;
        }
        if (buf[k] == '\n') {
            col = 0;
            line++;
            k++;
        }
    }
}

void malloc_enemies_and_set_pos(data_t *data)
{
    int scene_count = 9;
    int count = 0;
    char *file = my_strdup("txt/1.txt");

    set_enemies_count_in_scene(data);
    for (int i = 0; i < scene_count; i++) {
        file[4] = i + '0' + 1;
        count = data->scenes[i].enemy_count;
        data->scenes[i].enemies = malloc(sizeof(enemy_t) * count);
        set_enemies_pos(data, i, file);
    }
}