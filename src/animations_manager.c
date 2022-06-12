/*
** EPITECH PROJECT, 2020
** animations manager
** File description:
** manage animations
*/

#include "../include/my.h"
#include "../include/rpg.h"

void move_anim_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value)
        rect->left += offset;
    else
        rect->left = 0;
}

void play_animation(data_t *data, clocks_t *clocks, struct animation anim)
{
    int offset = 301;
    float refresh_rate = 0.08;
    sfTime anim_time;
    float anim_seconds;

    anim_time = sfClock_getElapsedTime(clocks->player_anim);
    anim_seconds = anim_time.microseconds / 1000000.0;
    if (anim_seconds > refresh_rate * anim.speed) {
        move_anim_rect(&(data->player.rect), offset,
                        data->player.anim.count * offset);
        sfClock_restart(clocks->player_anim);
        if (data->player_attack)
            data->anim_count += 1;
    }
    if (data->player_attack && data->anim_count > data->anims.attack.count) {
        data->player_attack = 0;
        data->anim_count = 0;
    }
}

void player_animation(data_t *data, clocks_t *clocks)
{
    if (data->player_move)
        data->player.anim = data->anims.walk;
    else if (!data->player_move && !data->player_attack)
        data->player.anim = data->anims.idle;
    if (data->player_attack) {
        data->player.anim = data->anims.attack;
    }
    sfSprite_setTexture(data->player.sprite,
                        data->player.anim.tex[data->player.dir], sfTrue);
    sfSprite_setTextureRect(data->player.sprite, data->player.rect);
    play_animation(data, clocks, data->player.anim);
}