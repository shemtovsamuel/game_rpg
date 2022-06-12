/*
** EPITECH PROJECT, 2020
** count int size
** File description:
** count int size
*/

int count_int_size(int nb)
{
    int count = 0;

    while (nb >= 10) {
        nb /= 10;
        count++;
    }
    return (++count);
}
