/*
** EPITECH PROJECT, 2020
** my str is alpha
** File description:
** oui
*/

int my_str_isnum(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;
    if (count == 0)
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
    }
    return (1);
}
