/*
** EPITECH PROJECT, 2020
** rpg.h
** File description:
** rpg.h
*/

#include <SFML/Window/Export.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics/FontInfo.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
// #include <SFML/Audio/Export.h>
// #include <SFML/Audio/SoundStatus.h>
// #include <SFML/Audio/Types.h>
#include <SFML/Audio.h>
#include <fcntl.h>

struct animation {
    sfTexture *tex[8];
    int count;
    float speed;
};

struct slime_animation {
    sfTexture *tex[2];
    int count;
    float speed;
};

struct enemy_struct {
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    struct slime_animation anim;
    float speed;
    int dir;
    float max_health;
    float current_health;
    int damage;
    int alive;
};
typedef struct enemy_struct enemy_t;

struct player_struct {
    struct animation anim;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    int exp_to_next_lvl;
    int exp;
    float max_health;
    float current_health;
    int damage;
    float speed;
    int crit_chance;
    int crit_damage;
    int block_chance;
    int dir;
};
typedef struct player_struct player_t;

struct tile_struct {
    sfSprite *sprite;
};
typedef struct tile_struct tile_t;

struct map_struct {
    int cols;
    int lines;
    char **char_t;
    tile_t **map;
};
typedef struct map_struct map_t;

struct player_animations
{
    struct animation idle;
    struct animation walk;
    struct animation attack;
    /*sfTexture **run;
    sfTexture **got_hit;
    sfTexture **death;*/
};
typedef struct player_animations player_anims;

struct slime_animations
{
    struct slime_animation idle;
    struct slime_animation walk;
    struct slime_animation attack;
    /*sfTexture **run;
    sfTexture **got_hit;
    sfTexture **death;*/
};typedef struct slime_animations slime_anims;

struct scene_s {
    sfSprite *bg;
    int **col;
    int enemy_count;
    enemy_t *enemies;
};
typedef struct scene_s scene_t;

struct objects_in_game {
    sfRenderWindow *win;
    sfVector2f map_pos;
    int scene_index;
    scene_t scenes[13];
    map_t map;
    player_t player;
    int player_move;
    int player_attack;
    player_anims anims;
    slime_anims s_anims;
    int anim_count;
    sfSound **sounds;
};
typedef struct objects_in_game data_t;

struct game_clocks {
    sfClock *player_move;
    sfClock *player_anim;
    sfClock *enemy_move;
    sfClock *enemy_anim;
};
typedef struct game_clocks clocks_t;

typedef struct button button;
struct button{
    const sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int hidden;
    sfVector2i state;
    void (*callback)();
};

typedef struct menu_t menu_t;
struct menu_t {
    int state;
    button *buttons;
    sfSprite *bg;
    sfSprite *hover;
    sfSprite *title;
};

enum sounds_name {
    // e_1,
    // e_2,
    // e_4,
    // e_5,
    // e_click,
    // e_epee,
    // e_level_up,
    // e_medieval,
    // e_monster,
    // e_monster2,
    // e_notification,  
    e_sword,
    // e_unlock,
    e_nb_sounds
};

int check_error(int ac, char **av, char **env);
void init_game_objects(data_t *data, clocks_t *clocks);
void check_hover(sfRenderWindow *window, menu_t *menu, int states);
int menu(sfRenderWindow *window, sfEvent *event);
int input_event_manager(data_t *data, clocks_t *clocks,
sfEvent event);

int button_is_clicked(button button, sfVector2f click_pos);
void init_button(button *button, sfVector2f position, sfVector2f size
, char *path);
int check_buttons(sfEvent event, button *button, menu_t *menu);

void player_movement(data_t *data, clocks_t *clocks);
void player_animation(data_t *data, clocks_t *clocks);
void move_anim_rect(sfIntRect *rect, int offset, int max_value);

void setup_enemies(data_t *data);
void malloc_enemies_and_set_pos(data_t *data);

void load_map(data_t *data);
void set_map_texture(map_t *data, int i, int j);
void init_bg(data_t *data);
void map_check(data_t *data);

int s_index(int x, int y);
void load_txts(data_t *data);

char *my_putnbr_str(char *str, char *tmp, int nb, int start_index);
int count_int_size(int nb);

void init_sound(data_t *data);

int act(int state, menu_t *menu);
int check_gamepad(sfEvent event, menu_t *menu, int *state);