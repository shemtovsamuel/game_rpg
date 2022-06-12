/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** st
*/

#include <stddef.h>
#include <stdio.h>

int check_word(char *str, char const *to_find, int i)
{
    for (int j = 0, k = i; to_find[j] != '\0' && str[k] != '\0'; j++, k++) {
        if (str[k] != to_find[j])
            return (84);
    }
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[0] && check_word(str, to_find, i) == 0) {
            return (&str[i]);
        }
    }
    return (NULL);
}
