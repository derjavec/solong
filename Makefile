NAME		     =	so_long
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror #-fsanitize=address
RM			=	rm -rf	
SRC			=	so_long.c \
				utils/str_tab_functions/ft_bzero.c utils/str_tab_functions/ft_filelen.c utils/str_tab_functions/ft_freemap.c \
				utils/str_tab_functions/ft_mapdup.c utils/str_tab_functions/ft_strdup.c utils/str_tab_functions/ft_strlcpy.c \
				utils/str_tab_functions/ft_strlen.c utils/str_tab_functions/ft_strncmp.c utils/str_tab_functions/ft_strnstr.c \
				utils/str_tab_functions/ft_strtrim.c \
				utils/list_functions/create_list.c utils/list_functions/ft_lstadd_back.c utils/list_functions/ft_lstclear_solong.c \
				utils/list_functions/ft_lstnew.c \
				utils/textures/assign_textures.c utils/textures/assign_textures_pl_e_c.c utils/textures/assign_textures_env_ex.c \
				utils/hooks/close_game.c utils/hooks/next_level.c utils/hooks/update.c utils/hooks/game_over.c utils/hooks/key.c \
				utils/map_init/assign_level.c utils/map_init/check_maps.c utils/map_init/map_init.c utils/map_init/flood_fill.c\
				utils/game/game_init.c utils/game/move_enemy.c utils/game/move_player.c utils/game/render.c utils/game/animation.c \
				utils/end_game/free_all.c utils/end_game/ft_error.c \
				utils/gnl/get_next_line.c utils/gnl/get_next_line_utils.c \
				utils/ft_printf/ft_printf.c utils/ft_printf/ft_printf_c.c utils/ft_printf/ft_printf_di.c utils/ft_printf/ft_printf_p.c \
				utils/ft_printf/ft_printf_s.c  utils/ft_printf/ft_printf_u.c utils/ft_printf/ft_printf_x.c utils/ft_printf/ft_printf_xx.c \

OBJ			=	$(SRC:.c=.o)
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
HEADER		= so_long.h utils/gnl/get_next_line.h mlx/mlx.h mlx/mlx_int.h utils/ft_printf/ft_printf.h


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)


clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all
	
.PHONY: all clean fclean re
