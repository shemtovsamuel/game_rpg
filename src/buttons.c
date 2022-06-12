/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** buttons.c
*/
#include "../include/rpg.h"
#include "../include/my.h"

int check_buttons(sfEvent event, button *button, menu_t *menu)
{
    sfVector2f pos;
    sfVector2f click_pos;
    click_pos.x = event.mouseButton.x;
    click_pos.y = event.mouseButton.y + 26;

    for (int i = 0; button[i].sprite != NULL; i++) {
        if (button_is_clicked(button[i], click_pos)) {
            pos = sfSprite_getPosition(button[i].sprite);
            if (pos.y <= 400) {
                menu->state = 0;
            } else if (pos.y < 500) {
                my_putstr("BOUTON 2");
            } else if (pos.y > 560){
                return (1);
            }
        }
    }
    return (0);
}

int button_is_clicked(button button, sfVector2f click_pos)
{
    sfVector2f button_pos = sfSprite_getPosition(button.sprite);
    sfVector2f button_size = (sfVector2f)
    {button.rect.width, button.rect.height};

    if (click_pos.x >= button_pos.x &&
        click_pos.x <= button_pos.x + button_size.x) {
        if (click_pos.y >= button_pos.y &&
        click_pos.y <= button_pos.y + button_size.y) {
            return (1);
        }
    }
    return (0);
}

void check_hover(sfRenderWindow *window, menu_t *menu, int states)
{
    static int state = 0;
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(window);

    click_pos.y += 26;
    for (int i = 0; menu->buttons[i].sprite != NULL; i++) {
        if (button_is_clicked(menu->buttons[i],
        (sfVector2f){click_pos.x, click_pos.y})
        && state == 0) {
            menu->buttons[i].hidden = 0;
        } else {
            menu->buttons[i].hidden = 1;
        }
    }
    if (states == 0)
        menu->buttons[0].hidden = 0;
    else if (states == 1)
        menu->buttons[1].hidden = 0;
    else if (states == 2)
        menu->buttons[2].hidden = 0;
}

void start_game(int *currentScene)
{
    if (currentScene != NULL)
        *currentScene = 1;
    else
        my_putstr("ERROR: CURRENTSCENE = NULL\n");
}

void init_button(button *button, sfVector2f position
, sfVector2f size, char *path)
{
    button->hidden = 1;
    button->rect.top = 0;
    button->rect.left = 0;
    button->rect.height = size.y;
    button->rect.width = size.x;
    button->image = sfImage_createFromFile(path);
    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromImage(button->image, &button->rect);
    sfTexture_setRepeated(button->texture, sfFalse);
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfVector2f scale = (sfVector2f){1, 1};
    sfSprite_setScale(button->sprite, scale);
    sfSprite_setPosition(button->sprite, position);
    button->callback = &start_game;
}