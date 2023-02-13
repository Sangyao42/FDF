NAME = fdf
CC = gcc
CFLAGS =  -Wall -Werror -Wextra
# CFLAGS += -fsanitize=address -g3
CFLAGS += -march=nocona -flto -Ofast
# BS = -D BUFERSIZE=100
FRAMEWORK = -framework Cocoa -framework OpenGL -framework IOKit
SRC_DIR = ./src/
SRCS = check_file.c\
	   parser.c\
	   get_map.c\
	   start_fdf.c\
	   init_map.c\
	   update_coords.c\
	   rotate_map.c\
	   iso_proj.c\
       draw_line.c\
	   draw_iso.c\
	   draw_parallel.c\
	   hooks.c\
	   fdf_utils.c\
	   set_color_range.c\
	   set_color.c\
	   main.c
HEADER = -I ./include -I ./lib/MLX42/include/MLX42/ -I ./lib/GNL/src/
LIBMLX = "./lib/MLX42/"
LIBFT = "./lib/Libft/"
LIBGNL = "./lib/GNL"
LIBGLFW = "./lib/glfw-3.3.8/lib-x86_64/"

all: $(NAME)

$(NAME):  libmlx42 libgnl
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR),$(SRCS)) $(HEADER) -L $(LIBGNL) -lgnl -L $(LIBMLX) -lmlx42 -L $(LIBGLFW) -lglfw3 $(FRAMEWORK) -o $(NAME)

clean:
	rm -f $(OBJS)
#	make fclean -C ./lib/MLX42/
	make fclean -C ./lib/GNL/

fclean: clean
	rm -f $(NAME)

re: fclean all

libgnl:
	make -C ./lib/GNL/

libmlx42:
	make HEADERS='-I ../glfw-3.3.8/include/' -C ./lib/MLX42/

.PHONY: all clean fclean re
