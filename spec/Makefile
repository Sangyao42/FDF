NAME = $(TEST:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
TEST = fdf_test.c
SRCS = iso_proj.c\
       draw_line.c\
# OBJS = $(SRCS:.c=.o)
HEADER = -I ../MLX42/include/MLX42/
LIBMLX = "../MLX42/"

all: $(NAME)

$(NAME): $(TEST) #$(OBJS)#
	$(CC) $(CFLAGS) $(HEADER) $(TEST) $(SRCS) -L $(LIBMLX) -lmlx42 -L "/Users/$$USER/.brew/opt/glfw/lib/" -lglfw -o $(NAME)

# $(OBJS): $(SRCS)
# 	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
