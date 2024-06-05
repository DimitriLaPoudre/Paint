/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** menu_bar_function.c
*/

#include "my.h"

void new_file(global_t *G)
{
    char *tmp = NULL;

    free(G->file_name);
    G->file_name = my_strdup_na(G->pop_up->input);
    tmp = malloc(sizeof(char) * (my_strlen(G->file_name) + 12));
    tmp = my_strcpy(tmp, "My paint - ");
    tmp = my_strcat2(tmp, G->file_name);
    sfRenderWindow_setTitle(G->window, tmp);
    free(tmp);
    if (G->texture != NULL)
        sfTexture_destroy(G->texture);
    G->texture = sfTexture_create(G->size_project.x, G->size_project.y);
    destroy_layer(G);
    G->layer_act = 0;
    create_layer(G);
    G->pop_up->active = 0;
    G->menu_bar_wall_active = -1;
}

void file_new(global_t *G, button_t *button)
{
    pop_up(G, "Enter the name of the new file:", 1, 2, "Create", &new_file,
    "Cancel", &pop_up_cancel);
}

static int bad_extension(global_t *G)
{
    if (!my_strcmp(G->pop_up->input + my_strlen(G->pop_up->input) - 4, ".png"))
        return 0;
    if (!my_strcmp(G->pop_up->input + my_strlen(G->pop_up->input) - 4, ".jpg"))
        return 0;
    if (!my_strcmp(G->pop_up->input + my_strlen(G->pop_up->input) - 4, ".bmp"))
        return 0;
    return 1;
}

static char *filename(global_t *G)
{
    int index = 0;

    for (int i = 0; G->pop_up->input[i] != '\0'; i++)
        if (G->pop_up->input[i] == '/')
            index = i + 1;
    return G->pop_up->input + index;
}

static void open_file2(global_t *G)
{
    if (G->texture != NULL)
        sfTexture_destroy(G->texture);
    G->texture = sfTexture_create(G->size_project.x, G->size_project.y);
    destroy_layer(G);
    G->layer_act = 0;
    create_layer(G);
    sfImage_destroy((*((*(G->layer))->history))->action);
    (*((*(G->layer))->history))->action
    = sfImage_createFromFile(G->pop_up->input);
    sfImage_destroy((*(G->layer))->res);
    (*(G->layer))->res = sfImage_createFromFile(G->pop_up->input);
    G->size_project
    = u_to_2f(sfImage_getSize((*((*(G->layer))->history))->action));
    G->pos_image = (sfVector2f){\
    ((float)G->size_window.x - G->size_project.x) / 2,
    (((float)G->size_window.y - 165) - G->size_project.y) / 2 + 165};
    G->pop_up->active = 0;
    G->menu_bar_wall_active = -1;
}

static void open_file(global_t *G)
{
    char *tmp = NULL;
    struct stat file_s;

    if (bad_extension(G) || stat(G->pop_up->input, &file_s) == -1)
        return pop_up(G,
        "Enter the name of the file to open:\n        File can't be open",
        1, 2, "Open", &open_file, "Cancel", &pop_up_cancel);
    free(G->file_name);
    G->file_name = my_strdup_na(filename(G));
    G->file_name[my_strlen(G->file_name) - 4] = '\0';
    tmp = malloc(sizeof(char) * (my_strlen(G->file_name) + 12));
    tmp = my_strcpy(tmp, "My paint - ");
    tmp = my_strcat2(tmp, G->file_name);
    sfRenderWindow_setTitle(G->window, tmp);
    free(tmp);
    open_file2(G);
}

void file_open(global_t *G, button_t *button)
{
    pop_up(G, "Enter the name of the file to open:", 1, 2, "Open", &open_file,
    "Cancel", &pop_up_cancel);
}

void file_save(global_t *G, button_t *button)
{
    pop_up(G, "Enter the file name:", 1, 4, ".jpg", &pop_up_jpg,
    ".png", &pop_up_png, ".bmp", &pop_up_bmp, "Cancel", &pop_up_cancel);
}

void file_exit(global_t *G, button_t *button)
{
    sfRenderWindow_close(G->window);
}
