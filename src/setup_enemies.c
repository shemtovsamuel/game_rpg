/*
** EPITECH PROJECT, 2020
** enemies
** File description:
** setup enemies
*/

#include "../include/my.h"
#include "../include/rpg.h"

void set_enemies_stats(data_t *data)
{
    float speed = 3;
    int dir = 3;
    float health = 10;
    int dammage = 2;
    int alive = 1;

    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < data->scenes[i].enemy_count; k++) {
            data->scenes[i].enemies[k].alive = alive;
            data->scenes[i].enemies[k].speed = speed;
            data->scenes[i].enemies[k].max_health = health;
            data->scenes[i].enemies[k].current_health = health;
            data->scenes[i].enemies[k].damage = dammage;
            data->scenes[i].enemies[k].dir = dir;
        }
    }
}

void set_sprite_and_texture(data_t *data)
{
    sfIntRect rect = {0, 0, 32, 30};
    sfVector2f scale = {2.5, 2.5};

    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < data->scenes[i].enemy_count; k++) {
            data->scenes[i].enemies[k].sprite = sfSprite_create();
            data->scenes[i].enemies[k].rect = rect;
            data->scenes[i].enemies[k].anim = data->s_anims.idle;
            sfSprite_setTexture(data->scenes[i].enemies[k].sprite,
                data->scenes[i].enemies[k].anim.tex[0], sfTrue);
            sfSprite_setTextureRect(data->scenes[i].enemies[k].sprite, rect);
            sfSprite_setPosition(data->scenes[i].enemies[k].sprite, data->scenes[i].enemies[k].pos);
            sfSprite_setScale(data->scenes[i].enemies[k].sprite, scale);
        }
    }
}

void set_enemies_anim_struct(data_t *data)
{
    char *walk_str = my_strdup("img/s_walk_0.png");
    char *idle_str = my_strdup("img/s_idle_0.png");

    data->s_anims.idle.count = 6;
    data->s_anims.idle.speed = 1;
    data->s_anims.walk.count = 7;
    data->s_anims.walk.speed = 0.3;
    for (int i = 0; i < 2; i++) {
        walk_str[11] = i + '0';
        idle_str[11] = i + '0';
        data->s_anims.idle.tex[i] = sfTexture_createFromFile(idle_str, NULL);
        data->s_anims.walk.tex[i] = sfTexture_createFromFile(walk_str, NULL);
    }
}

void setup_enemies(data_t *data)
{
    malloc_enemies_and_set_pos(data);
    set_enemies_stats(data);
    set_enemies_anim_struct(data);
    set_sprite_and_texture(data);
}