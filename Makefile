NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I include -I mlx -I src/get_next_line
MLX = mlx/libmlx.a
SRCDIR = src
OBJDIR = obj
SRCS = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/get_next_line/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(MLX) -lm -lX11 -lXext

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR) $(OBJDIR)/get_next_line
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX):
	$(MAKE) -C mlx

clean:
	$(MAKE) -C mlx clean
	rm -f $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
