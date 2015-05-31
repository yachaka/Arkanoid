# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/03 22:55:20 by ihermell          #+#    #+#              #
#    Updated: 2015/05/10 10:48:43 by ihermell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME		= arkanoid

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Ofast -Wno-deprecated-declarations

SRC_DIR		= src/
SRC_NAME	=	main.c\
				init.c \
				\
				create_map.c\
				\
				get_next_line/get_next_line.c\
				\
				glfw_error.c \
				glfw_key_callbacks.c \
				glfw_mouse_callbacks.c \
				gl_circle.c \
				\
				brick.c \
				\
				render.c \
				\
				process.c \
				\
				move_bar.c \
				\
				ball.c \
				\
				bridge_collision.c \
				collision.c \
				\
				print_text.c \
				get_level.c \
				\
				game.c \
				\
				utils.c

SRC			= $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_DIR		= obj/
OBJ_NAME	= $(SRC_NAME:.c=.o)
OBJ			= $(addprefix $(OBJ_DIR),$(OBJ_NAME))

LIBFT_DIR	= Libft/
LIBFT_NAME	= libft.a
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

#use -l and -L

GLFW_CLONE	= glfw-clone/
GLFW_BUILD	= glfw-build/
GLFW_NAME	= src/libglfw3.a
GLFW		= $(addprefix $(GLFW_BUILD), $(GLFW_NAME))

INC_DIR		= -I $(addprefix $(GLFW_CLONE), include/) \
			  -I $(addprefix $(LIBFT_DIR), include) \
			  -I include/ \
			  -I 3DSPACE/include

LIBRARIES	= -L $(LIBFT_DIR) -lft -L$(GLFW_BUILD)/src/ -lglfw3 -framework\
			  Cocoa -framework OpenGL -framework IOKit -framework CoreVideo\
			  -framework GLUT ./3DSPACE/space3d.a

all : $(NAME)

$(NAME): $(LIBFT) $(GLFW) $(SRC)
	$(CC) $(CFLAGS) $(INC_DIR) $(LIBRARIES) $(SRC) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $<;
	@mkdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GLFW):
	git submodule add -f https://github.com/glfw/glfw.git $(GLFW_CLONE)
	@mkdir $(GLFW_BUILD) 2> /dev/null
	cd $(GLFW_BUILD); \
		pwd; \
		cmake ../$(GLFW_CLONE)
	make -C $(GLFW_BUILD)

clean:
	rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null
	make -C $(LIBFT_DIR) clean

glfw_clean:
	make -C $(GLFW_BUILD) clean

glfw_fclean:
	make -C $(GLFW_BUILD) fclean

glfw_build_clean:
	rm -rf $(GLFW_BUILD) 2> /dev/null || echo '' > /dev/null

glfw_complete_clean: glfw_build_clean
	rm -rf $(GLFW_CLONE) 2> /dev/null || echo '' > /dev/null

libft_clean:
	make -C $(LIBFT_DIR) clean

libft_fclean:
	make -C $(LIBFT_DIR) fclean
#add special clean rules for libft and glfw

fclean: clean
	rm -rf $(NAME)

re: fclean all
