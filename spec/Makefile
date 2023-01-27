NAME = $(TEST:.c=.o)
CC = gcc
CFLAGS =  -Wall -Werror -Wextra
# CFLAGS += -fsanitize=address -g3
BS = -D BUFERSIZE=100
FRAMEWORK = -framework Cocoa -framework OpenGL -framework IOKit
TEST = fdf_test.c
SRCS = iso_proj.c\
       draw_line.c\
	   get_map.c\
	   parser.c\
	   draw_map.c\
	   scale_map.c\
	   rotate_map.c\
# OBJS = $(SRCS:.c=.o)
HEADER = -I ../MLX42/include/MLX42/ -I ../GNL/src/
LIBMLX = "../MLX42/"
# LIBFT = "../Libft/"
LIBGNL = "../GNL"
LIBGLFW = "../glfw-3.3.8/lib-x86_64/"

all: $(NAME)

$(NAME): $(TEST) libmlx42 libgnl#$(OBJS)#
	$(CC) $(CFLAGS) $(TEST) $(SRCS) $(HEADER) -L $(LIBGNL) -lgnl -L $(LIBMLX) -lmlx42 -L $(LIBGLFW) -lglfw3 $(FRAMEWORK) -o $(NAME)

# $(OBJS): $(SRCS)
# 	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)
#	make fclean -C ../MLX42/
	make fclean -C ../GNL/
#   make fclean -C ../Libft/

fclean: clean
	rm -f $(NAME)

re: fclean all

# libft:
# 	make -C ../Libft/

libgnl:
	make -C ../GNL/

libmlx42:
	make HEADERS='-I ../glfw-3.3.8/include/' -C ../MLX42/

#-L "/Users/$$USER/.brew/opt/glfw/lib/" -lglfw
