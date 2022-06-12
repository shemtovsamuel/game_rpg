/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** copy n char from src string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int len = 0;
    int i = 0;

    for (int k = 0; src[k] != '\0'; k++) {
        len++;
    }
    for (; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    if (n >= len)
        dest[i] = '\0';
    return (dest);
}
