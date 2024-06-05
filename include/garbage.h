/*
** EPITECH PROJECT, 2023
** Standard File
** File description:
** garbage.h
*/

#ifndef GARBAGE
    #define GARBAGE

    #define ALLOC(size) allocat(&alloc_malloc, NULL, size, &free)
    #define CALLOC(size) allocat(&alloc_calloc, NULL, size, &free)
    #define ALLOC_S(p) ((sprite_t *)allocat(&asprite, p, 0, &dsprite))->sprite
    #define ALLOC_SOUND(p) ((sound_t *)allocat(&asound, p, 0, &dsound))->sound
    #define ALLOC_CLOCK ((sfClock *)allocat(&aclock, "-1", 0, &dclock))
    #define DALLOC allocat(NULL, 0, 0, NULL)

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <string.h>

typedef struct allocation {
    void *data_alloc;
    void (*f)(void *);
} allocat_t;

typedef struct garbage {
    allocat_t *data;
    struct garbage *next;
} garbage_t;

typedef struct sprite {
    sfTexture *texture;
    sfSprite *sprite;
} sprite_t;

typedef struct sound {
    sfSoundBuffer *sb;
    sfSound *sound;
} sound_t;

void *allocat(void *(*create)(void *, size_t), void *size1, size_t size2,
    void (*destroy)(void *));

void *alloc_malloc(void *z, size_t size);

void *alloc_calloc(void *z, size_t size);

void *asprite(void *path, size_t z);

void dsprite(void *base);

void *asound(void *path, size_t z);

void dsound(void *base);

void *aclock(void *path, size_t z);

void dclock(void *base);

#endif
