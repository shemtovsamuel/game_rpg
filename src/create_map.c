/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-clement.schobert
** File description:
** create_map.c
*/

#include "../include/my.h"
#include "../include/rpg.h"

void init_bg_sprites(data_t *data)
{
    data->scene_index = 4;
    for (int i = 0; i < 13; i++) {
        data->scenes[i].bg = sfSprite_create();
    }
}

void init_textures_bis(data_t *data)
{
    sfTexture *hall = sfTexture_createFromFile("img/rooms/Salle1.png", NULL);
    sfTexture *left =
    sfTexture_createFromFile("img/rooms/dark_salle.png", NULL);
    sfTexture *right =
    sfTexture_createFromFile("img/rooms/dark_salle.png", NULL);
    sfTexture *up = sfTexture_createFromFile("img/rooms/Salle2.png", NULL);

    sfSprite_setTexture(data->scenes[9].bg, hall, sfTrue);
    sfSprite_setPosition(data->scenes[9].bg, (sfVector2f){0, 0});
    sfSprite_setTexture(data->scenes[10].bg, left, sfTrue);
    sfSprite_setPosition(data->scenes[10].bg, (sfVector2f){0, 0});
    sfSprite_setTexture(data->scenes[11].bg, right, sfTrue);
    sfSprite_setPosition(data->scenes[11].bg, (sfVector2f){0, 0});
    sfSprite_setTexture(data->scenes[12].bg, up, sfTrue);
    sfSprite_setPosition(data->scenes[12].bg, (sfVector2f){0, 0});
}

void init_textures(data_t *data)
{
    sfTexture *halltex = sfTexture_createFromFile("img/Outdoor/5.png", NULL);
    sfTexture *up = sfTexture_createFromFile("img/Outdoor/2.png", NULL);
    sfTexture *dow = sfTexture_createFromFile("img/Outdoor/8.png", NULL);
    sfTexture *lefttex = sfTexture_createFromFile("img/Outdoor/4.png", NULL);
    sfTexture *upl = sfTexture_createFromFile("img/Outdoor/1.png", NULL);
    sfTexture *upr = sfTexture_createFromFile("img/Outdoor/3.png", NULL);

    sfSprite_setTexture(data->scenes[4].bg, halltex, sfTrue);
    sfSprite_setPosition(data->scenes[4].bg, (sfVector2f){0, 0});
    sfSprite_setTexture(data->scenes[1].bg, up, sfTrue);
    sfSprite_setPosition(data->scenes[1].bg, (sfVector2f){0, 0});
    sfSprite_setTexture(data->scenes[7].bg, dow, sfTrue);
    sfSprite_setPosition(data->scenes[7].bg, (sfVector2f){0, 0});
    sfSprite_setTexture(data->scenes[3].bg, lefttex, sfTrue);
    sfSprite_setPosition(data->scenes[3].bg, (sfVector2f){0, 0});
    sfSprite_setTexture(data->scenes[0].bg, upl, sfTrue);
    sfSprite_setPosition(data->scenes[0].bg, (sfVector2f){0, 0});
    sfSprite_setTexture(data->scenes[2].bg, upr, sfTrue);
    sfSprite_setPosition(data->scenes[2].bg, (sfVector2f){0, 0});
    init_textures_bis(data);
}

void init_bg(data_t *data)
{
    sfTexture *r = sfTexture_createFromFile("img/Outdoor/6.png", NULL);
    sfTexture *downleft = sfTexture_createFromFile("img/Outdoor/7.png", NULL);
    sfTexture *downr = sfTexture_createFromFile("img/Outdoor/9.png", NULL);

    init_bg_sprites(data);
    init_textures(data);
    sfSprite_setTexture(data->scenes[5].bg, r, sfTrue);
    sfSprite_setPosition(data->scenes[5].bg, (sfVector2f){0, 0});
    sfSprite_setTexture(data->scenes[6].bg, downleft, sfTrue);
    sfSprite_setPosition(data->scenes[6].bg, (sfVector2f){0, 0});
    sfSprite_setTexture(data->scenes[8].bg, downr, sfTrue);
    sfSprite_setPosition(data->scenes[8].bg, (sfVector2f){0, 0});
}
