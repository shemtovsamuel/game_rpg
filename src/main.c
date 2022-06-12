/*
** EPITECH PROJECT, 2020
** main
** File description:
** main rpg
*/

#include "../include/my.h"
#include "../include/rpg.h"

void display_objects(data_t *data)
{
    int x = data->map_pos.x;
    int y = data->map_pos.y;

    if (data->scene_index < 8)
        data->scene_index = s_index(x, y);
    if (data->scenes[data->scene_index].bg != NULL)
        sfRenderWindow_drawSprite(data->win, data->scenes[data->scene_index].bg, NULL);
    for (int i = 0; i < data->scenes[data->scene_index].enemy_count; i++) {
        if (data->scenes[data->scene_index].enemies[i].alive) {
            sfRenderWindow_drawSprite(data->win,
            data->scenes[data->scene_index].enemies[i].sprite, NULL);
        }
    }
    sfRenderWindow_drawSprite(data->win, data->player.sprite, NULL);
}

int game(data_t *data, clocks_t *clocks, sfEvent *event)
{
    display_objects(data);
    while (sfRenderWindow_pollEvent(data->win, event)) {
        if (input_event_manager(data, clocks, *event) == 1)
            return (1);
    }
    map_check(data);
    player_movement(data, clocks);
    player_animation(data, clocks);
    return (0);
}

int main(int ac, char **av, char **env)
{
    sfEvent event;
    clocks_t clocks;
    data_t data;
    int check = 0;

    check = check_error(ac, av, env);
    if (check == 84)
        return (84);
    else if (check == 1)
        return (0);
    init_game_objects(&data, &clocks);
    if (menu(data.win, &event) == 1)
        return (0);
    while (sfRenderWindow_isOpen(data.win)) {
        sfRenderWindow_display(data.win);
        sfRenderWindow_clear(data.win, sfBlack);
        if (game(&data, &clocks, &event) == 1)
            return (0);
    }
    return (0);
}
