/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** menu_bar.c
*/

#include "my.h"

static button_t *create_wall2(button_t *new, va_list *list, int id)
{
    new->id = id;
    new->text = my_strdup(va_arg(*list, char *));
    new->function = va_arg(*list, void (*)(global_t *, button_t *));
    new->next = NULL;
    return new;
}

static button_t **create_wall(int ac, va_list *list, int *width)
{
    button_t **wall = CALLOC(sizeof(button_t *));
    button_t *tmp = NULL;
    button_t *new = NULL;
    int id = 0;

    for (int i = 0; i < ac; i++) {
        tmp = *wall;
        new = create_wall2(ALLOC(sizeof(button_t)), list, id);
        id++;
        if (my_strlen(new->text) > *width)
            *width = my_strlen(new->text);
        if (tmp == NULL) {
            *wall = new;
            continue;
        }
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new;
    }
    return wall;
}

static void create_new_menu_bar(menu_bar_t **mb, char *name, int ac, ...)
{
    static int id = 0;
    menu_bar_t *new = ALLOC(sizeof(menu_bar_t));
    menu_bar_t *tmp = *mb;
    va_list list;

    va_start(list, ac);
    new->id = id;
    new->name = my_strdup(name);
    new->wall_size = ac;
    new->width = 0;
    new->wall = create_wall(ac, &list, &new->width);
    new->width = 6 + new->width * 9 + 20;
    new->next = NULL;
    id++;
    va_end(list);
    for (; tmp != NULL && tmp->next != NULL; tmp = tmp->next);
    if (tmp == NULL)
        *mb = new;
    else
        tmp->next = new;
}

menu_bar_t **create_menu_bar(void)
{
    menu_bar_t **mb = CALLOC(sizeof(menu_bar_t *));

    create_new_menu_bar(mb, "File", 4, "New file", &file_new,
    "Open file", &file_open, "Save", &file_save, "Exit", &file_exit);
    create_new_menu_bar(mb, "Edit", 5, "Undo", &edit_undo, "Redo", &edit_redo,
    "Pencil", &edit_pencil, "Eraser", &edit_eraser,
    "Rectangle Shape", &edit_rectangle);
    create_new_menu_bar(mb, "Help", 1, "About", &help_about);
    return mb;
}

static void set_color_wall(global_t *G, button_t *wall_act)
{
    if (wall_act->id == G->menu_bar_wall_active) {
        sfRectangleShape_setFillColor(G->shape_r, sfBlue);
        sfText_setFillColor(G->text, sfWhite);
    } else {
        sfRectangleShape_setFillColor(G->shape_r, sfWhite);
        sfText_setFillColor(G->text, sfBlack);
    }
}

static void display_wall2(global_t *G, float offset, float offset2,
    button_t *tmp)
{
    set_color_wall(G, tmp);
    sfRectangleShape_setPosition(G->shape_r,
    (sfVector2f){RATIO_X(offset), RATIO_Y(offset2)});
    sfRenderWindow_drawRectangleShape(G->window, G->shape_r, NULL);
    sfText_setString(G->text, tmp->text);
    sfText_setPosition(G->text,
    (sfVector2f){RATIO_X((offset + 6)), RATIO_Y((offset2 + 5))});
    sfRenderWindow_drawText(G->window, G->text, NULL);
}

void display_wall(global_t *G, button_t **wall, int offset, menu_bar_t
    *menu_act)
{
    float offset2 = 25;

    sfRectangleShape_setPosition(G->shape_r, (sfVector2f){RATIO_X(offset), 0});
    sfText_setScale(G->text, (sfVector2f){1, 1});
    sfRectangleShape_setSize(G->shape_r,
    (sfVector2f){RATIO_X((sfText_getGlobalBounds(G->text).width + 15)),
    RATIO_Y(25)});
    sfText_setScale(G->text, (sfVector2f){RATIO_X(1), RATIO_Y(1)});
    sfRectangleShape_setFillColor(G->shape_r, (sfColor){100, 100, 100, 255});
    sfRenderWindow_drawRectangleShape(G->window, G->shape_r, NULL);
    sfRectangleShape_setSize(G->shape_r, (sfVector2f){RATIO_X(menu_act->width),
    RATIO_Y(30)});
    for (button_t *tmp = *wall; tmp != NULL; tmp = tmp->next) {
        display_wall2(G, offset, offset2, tmp);
        offset2 += 28;
    }
}

void display_menu_bar(global_t *G)
{
    float offset = 0;

    sfRectangleShape_setPosition(G->shape_r, (sfVector2f){0, 0});
    sfRectangleShape_setSize(G->shape_r, (sfVector2f){800,
    (25 * 600 / G->size_window.y)});
    sfRectangleShape_setFillColor(G->shape_r, sfWhite);
    sfRenderWindow_drawRectangleShape(G->window, G->shape_r, NULL);
    for (menu_bar_t *tmp = *(G->menu_bar); tmp != NULL; tmp = tmp->next) {
        sfText_setScale(G->text, (sfVector2f){RATIO_X(1), RATIO_Y(1)});
        sfText_setString(G->text, tmp->name);
        if (G->menu_bar_active == tmp->id)
            display_wall(G, tmp->wall, offset, tmp);
        sfText_setString(G->text, tmp->name);
        sfText_setPosition(G->text,
        (sfVector2f){RATIO_X((offset + 6)), RATIO_Y(2)});
        sfText_setFillColor(G->text, sfBlack);
        sfRenderWindow_drawText(G->window, G->text, NULL);
        sfText_setScale(G->text, (sfVector2f){1, 1});
        offset += sfText_getGlobalBounds(G->text).width + 15;
    }
}
