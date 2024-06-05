/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** pop_up.c
*/

#include "my.h"

static void set_rect(global_t *G, sfVector2f pos, sfVector2f size,
    sfColor color)
{
    sfRectangleShape_setPosition(G->shape_r, pos);
    sfRectangleShape_setSize(G->shape_r, size);
    sfRectangleShape_setFillColor(G->shape_r, color);
    sfRenderWindow_drawRectangleShape(G->window, G->shape_r, NULL);
}

static void display_pop_up_button(global_t *G, ...)
{
    va_list list;
    char *tmp = NULL;

    va_start(list, G);
    for (int i = 0; i < G->pop_up->ac; i++) {
        tmp = va_arg(list, char *);
        if (tmp != NULL)
            set_text(G, tmp, (sfVector2f){(G->size_window.x - 400) / 2 \
            + (400 / G->pop_up->ac / 2 + (i * 400 / G->pop_up->ac)),
            (G->size_window.y - 300) / 2 + 265}, 15, sfBlack);
        if (i != G->pop_up->ac - 1) {
            set_rect(G, (sfVector2f){RATIO_X((G->size_window.x - 400) / 2)
            + RATIO_X(400 * (i + 1) / G->pop_up->ac),
            RATIO_Y((G->size_window.y - 300) / 2) + RATIO_Y(240)},
            (sfVector2f){RATIO_X(2), RATIO_Y(60)},
            (sfColor){100, 100, 100, 255});
        }
    }
    va_end(list);
}

static void display_pop_up2(global_t *G)
{
    set_rect(G, (sfVector2f){RATIO_X((G->size_window.x - 360) / 2),
    RATIO_Y((G->size_window.y - 300) / 2) + RATIO_Y(138)},
    (sfVector2f){RATIO_X(360), RATIO_Y(30)},
    (sfColor){100, 100, 100, 255});
    set_rect(G, (sfVector2f){RATIO_X((G->size_window.x - 356) / 2),
    RATIO_Y((G->size_window.y - 300) / 2) + RATIO_Y(140)},
    (sfVector2f){RATIO_X(356), RATIO_Y(26)},
    (sfColor){255, 255, 255, 255});
    set_text(G, G->pop_up->input, (sfVector2f){(G->size_window.x) / 2,
    (G->size_window.y - 300) / 2 + 145}, 15, sfBlack);
}

void display_pop_up(global_t *G)
{
    sfRenderWindow_setView(G->window, G->main_view);
    set_rect(G, (sfVector2f){0, 0},
    ratio_from_u(G->size_window, G), (sfColor){0, 0, 0, 150});
    set_rect(G, (sfVector2f){RATIO_X((G->size_window.x - 400) / 2),
    RATIO_Y((G->size_window.y - 300) / 2)},
    (sfVector2f){RATIO_X(400), RATIO_Y(300)}, (sfColor){230, 230, 230, 255});
    set_text(G, G->pop_up->text, (sfVector2f){(G->size_window.x) / 2,
    (G->size_window.y - 300) / 2 + 40}, 15, sfBlack);
    if (G->pop_up->mode == 1)
        display_pop_up2(G);
    set_rect(G, (sfVector2f){RATIO_X((G->size_window.x - 400) / 2),
    RATIO_Y((G->size_window.y - 300) / 2) + RATIO_Y(238)},
    (sfVector2f){RATIO_X(400), RATIO_Y(2)}, (sfColor){100, 100, 100, 255});
    display_pop_up_button(G, G->pop_up->opt1, G->pop_up->opt2,
    G->pop_up->opt3, G->pop_up->opt4);
}

static void check_pressed(global_t *G, ...)
{
    va_list list;
    void (*tmp)(global_t *) = NULL;
    sfVector2f click
    = ratio_from_i(sfMouse_getPositionRenderWindow(G->window), G);

    va_start(list, G);
    for (int i = 0; i < G->pop_up->ac; i++) {
        tmp = va_arg(list, void (*)(global_t *));
        if (click.x >= RATIO_X((G->size_window.x - 400) / 2) \
        + RATIO_X(i * 400 / G->pop_up->ac)
        && click.x < RATIO_X((G->size_window.x - 400) / 2) \
        + RATIO_X((i + 1) * 400 / G->pop_up->ac)
        && click.y >= RATIO_Y((G->size_window.y - 300) / 2) + RATIO_Y(240)
        && click.y < RATIO_Y((G->size_window.y - 300) / 2) + RATIO_Y(300)) {
            tmp(G);
            break;
        }
    }
    va_end(list);
}

static void check_key(global_t *G)
{
    if (G->event.key.code == sfKeyEscape)
        pop_up_cancel(G);
    if (G->event.key.code == sfKeyBackspace
    && my_strlen(G->pop_up->input) != 0)
        G->pop_up->input[my_strlen(G->pop_up->input) - 1] = '\0';
    if (my_strlen(G->pop_up->input) == 38)
        return;
    if (G->event.key.code < 26)
        my_strcat2(G->pop_up->input, (char[2]){'a' + G->event.key.code, 0});
    if (G->event.key.code == sfKeySpace || G->event.key.code == sfKeyNum8)
        my_strcat2(G->pop_up->input, "_");
    if (G->event.key.code == sfKeySemiColon
    || G->event.key.code == sfKeyPeriod)
        my_strcat2(G->pop_up->input, ".");
    if (G->event.key.code == sfKeySlash)
        my_strcat2(G->pop_up->input, "/");
}

void analize_pop_up(global_t *G)
{
    switch (G->event.type) {
        case (sfEvtClosed):
            return sfRenderWindow_close(G->window);
        case (sfEvtMouseButtonPressed):
            check_pressed(G, G->pop_up->function1, G->pop_up->function2,
            G->pop_up->function3, G->pop_up->function4);
            break;
        case (sfEvtKeyPressed):
            check_key(G);
            break;
        case (sfEvtResized):
            help_resize(G);
            break;
    }
}

static void pop_up3(global_t *G, va_list *list)
{
    if (G->pop_up->ac > 2) {
        G->pop_up->opt3 = my_strdup_na(va_arg(*list, char *));
        G->pop_up->function3 = va_arg(*list, void (*)(global_t *));
    }
    if (G->pop_up->ac > 3) {
        G->pop_up->opt4 = my_strdup_na(va_arg(*list, char *));
        G->pop_up->function4 = va_arg(*list, void (*)(global_t *));
    }
}

static void pop_up2(global_t *G, char const *str, int mode)
{
    if (G->pop_up->text != NULL)
        free(G->pop_up->text);
    G->pop_up->text = my_strdup_na(str);
    if (G->pop_up->opt1 != NULL)
        free(G->pop_up->opt1);
    G->pop_up->opt1 = NULL;
    if (G->pop_up->opt2 != NULL)
        free(G->pop_up->opt2);
    G->pop_up->opt2 = NULL;
    if (G->pop_up->opt3 != NULL)
        free(G->pop_up->opt3);
    G->pop_up->opt3 = NULL;
    if (G->pop_up->opt4 != NULL)
        free(G->pop_up->opt4);
    G->pop_up->opt4 = NULL;
    G->pop_up->active = 1;
    G->pop_up->mode = mode;
    for (int i = 0; i < 39; i++)
        G->pop_up->input[i] = 0;
}

void pop_up(global_t *G, char const *str, int mode, ...)
{
    va_list list;

    va_start(list, mode);
    pop_up2(G, str, mode);
    G->pop_up->ac = va_arg(list, int);
    if (G->pop_up->ac > 0) {
        G->pop_up->opt1 = my_strdup_na(va_arg(list, char *));
        G->pop_up->function1 = va_arg(list, void (*)(global_t *));
    }
    if (G->pop_up->ac > 1) {
        G->pop_up->opt2 = my_strdup_na(va_arg(list, char *));
        G->pop_up->function2 = va_arg(list, void (*)(global_t *));
    }
    pop_up3(G, &list);
    va_end(list);
}
