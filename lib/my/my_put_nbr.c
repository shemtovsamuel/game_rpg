/*
** EPITECH PROJECT, 2020
** putnbr base
** File description:
** YES
*/

void *my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb *= -1;
    }
    if (nb < 10)
        my_putchar(48 + nb);
    else {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}
