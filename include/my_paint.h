/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** my_paint.h
*/

#ifndef MY_PAINT_
    #define MY_PAINT_

    #define RATIO_X(nb) nb * 800 / (float)G->size_window.x
    #define RATIO_Y(nb) nb * 600 / (float)G->size_window.y

enum Buttons_enum {
    file,
    color,
    max
};

enum Action {
    Image,
    Draw,
    Erase,
    Rectangle,
    Circle,
    Cut,
    Copy,
    Paste,
    Shapes
};

enum Draw_type {
    Squareshape,
    Circleshape
};

enum Tools {
    Pencil,
    Eraser,
    Rectangle_shape,
    Circle_shape
};

enum State {
    None,
    Clicked,
    Hovered
};

enum Saving {
    Bmp,
    Png,
    Jpg
};

struct global_s;

typedef struct pop_op_s {
    int active;
    char *text;
    char *opt1;
    char *opt2;
    char *opt3;
    char *opt4;
    void (*function1)(struct global_s *);
    void (*function2)(struct global_s *);
    void (*function3)(struct global_s *);
    void (*function4)(struct global_s *);
    int ac;
    int mode;
    char input[39];
} pop_up_t;

typedef struct menu_bar_s {
    int id;
    char *name;
    int wall_size;
    int width;
    struct button_s **wall;
    struct menu_bar_s *next;
} menu_bar_t;

typedef struct button_s {
    int id;
    char *text;
    char *hover;
    sfSprite *icon;
    sfIntRect pos;
    sfColor color;
    void (*function)(struct global_s *, struct button_s *);
    struct button_s *next;
} button_t;

typedef struct clipboard_s {
    sfTexture *texture;
    sfSprite *sprite;
} clipboard_t;

typedef struct global_s {
    sfRenderWindow *window;
    sfColor color_bg;
    int to_hover;
    int menu_bar_active;
    int menu_bar_wall_active;
    int is_action;
    sfVector2f pos_point;
    sfVector2f pos_image;
    sfVector2f pos_shape;
    int is_out;
    int active_action;
    enum Tools tool;
    sfColor color_use;
    int saving_type;
    int size_p;
    int size_e;
    int thickness;
    int drawing_type;
    sfEvent event;
    sfVector2u size_window;
    char *file_name;
    sfVector2f size_project;
    sfView *main_view;
    sfView *draw_view;
    struct layer_s **layer;
    int layer_act;
    struct clipboard_s clipboard;
    struct menu_bar_s **menu_bar;
    struct button_s **buttons;
    sfRectangleShape *shape_r;
    sfCircleShape *shape_c;
    int draw_hover;
    sfSprite *hover_color;
    sfTexture *texture;
    sfSprite *sprite;
    sfText *text;
    sfSprite *cursor;
    pop_up_t *pop_up;
} global_t;

typedef struct layer_s {
    int id;
    int active;
    int action_act;
    struct action_s **history;
    sfImage *res;
    struct layer_s *next;
} layer_t;

typedef struct action_s {
    int id;
    int name;
    sfImage *action;
    struct action_s *next;
} action_t;

// initialisation
global_t *init_global(void);
menu_bar_t **create_menu_bar(void);
void create_button(button_t **buttons, void (*function)
    (global_t *G, button_t *button), char *hover, ...);
void create_layer(global_t *G);
void destroy_layer(global_t *G);
void new_file(global_t *G);

//tools
void modify_text(sfText *text, sfVector2f pos, char *content);
void save_img(global_t *G);
void create_action(global_t *G);
void circle_on_pixel(global_t *G, sfImage *img, sfVector2f pixel);
void square_on_pixel(global_t *G, sfImage *img, sfVector2f pixel);
void display_cursor(global_t *G);
void set_text(global_t *G, char *str, sfVector2f pos, ...);
void undo(global_t *G, button_t *button);
void redo(global_t *G, button_t *button);
void destroy_action(action_t **action_head, int id);
void add_layer(global_t *G, button_t *button);
void rm_layer(global_t *G, button_t *button);
void destroy_last(global_t *G);
void down_layer(global_t *G, button_t *button);
void up_layer(global_t *G, button_t *button);
void placeholder_square(global_t *G);
void set_shape(global_t *G, button_t *button);
void release_rectangle(global_t *G);
sfVector2f i_to_2f(sfVector2i change);
sfVector2f u_to_2f(sfVector2u change);
sfVector2f ratio_from_i(sfVector2i change, global_t *G);
sfVector2f ratio_from_u(sfVector2u change, global_t *G);
sfVector2f ratio_from_f(sfVector2f change, global_t *G);

//Buttons ptr functions
void none(global_t *G, button_t *button);
void color_buttons_hd(global_t *G, button_t *button);
void color_palette_interaction(global_t *G, button_t *button);
void thick_minus(global_t *G, button_t *button);
void thick_plus(global_t *G, button_t *button);
void set_circle(global_t *G, button_t *button);
void set_square(global_t *G, button_t *button);
void set_draw(global_t *G, button_t *button);
void set_erase(global_t *G, button_t *button);
void hide_show_layer(global_t *G, button_t *button);

// analize_event
void what_analize(global_t *G);
void analize_event(global_t *G);
void analize_pop_up(global_t *G);
void draw_movement(global_t *G, int handle);
void display_color_hovered(global_t *G, button_t *current,
    sfMouseMoveEvent pos_move);
void help_resize(global_t *G);

// update
void update(global_t *G);
void update_image(global_t *G);
void set_updated_image(sfImage *saved, action_t *to_get);
void pop_up(global_t *G, char const *str, int mode, ...);

// display
void display(global_t *G);
void display_menu_bar(global_t *G);
void display_menu(global_t *G);
void display_buttons(global_t *G);
void display_layer(global_t *G);
void display_pop_up(global_t *G);

// function ptr
void file_new(global_t *G, button_t *button);
void file_open(global_t *G, button_t *button);
void file_save(global_t *G, button_t *button);
void file_exit(global_t *G, button_t *button);
void edit_pencil(global_t *G, button_t *button);
void edit_eraser(global_t *G, button_t *button);
void edit_rectangle(global_t *G, button_t *button);
void edit_undo(global_t *G, button_t *button);
void edit_redo(global_t *G, button_t *button);
void help_login(global_t *G, button_t *button);
void help_about(global_t *G, button_t *button);
void pop_up_jpg(global_t *G);
void pop_up_png(global_t *G);
void pop_up_bmp(global_t *G);
void pop_up_cancel(global_t *G);

#endif /* MY_PAINT_ */
