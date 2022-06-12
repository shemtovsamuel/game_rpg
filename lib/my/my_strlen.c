/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** yes
*/

int my_strlen(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        count++;
    }
    return (count);
}
