/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** menu.c
*/

#include "../include/rpg.h"

int menu_events(sfRenderWindow *window, sfEvent event, menu_t *menu)
{
    static int state = 0;

    check_hover(window, menu, state);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (1);
        }
    }
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == sfMouseLeft)
            if (check_buttons(event, menu->buttons, menu) == 1)
                return (1);
    }
    if (event.type == sfEvtJoystickMoved
    || event.type == sfEvtJoystickButtonPressed)
        if (check_gamepad(event, menu, &state) == 1)
            return (1);
    return (0);
}

sfSprite *create_sprite(char *path, sfIntRect rect
, sfVector2f scale, sfVector2f pos)
{
    sfTexture *bg = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, bg, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfVector2f size = (sfVector2f){579, 72};

    menu->state = 1;
    menu->hover = create_sprite("img/menu/hover.png",
        (sfIntRect){0, 0, 200, 75}, (sfVector2f){1, 1},
        (sfVector2f){1920, 1080});
    menu->bg = create_sprite("img/menu/bg.png", (sfIntRect){0, 0, 1920, 1080},
        (sfVector2f){1, 1}, (sfVector2f){0, 0});
    menu->buttons = malloc(sizeof(button) * 5);
    init_button(&(menu->buttons[0])
    , (sfVector2f){618, 260}, (sfVector2f){676, 72}, "img/menu/play.png");
    init_button(&(menu->buttons[1])
    , (sfVector2f){547, 414}, (sfVector2f){820, 72}, "img/menu/start.png");
    init_button(&(menu->buttons[2])
    , (sfVector2f){664, 568}, size, "img/menu/quit.png");
    menu->buttons[3].sprite = NULL;
    return (menu);
}

void display_menu(menu_t *menu, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, menu->bg, NULL);
    sfRenderWindow_drawSprite(win, menu->hover, NULL);
    for (int i = 0; menu->buttons[i].sprite != NULL; i++)
        if (menu->buttons[i].hidden == 0)
        sfRenderWindow_drawSprite(win, menu->buttons[i].sprite, NULL);
}

int menu(sfRenderWindow *window, sfEvent *event)
{
    menu_t *menu = init_menu();

    while (menu->state == 1) {
        if (menu_events(window, *event, menu) == 1)
            return (1);
        display_menu(menu, window);
        sfRenderWindow_display(window);
    }
    free(menu->buttons);
    free(menu);
    return (0);
}
