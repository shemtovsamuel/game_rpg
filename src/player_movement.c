/*
** EPITECH PROJECT, 2020
** player movement
** File description:
** manage player movement
*/

#include "../include/my.h"
#include "../include/rpg.h"

static const sfVector2f dir_array[8] = {{0, -1}, {0.8, -0.8}, {1, 0}, {0.8, 0.8}
                                , {0, 1}, {-0.8, 0.8}, {-1, 0}, {-0.8, -0.8}};

void move_player(data_t *data)
{
    float speed = data->player.speed;

    data->player.pos.x += dir_array[data->player.dir].x * speed;
    data->player.pos.y += dir_array[data->player.dir].y * speed;
    sfSprite_setPosition(data->player.sprite, data->player.pos);
}

int check_collision(data_t *data)
{
    sfVector2f pos =  sfSprite_getPosition(data->player.sprite);
    float pre_x = pos.x;
    float pre_y = pos.y;
    float speed = data->player.speed;

    pre_x += 150;
    pre_y += 170;
    pre_x += dir_array[data->player.dir].x * speed;
    pre_y += dir_array[data->player.dir].y * speed;
    pre_x = pre_x * 16 / 1920;
    pre_y = pre_y * 9 / 1080;
    if (data->scenes[data->scene_index].col[(int)pre_y][(int)pre_x] == 1)
        return (0);
    return (data->player_move);
}

void player_movement(data_t *data, clocks_t *clocks)
{
    float move_rate = 0.001;
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clocks->player_move);
    seconds = time.microseconds / 1000000.0;
    data->player_move = check_collision(data);
    if (seconds > move_rate && data->player_move) {
        move_player(data);
        sfClock_restart(clocks->player_move);
    }
}