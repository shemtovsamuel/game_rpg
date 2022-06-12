/*
** EPITECH PROJECT, 2020
** sort int array
** File description:
** sort
*/

int check_if_sort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i+1])
            return (0);
    }
    return (1);
}

int *sort_int_array_next(int *array, int i)
{
    int tmp = 0;

    if (array[i] > array[i + 1]) {
        tmp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = tmp;
    }
    return (array);
}

void my_sort_int_array(int *array, int size)
{
    while (check_if_sort(array, size) == 0) {
        for (int i = 0; i < size - 1; i++) {
            array = sort_int_array_next(array, i);
        }
    }
}
