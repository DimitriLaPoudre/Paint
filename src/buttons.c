/*
** EPITECH PROJECT, 2023
** B-MUL-200-NCE-2-1-mypaint-raphael.launay
** File description:
** buttons.c
*/

#include "my.h"

static void display_buttons3(global_t *G, sfRectangleShape *rec,
    button_t *temp)
{
    sfSprite_setScale(temp->icon,
    (sfVector2f){RATIO_X( \
    temp->pos.width) / (float)(sfTexture_getSize(
    sfSprite_getTexture(temp->icon)).x),
    RATIO_Y(temp->pos.height) / (float)(sfTexture_getSize( \
    sfSprite_getTexture(temp->icon)).y)});
    sfSprite_setPosition(temp->icon,
    (sfVector2f){RATIO_X(temp->pos.left), RATIO_Y(temp->pos.top)});
    sfRenderWindow_drawSprite(G->window, temp->icon, NULL);
}

static void display_buttons2(global_t *G, sfRectangleShape *rec,
    button_t *temp)
{
    sfRectangleShape_setFillColor(rec, temp->color);
    sfRectangleShape_setSize(rec, (sfVector2f){RATIO_X(temp->pos.width),
    RATIO_Y(temp->pos.height)});
    sfRectangleShape_setPosition(rec,
    (sfVector2f){RATIO_X(temp->pos.left), RATIO_Y(temp->pos.top)});
    sfRectangleShape_setOutlineColor(rec, sfTransparent);
    sfRectangleShape_setOutlineThickness(rec, 1);
    if (temp->id >= 2 && temp->id <= 12)
        sfRectangleShape_setOutlineColor(rec, sfBlack);
    if ((temp->id == 10 && G->active_action == Draw)
    || (temp->id == 11 && G->active_action == Erase)
    || (temp->id == 12 && G->active_action == Shapes))
        sfRectangleShape_setFillColor(rec, (sfColor){150, 150, 150, 255});
    if ((temp->id == 16 && G->drawing_type == Squareshape)
    || (temp->id == 15 && G->drawing_type == Circleshape))
        sfRectangleShape_setFillColor(rec, (sfColor){150, 150, 150, 255});
    sfRenderWindow_drawRectangleShape(G->window, rec, NULL);
}

void display_buttons(global_t *G)
{
    button_t *temp = NULL;
    sfRectangleShape *rec = G->shape_r;

    if (G->buttons == NULL)
        return;
    for (temp = *(G->buttons); temp != NULL; temp = temp->next) {
        display_buttons2(G, rec, temp);
        if (temp->text == NULL && temp->icon == NULL)
            continue;
        if (temp->text == NULL) {
            display_buttons3(G, rec, temp);
        } else {
            modify_text(G->text, (sfVector2f){temp->pos.left,
            RATIO_Y(temp->pos.top)}, temp->text);
            sfText_setColor(G->text, sfRed);
            sfRenderWindow_drawText(G->window, G->text, NULL);
        }
    }
}

static void create_button2(button_t *new, char *text)
{
    sfFloatRect fr;

    if (text == NULL) {
        new->text = NULL;
        new->icon = NULL;
    } else if (!my_strncmp("sprite/", text, 7)) {
        new->text = NULL;
        new->icon = ALLOC_S(text);
        fr = sfSprite_getGlobalBounds(new->icon);
        sfSprite_setPosition(new->icon, (sfVector2f)
        {fr.left + fr.width / 2, fr.top + fr.height / 2});
    } else {
        new->text = my_strdup(text);
        new->icon = NULL;
    }
}

void create_button(button_t **buttons,
    void (*function)(global_t *G, button_t *button), char *hover, ...)
{
    static int id = 1;
    char *text = NULL;
    sfColor color;
    button_t *new = ALLOC(sizeof(button_t));
    va_list list;

    va_start(list, hover);
    new->id = id;
    new->function = function;
    new->hover = my_strdup(hover);
    new->pos = va_arg(list, sfIntRect);
    text = va_arg(list, char *);
    create_button2(new, text);
    new->color = va_arg(list, sfColor);
    new->next = *buttons;
    *buttons = new;
    id++;
    va_end(list);
}
