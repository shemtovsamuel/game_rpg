/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** sound.c
*/

#include "../include/rpg.h"

void volume(data_t *data)
{
}

void init_sound(data_t *data)
{
    sfSoundBuffer **sound_buffers;
   
    data->sounds = malloc(sizeof(sfSound *) * e_nb_sounds);
    for (int i = 0; i < e_nb_sounds; i++)
        data->sounds[i] = sfSound_create();

    sound_buffers = malloc(sizeof(sfSoundBuffer *) * e_nb_sounds);
    sound_buffers[e_sword] = sfSoundBuffer_createFromFile("sounds/sword.wav");
    sfSound_setBuffer(data->sounds[e_sword], sound_buffers[e_sword]);
}