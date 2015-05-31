# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihermell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/16 16:31:14 by ihermell          #+#    #+#              #
#    Updated: 2015/05/01 03:17:22 by ihermell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, all, re, reclean, fclean
NAME = space3d.a
CFLAGS = -Wall -Wextra -Werror
SOURCES =	intersects/ray2_to_segment2.c \
			intersects/segment2_to_segment2.c \
			intersects/circle2_to_aabb2.c \
			\
			objects/point2/point2.c \
			objects/point2/point2_comparisons.c \
			\
			objects/point3/point3.c \
			objects/point3/point3_comparisons.c \
			\
			objects/ray2/ray2.c \
			\
			objects/segment2/segment2.c \
			\
			objects/vector2/vector2.c \
			objects/vector2/vector2_operations.c \
			objects/vector2/vector2_transformations.c \
			\
			objects/vector3/vector3.c \
			objects/vector3/vector3_operations.c \
			\
			objects/circle2/circle2.c \
			\
			objects/aabb2/aabb2.c \
			\
			utils/true_angle.c
OBJS = $(notdir $(SOURCES:.c=.o))

all: $(NAME)

$(NAME):
	@echo ""
	@echo ".: 2DSPACE Library (c) Whiteyyyy Poseyyy :."
	@echo "-------------------------------------------"
	@echo ""
	@echo "             Compilation ..."
	@echo ""
	@echo ""
	@gcc $(CFLAGS) -c $(SOURCES) -I./include/
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo ">> Alright. SWIFT"
	@echo ""
clean:
	@rm -f $(OBJS)
fclean: clean 
	@rm -f $(NAME)
re: fclean all
reclean: re
	@rm -f $(OBJS)
