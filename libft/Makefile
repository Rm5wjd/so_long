NAME = libft.a
CC = cc
CFLAGS = -Werror -Wall -Wextra
SRCS = ft_isalpha.c \
		ft_memcpy.c \
		ft_strlcpy.c \
		ft_toupper.c \
		ft_isascii.c \
		ft_memmove.c \
		ft_strlen.c \
		ft_isdigit.c \
		ft_memset.c \
		ft_strncmp.c \
		ft_bzero.c \
		ft_isprint.c \
		ft_strchr.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_memchr.c \
		ft_strdup.c \
		ft_strrchr.c \
		ft_isalnum.c \
		ft_memcmp.c \
		ft_strlcat.c \
		ft_tolower.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_split.c \
			get_next_line.c \
			get_next_line_utils.c \
		ft_pharsing.c \
		ft_printf_utils1.c \
		ft_printf_utils2.c \
		ft_printf.c \
		ft_put_all.c \
		ft_put_utils1.c \
		ft_put_utils2.c \
		ft_boxing.c \
		ft_combination.c \
		ft_putnbr_base.c \
		ft_printf_atoi.c

OBJS = ${SRCS:.c=.o} 

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

