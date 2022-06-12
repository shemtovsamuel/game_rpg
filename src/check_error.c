/*
** EPITECH PROJECT, 2021
** check_error
** File description:
** check_error
*/

#include "../include/my.h"
#include "../include/rpg.h"

void display_helper(void)
{
    my_putstr("MY_RPG\n\n");
    my_putstr("USAGE:\n");
    my_putstr("   ./my_rpg\n");
}

int check_error(int ac, char **av, char **env)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        display_helper();
        return (1);
    }
    return (0);
}
