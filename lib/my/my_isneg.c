/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** is num neg or pos
*/

#include <unistd.h>

int my_isneg(int n)
{
    if (n < 0) {
        write(1, "N", 1);
    } else {
        write(1, "P", 1);
    }
    write(1, "\n", 1);
    return (0);
}
