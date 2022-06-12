/*
** EPITECH PROJECT, 2020
** my show word array
** File description:
** show word array
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int count_word_amount(char * const *tab)
{
    int count = 0;

    for (int i = 0; tab[i] != NULL; i++)
        count++;
    return (count);
}

int my_show_word_array(char * const *tab)
{
    int tab_size = count_word_amount(tab);

    for (int k = 0; k < tab_size; k++) {
        my_putstr(tab[k]);
        my_putchar('\n');
    }
    return (0);
}
