/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *str)
{
    int size = my_strlen(str);
    char *new_str = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++)
        new_str[i] = str[i];
    new_str[size] = '\0';
    return (new_str);
}
