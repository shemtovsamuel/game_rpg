/*
** EPITECH PROJECT, 2020
** my put nbr str
** File description:
** put number in string
*/

#include <stdlib.h>

int count_int_size(int nb);

char *my_revstr(char *str);

char *my_put_nbr_str(int nb)
{
    int size = count_int_size(nb);
    char *str = malloc(sizeof(char) * (size + 1));
    int i = 0;

    for (i = 0; i < size; i++) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}
