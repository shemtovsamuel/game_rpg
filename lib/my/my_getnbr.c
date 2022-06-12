/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** yes
*/

int check_if_to_big(char const *str, int i)
{
    int size = 0;
    char *max_int = "2147483647";

    for (int j = i; str[j] >= '0' && str[j] <= '9'; j++)
        size++;
    if (size > 10 || size < 1)
        return (0);
    if (size < 10 && size > 0)
        return (1);
    for (int j = i, k = 0; str[j] >= '0' && str[j] <= '9'; j++, k++) {
        if (str[j] < max_int[k])
            return (1);
        else if (str[j] > max_int[k])
            return (0);
    }
    return (1);
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int mcount = 0;
    int isneg = 1;
    int i = 0;

    for (i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            mcount++;
    }
    if (mcount % 2 != 0)
        isneg *= -1;
    if (check_if_to_big(str, i) == 0)
        return (0);
    for (;str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - '0';
        } else
            return (nb * isneg);
    }
    return (nb * isneg);
}
