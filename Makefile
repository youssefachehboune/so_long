# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 16:42:44 by yachehbo          #+#    #+#              #
#    Updated: 2022/02/25 19:06:32 by yachehbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
all: so_long
bonus: so_long_bonus
RM = rm -rf
CFLAGS = -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror
PRINTF = Mandatory/src/ft_printf/ft_putchar.c Mandatory/src/ft_printf/ft_putnbr_unsigned.c \
	Mandatory/src/ft_printf/ft_putstr.c Mandatory/src/ft_printf/ft_print_hex.c \
	Mandatory/src/ft_printf/ft_printf.c Mandatory/src/ft_printf/ft_pointer.c \
	Mandatory/src/ft_printf/ft_putnbr.c 
SRCS = Mandatory/so_long.c Mandatory/read_map.c Mandatory/check_map.c \
 	Mandatory/game_init.c Mandatory/src/ft_split.c \
	Mandatory/src/get_next_line_utils.c  Mandatory/src/get_next_line.c Mandatory/map_set.c \
	Mandatory/src/ft_strcpy.c  Mandatory/game.c \
	Mandatory/src/ft_strdup.c   Mandatory/player_moves.c
SRCS_BONUS = Bonus/so_long.c Bonus/read_map.c Bonus/check_map.c \
 	Bonus/game_init.c Bonus/src/ft_split.c Bonus/src/ft_itoa.c \
	Bonus/src/get_next_line_utils.c  Bonus/src/get_next_line.c Bonus/map_set.c \
	Bonus/src/ft_strcpy.c  Bonus/game.c  Bonus/game_render.c  Bonus/game_update.c\
	Bonus/src/ft_strdup.c   Bonus/player_moves.c Bonus/key_bonus.c Bonus/enemy_animation.c
so_long: Mandatory/so_long.h $(SRCS)
	cc $(CFLAGS) $(SRCS) $(PRINTF) -o $(NAME)
so_long_bonus: Bonus/so_long.h $(SRCS_BONUS)
	cc $(CFLAGS) $(SRCS_BONUS) $(PRINTF) -o so_long_bonus
clean:
	$(RM) so_long
fclean: clean
	$(RM) so_long_bonus
re: fclean all

.PHONY: all clean fclean re so_long so_long_bonus

