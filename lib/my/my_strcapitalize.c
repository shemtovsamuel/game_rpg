/*
** EPITECH PROJECT, 2020
** my strcapitalize
** File description:
** capitalize first letter of each word
*/

void capitalize_next(char *str, int i)
{
    char c = str[i - 1];

    if (i == 0)
        str[i] -= 32;
    else if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
        str[i] -= 32;
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            capitalize_next(str, i);
        }
    }
    return (str);
}
