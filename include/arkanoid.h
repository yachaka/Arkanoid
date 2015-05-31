/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:52:29 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 23:34:58 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include <sys/uio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <GLUT/glut.h>
# include <dirent.h>
# include "GLFW/glfw3.h"

# include "space3d.h"
# include "libft.h"
# include "game.h"

# define FALSE 0
# define TRUE 1

# define LIGHT_BLUE 102.0f, 255.0f, 255.0f
# define RED	255.0f, 51.0f, 0.0f
# define ORANGE	255.0f, 153.0f, 51.0f
# define YELLOW	255.0f, 204.0f, 102.0f
# define BLACK	0.0f, 0.0f, 0.0f
# define WHITE	1.0f, 1.0f, 1.0f

typedef char		t_bool;

typedef struct		s_env
{
	GLFWwindow		*window;
	int				w_width;
	int				w_height;
	t_game			*game;
}					t_env;

typedef struct dirent	t_dirent;

t_env				*init_env();
GLFWwindow			*init_glfw(int width, int height, const char *title);
t_game				*init_game();

void				glfw_key_callback(GLFWwindow *window, int key,
					int scancode, int action, int mods);
void				glfw_key_press_callback(GLFWwindow *window, int key,
					int scancode, int mods);
void				glfw_key_release_callback(GLFWwindow *window, int key,
					int scancode, int mods);
void				glfw_mouse_move_callback(GLFWwindow *window, double x,
					double y);
void				glfw_mouse_button_callback(GLFWwindow *window, int button,
					int action, int mods);

void				glfw_error_callback(int error, const char *description);
void				gl_circle(float x, float y, float r, int segments);

void				calc_bricks_f(t_map *map, t_brick *bricks, int n);
t_brick				new_brick(int x, int y, int width, int height);
char				brick_hit_at(t_ball *ball, t_brick *b);
void				brick_got_hit(t_brick *brick, t_game *game);

void				render(t_game *game);
void				render_ball(t_ball *ball);
void				render_bar(t_bar *bar, t_settings *s);
void				render_brick(t_brick *brick);

void				process(t_game *game);
void				process_collisions(t_game *game);
void				process_screen_collisions(t_game *game);
void				process_bricks_collisions(t_game *game);

void				move_bar(t_game *game, float x);
void				center_bar(t_game *game);

void				throw_ball(t_game *game, float x, float y);
void				spawn_ball(t_game *game);
void				move_ball(t_game *game);
void				bounce_ball(int hit, t_ball *ball);

char				collision_ball_to_bar(t_ball *ball, t_bar *bar,
					t_settings *s);
char				collision_ball_to_brick(t_ball *ball, t_brick *brick);

t_map				*create_map(char *path);

void				print_text(char *s, float x, float y);

char				*get_level(char *path, int lv);
void				load_level(t_game *game);

void				should_load_next_level(t_game *game);
void				no_levels();
void				win_game(t_game *game);
void				lose_game(t_game *game);
void				lose_life(t_game *game);

float				get_width_in_f(GLFWwindow *window, double pixels);
float				get_height_in_f(GLFWwindow *window, double pixels);

#endif
