/*
** EPITECH PROJECT, 2020
** enemies
** File description:
** setup enemies
*/

#include "../include/my.h"

char *open_read_file(char *filepath)
{
    struct stat info;
    int status = stat(filepath, &info);
    int fd = open(filepath, O_RDONLY);
    char *buff = malloc(sizeof(char) * (info.st_size + 1));
    char tmp = 0;
    int i = 0;

    if (fd < 0 || buff == NULL)
        return (NULL);
    while (read(fd, &tmp, 1) > 0)
        buff[i++] = tmp;
    buff[i] = '\0';
    close(fd);
    return (buff);
}