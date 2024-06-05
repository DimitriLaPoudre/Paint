/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** analize_event.c
*/

#include "my.h"

static void check_menu_bar(global_t *G)
{
    float offset = 0;

    if (G->menu_bar == NULL || G->event.mouseButton.button != 0) {
        G->menu_bar_active = -1;
        return;
    }
    for (menu_bar_t *tmp = *(G->menu_bar); tmp != NULL; tmp = tmp->next) {
        sfText_setString(G->text, tmp->name);
        if (G->event.mouseButton.x >= offset
        && G->event.mouseButton.x
        < offset + sfText_getGlobalBounds(G->text).width + 15
        && G->menu_bar_active != tmp->id) {
            G->menu_bar_active = tmp->id;
            G->menu_bar_wall_active = -1;
            return;
        }
        offset += sfText_getGlobalBounds(G->text).width + 15;
    }
    G->menu_bar_active = -1;
}

static void check_wall_pressed(global_t *G)
{
    float offset = 0;
    float offset2 = 25;
    menu_bar_t *tmp1 = *(G->menu_bar);

    for (; tmp1->id != G->menu_bar_active; tmp1 = tmp1->next) {
        sfText_setString(G->text, tmp1->name);
        offset += sfText_getGlobalBounds(G->text).width + 15;
    }
    for (button_t *tmp2 = *(tmp1->wall); tmp2 != NULL; tmp2 = tmp2->next) {
        if (G->event.mouseButton.x >= offset
        && G->event.mouseButton.x < offset + tmp1->width
        && G->event.mouseButton.y >= offset2
        && G->event.mouseButton.y < offset2 + 28) {
            return tmp2->function(G, tmp2);
        }
        offset2 += 28;
    }
}

static void pressed_button(global_t *G)
{
    button_t *temp = NULL;
    sfIntRect tmp;

    if (G->buttons == NULL)
        return;
    temp = *(G->buttons);
    for (; temp != NULL; temp = temp->next) {
        tmp = temp->pos;
        if (sfIntRect_contains(&(tmp),
        G->event.mouseButton.x, G->event.mouseButton.y))
            break;
    }
    if (temp == NULL)
        return;
    temp->function(G, temp);
}

static void check_pressed(global_t *G)
{
    if (G->menu_bar_active != -1) {
        check_wall_pressed(G);
        G->menu_bar_active = -1;
        return;
    }
    G->menu_bar_active = -1;
    if (G->event.mouseButton.button == 0 && G->event.mouseButton.x >= 0
    && G->event.mouseButton.x <= G->size_window.x
    && G->event.mouseButton.y >= 165
    && G->event.mouseButton.y <= G->size_window.y) {
        if (G->active_action == Shapes)
            G->pos_shape = (sfVector2f){G->event.mouseButton.x,
            G->event.mouseButton.y};
        create_action(G);
        G->is_action = 1;
        return;
    }
    pressed_button(G);
}

static int check_wall(global_t *G)
{
    float offset = 0;
    float offset2 = 25;
    menu_bar_t *tmp1 = *(G->menu_bar);

    for (; tmp1->id != G->menu_bar_active; tmp1 = tmp1->next) {
        sfText_setString(G->text, tmp1->name);
        offset += sfText_getGlobalBounds(G->text).width + 15;
    }
    for (button_t *tmp2 = *(tmp1->wall); tmp2 != NULL; tmp2 = tmp2->next) {
        if (G->event.mouseMove.x >= offset
        && G->event.mouseMove.x < offset + tmp1->width
        && G->event.mouseMove.y >= offset2
        && G->event.mouseMove.y < offset2 + 28) {
            G->menu_bar_wall_active = tmp2->id;
            return 1;
        }
        offset2 += 28;
    }
    G->menu_bar_wall_active = -1;
    return 0;
}

void hover_fixed(global_t *G, button_t *temp)
{
    switch (temp->id) {
        case 1:
            display_color_hovered(G, temp, G->event.mouseMove);
            break;
        default:
            G->to_hover = temp->id;
            break;
    }
}

static void check_buttons_hover(global_t *G)
{
    button_t *temp = NULL;
    sfIntRect tmp;

    if (G->buttons == NULL)
        return;
    temp = *(G->buttons);
    for (; temp != NULL; temp = temp->next) {
        tmp = temp->pos;
        if (sfIntRect_contains(&(tmp),
        G->event.mouseMove.x, G->event.mouseMove.y))
            break;
    }
    G->draw_hover = temp != NULL &&
    G->draw_hover == 1 && temp->id == 1 ? 1 : 0;
    if (temp == NULL) {
        G->to_hover = -1;
        return;
    }
    
    hover_fixed(G, temp);
}

static void check_hover(global_t *G)
{
    if (G->menu_bar_active != -1 && check_wall(G))
        return;
    check_buttons_hover(G);
    if (G->is_action) {
        draw_movement(G, 1);
        return;
    }
}

static void check_released(global_t *G)
{
    if (G->event.mouseButton.button == 0 && G->is_action == 1) {
        G->is_action = 0;
        release_rectangle(G);
        update_image(G);
    }
}

void analize_event(global_t *G)
{
    switch (G->event.type) {
        case (sfEvtClosed):
            return sfRenderWindow_close(G->window);
        case (sfEvtMouseButtonPressed):
            if (G->event.mouseButton.y <= 25)
                check_menu_bar(G);
            else
                check_pressed(G);
            break;
        case (sfEvtMouseMoved):
            check_hover(G);
            break;
        case (sfEvtMouseButtonReleased):
            check_released(G);
            break;
        case (sfEvtResized):
            help_resize(G);
            break;
    }
}
