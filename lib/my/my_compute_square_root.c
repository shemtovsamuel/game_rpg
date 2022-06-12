/*
** EPITECH PROJECT, 2020
** compute square root
** File description:
** yes
*/

int my_compute_square_root(int nb)
{
    int res = 0;
    int tmp = 0;

    if (nb <= 0)
        return (0);
    while (res != nb) {
        tmp++;
        res = tmp * tmp;
        if (res > nb)
            return (0);
    }
    return (tmp);
}
