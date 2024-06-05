/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** drawing.c
*/

#include "my.h"

void draw_shape(global_t *G, sfImage *image_act)
{
    switch (G->drawing_type) {
        case Circleshape:
            circle_on_pixel(G, image_act,
            (sfVector2f){G->pos_point.x - G->pos_image.x,
            G->pos_point.y - G->pos_image.y});
            break;
        case Squareshape:
            square_on_pixel(G, image_act,
            (sfVector2f){G->pos_point.x - G->pos_image.x,
            G->pos_point.y - G->pos_image.y});
            break;
    }
}

static void other_action_creation(global_t *G, action_t *new_head,
    layer_t *temp_layer)
{
    (temp_layer->action_act)++;
    if (G->active_action == Draw || G->active_action == Erase) {
        G->pos_point = i_to_2f(sfMouse_getPositionRenderWindow(G->window));
        if (G->pos_point.x - G->pos_image.x
        >= (float)sfImage_getSize(new_head->action).x ||
        G->pos_point.x - G->pos_image.x < 0.0 ||
        G->pos_point.y - G->pos_image.y
        >= (float)sfImage_getSize(new_head->action).y ||
        G->pos_point.y - G->pos_image.y < 0.0)
            draw_shape(G, new_head->action);
    }
}

void create_action(global_t *G)
{
    layer_t *temp_layer = *(G->layer);
    action_t *new_head = malloc(sizeof(action_t));

    for (; temp_layer->next != NULL && temp_layer->id != G->layer_act;
    temp_layer = temp_layer->next);
    new_head->id = 1;
    destroy_action(temp_layer->history, temp_layer->action_act + 1);
    for (action_t *temp = *(temp_layer->history); temp != NULL;
    temp = temp->next) {
        if (temp->next == NULL) {
            temp->next = new_head;
            break;
        }
        (new_head->id)++;
    }
    new_head->name = G->active_action;
    new_head->action = sfImage_createFromColor(G->size_project.x,
    G->size_project.y, sfTransparent);
    new_head->next = NULL;
    other_action_creation(G, new_head, temp_layer);
}

void to_draw(global_t *G, sfImage *image_act)
{
    sfVector2f old = G->pos_point;
    sfVector2f point;
    sfVector2f pos_point;
    float lerp_point = 0.0f;

    point = i_to_2f(sfMouse_getPositionRenderWindow(G->window));
    for (; lerp_point <= 1.0f;
    lerp_point += 1 / sqrt((double)((old.x - point.x) * (old.x - point.x)
    + (old.y - point.y) * (old.y - point.y)))) {
        G->pos_point.x = (1 - lerp_point) * old.x + lerp_point * point.x;
        G->pos_point.y = (1 - lerp_point) * old.y + lerp_point * point.y;
        draw_shape(G, image_act);
    }
    G->pos_point = point;
}

static void get_action(global_t *G, action_t *temp_act)
{
    switch (temp_act->name) {
        case Draw:
            to_draw(G, temp_act->action);
            break;
        case Erase:
            to_draw(G, temp_act->action);
            break;
        default:
            break;
    }
}

void draw_movement(global_t *G, int handle)
{
    layer_t *temp = *(G->layer);
    action_t *temp_act;

    for (; temp != NULL && temp->id != G->layer_act; temp = temp->next);
    temp_act = *(temp->history);
    for (; temp_act != NULL && temp_act->id != temp->action_act;
    temp_act = temp_act->next);
    get_action(G, temp_act);
}
