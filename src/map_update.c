/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-clement.schobert
** File description:
** map_update.c
*/

#include "../include/my.h"
#include "../include/rpg.h"

void change_x(data_t *data, int x, int posx)
{
    data->map_pos.x += x;
    data->player.pos.x = posx;
    sfSprite_setPosition(data->player.sprite, data->player.pos);
}

void change_y(data_t *data, int y, int posy)
{
    data->map_pos.y += y;
    data->player.pos.y = posy;
    sfSprite_setPosition(data->player.sprite, data->player.pos);
}

void check_castle_rooms(data_t *data)
{
}

void put_player_castle(data_t *data)
{
    if (data->player.pos.x > 775 && data->player.pos.x < 855) {
        if (data->player.pos.y >= 400 && data->player.pos.y <= 420){
            data->scene_index = 9;
            data->player.pos.y = 800;
            sfSprite_setPosition(data->player.sprite, data->player.pos);
        }
    }
}

void map_check(data_t *data)
{
    if (data->scene_index > 8) {
        check_castle_rooms(data);
        return;
    } else if (data->scene_index == 4)
        put_player_castle(data);
    if (data->player.pos.y < -10 && data->map_pos.y > 0)
        change_y(data, -1, 900);
    if (data->player.pos.y > 950 && data->map_pos.y < 3)
        change_y(data, 1, 0);
    if (data->player.pos.x < -80 && data->map_pos.x > 0)
        change_x(data, -1, 1730);
    if (data->player.pos.x > 1730 && data->map_pos.x < 3)
        change_x(data, 1, -70);
}
