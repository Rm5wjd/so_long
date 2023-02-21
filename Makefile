NAME=so_long
CC=cc
CFLAGS=-Wall -Werror -Wextra -g

LIB=libft.a
LIB_PATH=libft
LIBMLX=libmlx.a
DYLD_LIBRARY_PATH=minilibx_opengl_20191021

RM=rm -rf

SRCS= $(addprefix srcs/, main.c color.c key_event.c init.c \
		file_extension_check.c map_parsing.c map_valid_check.c \
		queue.c bfs.c bfs_utils.c \
		player_left_sprite_init.c player_right_sprite_init.c rendering.c \
		key_release.c player_collision.c tile_setting.c wasd_pos_set.c \
		enemy_left_sprite_init.c enemy_right_sprite_init.c enemy_collision.c enemy_spawn.c \
		so_long_utils.c so_long_utils2.c so_long_utils3.c)
OBJS=$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -I. -I$(DYLD_LIBRARY_PATH) $(DYLD_LIBRARY_PATH)/$(LIBMLX) -framework OpenGL -framework Appkit -o $(NAME) $(LIB_PATH)/$(LIB)

%.o:%.c
	$(CC) -I. -I$(DYLD_LIBRARY_PATH) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(OBJS) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
