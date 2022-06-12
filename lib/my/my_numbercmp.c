/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compare 2 strings
*/

int my_numbercmp(char const *s1, char const *s2)
{
    int value = 0;
    int i = 0;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] < s2[i] && value == 0)
            value = -1;
        else if (s1[i] > s2[i] && value == 0)
            value = 1;
    }
    if (s1[i] == '\0' && s2[i] != '\0')
        return (-1);
    else if (s1[i] != '\0' && s2[i] == '\0')
        return (1);
    return (value);
}
