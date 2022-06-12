/*
** EPITECH PROJECT, 2020
** yes
** File description:
** yes
*/

int my_compute_power_rec(int nb, int p)
{
    int res = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    if (p == 1)
        return (nb);
    if (p > 0)
        res = res * my_compute_power_rec(nb, p - 1);
    else
        return (res);
    return (res);
}
