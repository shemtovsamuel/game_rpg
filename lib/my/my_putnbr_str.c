/*
** EPITECH PROJECT, 2020
** my_putnbr_str
** File description:
** put nbr in str at start_index
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_strlen(char const *str);

int count_int_size(int nb);

char *my_putnbr_str(char *str, char *tmp, int nb, int start_index)
{
    int i = start_index + count_int_size(nb) - 1;

    for (int j = 0; j < i; j++)
        tmp[j] = str[j];
    if (nb < 0) {
        tmp[i] = '-';
        nb *= -1;
        i++;
    }
    if (nb < 10) {
        tmp[i] = nb + '0';
    } else {
        tmp = my_putnbr_str(str, tmp, nb / 10, i - 1);
        tmp[i] = nb % 10 + '0';
    }
    return (tmp);
}
