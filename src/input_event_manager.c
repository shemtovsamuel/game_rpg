/*
** EPITECH PROJECT, 2020
** rpg input events
** File description:
** gamepad, keyboard and mouse events
*/

#include "../include/rpg.h"
#include "../include/my.h"

void mouse_event(data_t *data, sfEvent event)
{
    int x_click = event.mouseButton.x;
    int y_click = event.mouseButton.y;
}

int keyboard_event(data_t *data, clocks_t *clocks, sfEvent event)
{
    sfIntRect rect = {0, 0, 240, 301};

    if (event.key.code == sfKeyEscape) {
        sfRenderWindow_close(data->win);
        return (1);
    }
    return (0);
}

void set_player_dir(data_t *data, int x, int y, float dead_zone)
{
    if (x < -dead_zone)
        data->player.dir = 6;
    if (x > dead_zone)
        data->player.dir = 2;
    if (y < -dead_zone)
        data->player.dir = 0;
    if (y > dead_zone)
        data->player.dir = 4;
    if (x < -dead_zone && y < -dead_zone)
        data->player.dir = 7;
    if (x < -dead_zone && y > dead_zone)
        data->player.dir = 5;
    if (x > dead_zone && y > dead_zone)
        data->player.dir = 3;
    if (x > dead_zone && y < -dead_zone)
        data->player.dir = 1;
}

void gamepad_event(data_t *data, sfEvent event)
{
    sfIntRect rect = {0, 0, 240, 301};
    int dead_zone = 30;
    float x = sfJoystick_getAxisPosition(0, 0);
    float y = sfJoystick_getAxisPosition(0, 1);

    if ((x > -dead_zone && x < dead_zone && y > -dead_zone && y < dead_zone)
        || data->player_attack)
        data->player_move = 0;
    else {
        set_player_dir(data, x, y, dead_zone);
        data->player_move = 1;
    }
    if (sfJoystick_isButtonPressed(0, 3) == 1 && !(data->player_attack)) {
        data->anim_count = 0;
        data->player.rect = rect;
        data->player_attack = 1;
        data->player_move = 0;
        sfSound_play(data->sounds[e_sword]);
    }
}

int input_event_manager(data_t *data, clocks_t *clocks, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (keyboard_event(data, clocks, event) == 1)
            return (1);
    }
    if (sfJoystick_isConnected(0))
        if (event.type == sfEvtJoystickMoved
            || event.type == sfEvtJoystickButtonPressed)
            gamepad_event(data, event);
    if (event.type == sfEvtMouseButtonPressed)
        mouse_event(data, event);
    if (event.type == sfEvtKeyReleased)
        if (event.key.code == sfKeyUp || event.key.code == sfKeyDown
            || event.key.code == sfKeyLeft || event.key.code == sfKeyRight)
            data->player_move = 0;
    if (event.type == sfEvtClosed) {
        sfRenderWindow_destroy(data->win);
        return (1);
    }
    return (0);
}
