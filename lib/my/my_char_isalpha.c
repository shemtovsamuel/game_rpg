/*
** EPITECH PROJECT, 2020
** my char is alpha
** File description:
** check if a char is a letter
*/

int my_char_isalpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    else
        return (0);
    return (0);
}
