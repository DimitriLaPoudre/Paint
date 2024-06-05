/*
** EPITECH PROJECT, 2023
** B-MUL-200-NCE-2-1-mypaint-raphael.launay
** File description:
** init.c
*/

#include "my.h"

static sfText *create_text(void)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("font/Cousine-Regular.ttf");

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 15);
    return text;
}

static void init_colors(button_t **button)
{
    create_button(button, &color_palette_interaction, "test",
    (sfIntRect){600, 45, 100, 100}, "sprite/color_palette.png", sfTransparent);
    create_button(button, &color_buttons_hd, "Black",
    (sfIntRect){460, 65, 20, 20}, "", sfBlack);
    create_button(button, &color_buttons_hd, "White",
    (sfIntRect){490, 65, 20, 20}, "", sfWhite);
    create_button(button, &color_buttons_hd, "Blue",
    (sfIntRect){520, 65, 20, 20}, "", sfBlue);
    create_button(button, &color_buttons_hd, "Red",
    (sfIntRect){550, 65, 20, 20}, "", sfRed);
    create_button(button, &color_buttons_hd, "Green",
    (sfIntRect){460, 105, 20, 20}, "", sfGreen);
    create_button(button, &color_buttons_hd, "Yellow",
    (sfIntRect){490, 105, 20, 20}, "", sfYellow);
    create_button(button, &color_buttons_hd, "Rose",
    (sfIntRect){520, 105, 20, 20}, "", (sfColor){255, 0, 255, 255});
    create_button(button, &color_buttons_hd, "Orange",
    (sfIntRect){550, 105, 20, 20}, "", (sfColor){255, 150, 0, 255});
}

static void other_buttons(button_t **button)
{
    create_button(button, &undo, "Undo on this layer",
    (sfIntRect){215, 30, 25, 25}, "sprite/undo.png", sfWhite);
    create_button(button, &redo, "Redo on this layer",
    (sfIntRect){250, 30, 25, 25}, "sprite/redo.png", sfWhite);
    create_button(button, &add_layer, "Add new layer",
    (sfIntRect){215, 62, 25, 25}, "sprite/addlayer.png", sfWhite);
    create_button(button, &rm_layer, "Remove this layer",
    (sfIntRect){215, 97, 25, 25}, "sprite/rmlayer.png", sfWhite);
    create_button(button, &up_layer, "Goto next layer",
    (sfIntRect){250, 62, 25, 25}, "sprite/up_arrow.png", sfWhite);
    create_button(button, &down_layer, "Goto previous layer",
    (sfIntRect){250, 97, 25, 25}, "sprite/down_arrow.png", sfWhite);
    create_button(button, &hide_show_layer, "Hide/Show this layer",
    (sfIntRect){215, 132, 25, 25}, "sprite/hide_show.png", sfWhite);
}

static button_t **init_buttons(void)
{
    button_t **button = CALLOC(sizeof(button_t *));

    init_colors(button);
    create_button(button, &set_draw, "Pencil",
    (sfIntRect){20, 32, 60, 60}, "sprite/pencil.png", sfWhite);
    create_button(button, &set_erase, "Eraser",
    (sfIntRect){20, 97, 60, 60}, "sprite/eraser.png", sfWhite);
    create_button(button, &set_shape, "Rectangle shape",
    (sfIntRect){380, 62, 60, 60}, "sprite/rectangle_shape.png", sfWhite);
    create_button(button, &thick_minus, "Reduce thickness",
    (sfIntRect){155, 62, 25, 25}, "sprite/minus.png", sfWhite);
    create_button(button, &thick_plus, "Increase thickness",
    (sfIntRect){120, 62, 25, 25}, "sprite/plus.png", sfWhite);
    create_button(button, &set_circle, "Circle brush",
    (sfIntRect){155, 97, 25, 25}, "sprite/circle.png", sfWhite);
    create_button(button, &set_square, "Square brush",
    (sfIntRect){120, 97, 25, 25}, "sprite/rectangle.png", sfWhite);
    other_buttons(button);
    return button;
}

static void init_global3(global_t *G)
{
    G->draw_view = sfView_create();
    sfView_setViewport(G->draw_view, (sfFloatRect){0,
    165.0 / G->size_window.y,
    1, (G->size_window.y - 165.0) / G->size_window.y});
    sfView_reset(G->draw_view,
    (sfFloatRect){(G->size_window.x - G->size_project.x) / 2 \
    - G->size_window.x, 0, G->size_window.x, (G->size_window.y - 165.0)});
    G->sprite = sfSprite_create();
    G->texture = NULL;
    G->pos_image = (sfVector2f){0, 0};
    G->hover_color = ALLOC_S("sprite/hover_color.png");
    sfSprite_setOrigin(G->hover_color, (sfVector2f){16.0, 36.0});
    G->pop_up = CALLOC(sizeof(pop_up_t));
    G->cursor = ALLOC_S("sprite/draw_cursor.png");
    sfSprite_setOrigin(G->cursor, (sfVector2f){
    sfSprite_getLocalBounds(G->cursor).width / 2,
    sfSprite_getLocalBounds(G->cursor).height / 2});
    my_strcpy(G->pop_up->input, "new_file");
}

static void init_global2(global_t *G)
{
    G->drawing_type = Circleshape;
    G->thickness = 5;
    G->to_hover = -1;
    G->saving_type = Png;
    G->active_action = Draw;
    G->is_action = 0;
    G->pos_point = (sfVector2f){-1, -1};
    G->text = create_text();
    G->size_project = (sfVector2f){800, 600};
    G->main_view = sfView_create();
    sfView_reset(G->main_view, (sfFloatRect){0, 0,
    G->size_window.x, G->size_window.y});
    sfView_setViewport(G->main_view,
    (sfFloatRect){0, 0, 1, 1});
    init_global3(G);
    new_file(G);
}

static void init_other(global_t *G)
{
    G->color_bg = sfWhite;
    G->menu_bar_active = -1;
    G->menu_bar_wall_active = -1;
    G->tool = Pencil;
    G->color_use = sfBlack;
    G->size_p = 1;
    G->size_e = 1;
    G->layer = CALLOC(sizeof(layer_t *));
    G->clipboard = (clipboard_t){NULL, NULL};
    G->menu_bar = create_menu_bar();
    G->buttons = init_buttons();
}

global_t *init_global(void)
{
    global_t *G = ALLOC(sizeof(global_t));
    sfImage* Icon = sfImage_createFromFile("sprite/icon.png");

    G->window = sfRenderWindow_create((sfVideoMode){800, 600},
    "My Paint", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(G->window, 60);
    sfRenderWindow_setIcon(G->window, 512, 512, sfImage_getPixelsPtr(Icon));
    sfImage_destroy(Icon);
    G->size_window = sfRenderWindow_getSize(G->window);
    G->file_name = my_strdup_na("new_file");
    init_other(G);
    G->shape_r = sfRectangleShape_create();
    G->shape_c = sfCircleShape_create();
    G->draw_hover = 0;
    init_global2(G);
    return G;
}
