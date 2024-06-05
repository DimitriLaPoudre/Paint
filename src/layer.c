/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** layer.c
*/

#include "my.h"

void destroy_action(action_t **action_head, int id)
{
    action_t *act = *action_head;
    action_t *tmp = NULL;

    for (int i = 0; i < id && act != NULL; i++) {
        tmp = act;
        act = act->next;
    }
    if (tmp != NULL)
        tmp->next = NULL;
    for (; act != NULL; act = tmp) {
        tmp = act->next;
        sfImage_destroy(act->action);
        free(act);
    }
}

void destroy_layer(global_t *G)
{
    layer_t *act = *(G->layer);
    layer_t *tmp = NULL;

    for (; act != NULL; act = tmp) {
        tmp = act->next;
        destroy_action(act->history, 0);
        free(act->history);
        sfImage_destroy(act->res);
        free(act);
    }
    (*(G->layer)) = NULL;
}

void destroy_last(global_t *G)
{
    layer_t *temp = *(G->layer);
    layer_t *prev = NULL;

    if (temp->next == NULL)
        return;
    for (; G->layer_act != temp->id; temp = temp->next)
        prev = temp;
    if (prev == NULL)
        *(G->layer) = temp->next;
    else
        prev->next = temp->next;
    destroy_action(temp->history, 0);
    free(temp->history);
    sfImage_destroy(temp->res);
    free(temp);
    if (G->layer_act != 0)
        G->layer_act--;
    temp = ((prev == NULL) ? *(G->layer) : prev->next);
    for (; temp != NULL; temp = temp->next)
        temp->id--;
}

void display_layer(global_t *G)
{
    action_t *tmp = NULL;

    sfSprite_setPosition(G->sprite,
    (sfVector2f){((float)G->size_window.x - G->size_project.x) / 2 \
    - (float)G->size_window.x,
    (((float)G->size_window.y - 165) - G->size_project.y) / 2});
    for (layer_t *tmp2 = *(G->layer); tmp2 != NULL; tmp2 = tmp2->next) {
        for (tmp = *(tmp2->history); G->is_action && tmp2->active
        && tmp->next != NULL && tmp->id < tmp2->action_act; tmp = tmp->next);
        if (tmp2->active) {
            sfTexture_updateFromImage(G->texture, tmp2->res, 0, 0);
            sfSprite_setTexture(G->sprite, G->texture, sfTrue);
            sfRenderWindow_drawSprite(G->window, G->sprite, NULL);
        }
        if (tmp2->active && G->is_action) {
            sfTexture_updateFromImage(G->texture, tmp->action, 0, 0);
            sfSprite_setTexture(G->sprite, G->texture, sfTrue);
            sfRenderWindow_drawSprite(G->window, G->sprite, NULL);
        }
    }
}

static void create_layer2(global_t *G, layer_t *new)
{
    new->active = 1;
    new->action_act = 0;
    G->layer_act = new->id;
    new->res = sfImage_createFromColor(G->size_project.x,
    G->size_project.y, (new->id == 0) ? sfWhite : sfTransparent);
    new->history = malloc(sizeof(action_t *));
    *(new->history) = malloc(sizeof(action_t));
    (*(new->history))->id = 0;
    (*(new->history))->name = Image;
    (*(new->history))->action = sfImage_createFromColor(G->size_project.x,
    G->size_project.y, (new->id == 0) ? sfWhite : sfTransparent);
    (*(new->history))->next = NULL;
    new->next = NULL;
}

void create_layer(global_t *G)
{
    layer_t *new = malloc(sizeof(layer_t));

    new->id = 0;
    for (layer_t *tmp2 = *(G->layer); tmp2 != NULL; tmp2 = tmp2->next) {
        (new->id)++;
        if (tmp2->next == NULL) {
            tmp2->next = new;
            break;
        }
    }
    if (*(G->layer) == NULL)
        *(G->layer) = new;
    create_layer2(G, new);
}
