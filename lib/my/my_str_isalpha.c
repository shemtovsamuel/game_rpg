/*
** EPITECH PROJECT, 2020
** my str is alpha
** File description:
** oui
*/

int my_str_isalpha(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;
    if (count == 0)
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z'))
            return (0);
    }
    return (1);
}
