/*
** EPITECH PROJECT, 2020
** my str to word array
** File description:
** put str in word array
*/

#include "../../include/my.h"

int my_show_word_array(char * const *tab);

int count_word_len(char const *str, int *i)
{
    int count = 0;
    int k = *i;

    for (; my_char_isalphanum(str[k]) == 1 && str[k] != '\0'; k++)
        count++;
    *i = k;
    return (count);
}

int count_word_in_str(char const *str)
{
    int count = 0;
    int is_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isalphanum(str[i]) == 0 && is_word == 1) {
            is_word = 0;
        } else if (my_char_isalphanum(str[i]) == 1 && is_word == 0) {
            is_word = 1;
            count++;
        }
    }
    return (count);
}

char **my_malloc_tab(char const *str)
{
    int word_amount = count_word_in_str(str);
    char **tab = malloc(sizeof(char *) * (word_amount + 1));
    int word_len = 0;

    if (tab == NULL)
        return (NULL);
    tab[word_amount] = NULL;
    for (int i = 0, k = 0; k < word_amount; i++, k++) {
        if (my_char_isalphanum(str[i]) == 1) {
            word_len = count_word_len(str, &i);
            tab[k] = malloc(sizeof(char) * (word_len + 1));
        }
    }
    return (tab);
}

char *my_stricpy(char const *src, int i, int len)
{
    char *str = malloc(sizeof(char) * (len + 1));
    int j = 0;

    for (; my_char_isalphanum(src[i]) == 1; i++, j++) {
        str[j] = src[i];
    }
    str[j] = '\0';
    return (str);
}

char **my_str_to_word_array(char const *str)
{
    int word_amount = count_word_in_str(str);
    char **tab = my_malloc_tab(str);
    int word_len = 0;

    for (int i = 0, k = 0, t = 0; k < word_amount; i++) {
        if (my_char_isalphanum(str[i]) == 1) {
            t = i;
            word_len = count_word_len(str, &i);
            tab[k] = my_stricpy(str, t, word_len);
            k++;
        }
    }
    return (tab);
}
