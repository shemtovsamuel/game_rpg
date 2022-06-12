/*
** EPITECH PROJECT, 2020
** my find prime sup
** File description:
** yes
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int n_nb = nb;

    while (my_is_prime(n_nb) == 0) {
        n_nb++;
    }
    return (n_nb);
}
