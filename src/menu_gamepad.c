/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-clement.schobert
** File description:
** menu_gamepad.c
*/

#include "../include/rpg.h"
#include "../include/my.h"

int act(int state, menu_t *menu)
{
    switch (state)
    {
        case 0:
            menu->state = 0;
            break;
        case 1:
            my_putstr("SETTINGS BUTTON PRESSED\n");
            break;
        case 2:
            return (1);
            break;
    }
    return (0);
}

int check_gamepad(sfEvent event, menu_t *menu, int *state)
{
    sfIntRect rect = {0, 0, 240, 301};
    int dead_zone = 30;
    float x = sfJoystick_getAxisPosition(0, 0);
    float y = sfJoystick_getAxisPosition(0, 1);

    if (y > 75 && *state < 2)
        *state += 1;
    else if (y < -75 && *state > 0)
        *state -= 1;
    if (sfJoystick_isButtonPressed(0, 0) == 1) {
        act(*state, menu);
    }
}
