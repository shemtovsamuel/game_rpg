/*
** EPITECH PROJECT, 2020
** my strupcase
** File description:
** put letters in uppercase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    return (str);
}
