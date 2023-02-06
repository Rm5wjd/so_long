NAME=so_long
CC=cc
CFLAGS=-Wall -Werror -Wextra -g

LIB=libft.a
LIB_PATH=libft
LIBMLX=libmlx.a
DYLD_LIBRARY_PATH=minilibx_opengl_20191021

RM=rm -rf

SRCS= main.c color.c key_event.c init.c map_pharsing.c map_valid_check.c queue.c bfs.c
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
