/*
** EPITECH PROJECT, 2020
** .h
** File description:
** .h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *my_putnbr_str(char *str, char *tmp, int nb, int start_index);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_put_nbr(int nb);
char *my_put_nbr_str(int nb);
int my_getnbr(char const *str);
int my_numbercmp(char const *nb1, char const *nb2);
void my_sort_int_array(int *array, int size);
char *my_revstr(char *str);
char *my_strdup(char const *str);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_isneg(int n);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_char_isalpha(char c);
int my_char_isnum(char c);
int my_char_isalphanum(char c);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
void my_swap(int *a, int *b);
int count_int_size(int nb);

int *sort_int_array_next(int *array, int i);
int check_if_sort(int *array, int size);
void capitalize_next(char *str, int i);
int check_if_to_big(char const *str, int i);
int count_word_amount(char * const *tab);
int check_word(char *str, char const *to_find, int i);
int count_word_len(char const *str, int *i);
int count_word_in_str(char const *str);
char **my_malloc_tab(char const *str);
char *my_stricpy(char const *src, int i, int len);

#endif
