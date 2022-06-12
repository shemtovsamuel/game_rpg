/*
** EPITECH PROJECT, 2020
** create rpg objects
** File description:
** create objects
*/

#include "../include/my.h"
#include "../include/rpg.h"

void init_clocks(clocks_t *clocks)
{
    clocks->player_move = sfClock_create();
    clocks->player_anim = sfClock_create();
}

void set_player_anim_struct(player_anims *anims)
{
    char *walk_str = my_strdup("img/p_walk_0.png");
    char *idle_str = my_strdup("img/p_idle_0.png");
    char *attack_str = my_strdup("img/p_atk_0.png");

    anims->idle.count = 15;
    anims->idle.speed = 1;
    anims->walk.count = 14;
    anims->walk.speed = 0.3;
    anims->attack.count = 16;
    anims->attack.speed = 0.35;
    for (int i = 0; i < 8; i++) {
        walk_str[11] = i + '0';
        idle_str[11] = i + '0';
        attack_str[10] = i + '0';
        anims->idle.tex[i] = sfTexture_createFromFile(idle_str, NULL);
        anims->walk.tex[i] = sfTexture_createFromFile(walk_str, NULL);
        anims->attack.tex[i] = sfTexture_createFromFile(attack_str, NULL);
    }
}

void create_player(data_t *data)
{
    sfIntRect rect = {0, 0, 240, 301};
    sfVector2f pos = {300, 900};
    float speed = 5;
    sfVector2f scale = {1, 1};

    data->player.sprite = sfSprite_create();
    data->player.rect = rect;
    data->player.pos = pos;
    data->player.speed = speed;
    data->player_move = 0;
    data->player_attack = 0;
    data->player.dir = 4;
    data->player.anim = data->anims.idle;
    sfSprite_setTexture(data->player.sprite, data->player.anim.tex[4], sfTrue);
    sfSprite_setTextureRect(data->player.sprite, rect);
    sfSprite_setPosition(data->player.sprite, data->player.pos);
    sfSprite_setScale(data->player.sprite, scale);
    sfRenderWindow_drawSprite(data->win, data->player.sprite, NULL);
}

void init_game_objects(data_t *data, clocks_t *clocks)
{
    sfVideoMode mode = {1920, 1080, 32};

    data->win = sfRenderWindow_create(mode, "window", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(data->win, 60);
    set_player_anim_struct(&(data->anims));
    create_player(data);
    data->map_pos = (sfVector2f){1, 1};
    init_bg(data);
    load_txts(data);
    init_clocks(clocks);
    init_sound(data);
    setup_enemies(data);
}