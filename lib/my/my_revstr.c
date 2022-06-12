/*
** EPITECH PROJECT, 2020
** my revstr
** File description:
** reverse string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char tmp = ' ';

    for (int i = len - 1, j = 0; i >= j; i--, j++) {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
    }
    return (str);
}
