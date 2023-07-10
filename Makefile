SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD
CFLAGS += -g3
# CFLAGS += -fsanitize=address

LIBFT = libft/libft.a
NAME = ft_nm

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

ffclean: fclean
	make -C libft fclean

re: fclean all

rere: ffclean all

$(LIBFT):
	make -C libft

bonus: all

-include $(DEPS)

.PHONY: all clean fclean ffclean re rere
