NAME        = minirt

# --- Manual File Listing ---
SRCS        = main.c \
			  src/init/initalisation.c \
			  src/init/init_data.c \
			  src/init/init_ambient.c \
			  src/window/my_mlx_functions.c \
			  src/window/pixel_color.c \
			  src/window/viewport.c \
			  src/window/distance_objects.c \
			  src/window/pixel_shadow.c \
			  src/window/put_light.c \
			  src/parsing/parse.c \
			  src/parsing/parse_shapes.c \
			  src/parsing/parse_ambient.c \
			  src/parsing/parse_utils1.c \
			  src/parsing/parse_utils2.c \
			  src/parsing/ft_atof.c \
			  src/utils/utils1.c \
			  src/utils/utils2.c \
			  src/utils/utils_maths1.c \
			  src/utils/utils_maths2.c \
			  src/free/free.c \
			  src/free/free_utils.c \
			  gnl/get_next_line.c \
			  gnl/get_next_line_utils.c

# This converts src/xxx.c to obj/xxx.o
OBJS        = $(SRCS:src/%.c=obj/%.o)

# --- Compilation Settings ---
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -ffast-math
INCLUDE     = -Isrc -I./minilibx_linux -I./libft -I./libftprintf -I./gnl
RM          = rm -f

# --- Library Paths ---
MLX_LIB     = ./minilibx_linux/libmlx.a
LIBFT_LIB   = ./libft/libft.a

# Linking: MiniLibX usually needs these specific flags for X11
MLX_FLAGS   = -L./minilibx_linux -lmlx_Linux -lXext -lX11 -lm

all : $(NAME)

$(NAME) : $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_LIB) -o $(NAME)

# --- Manual Directory Creation ---
# Add every new subdirectory to this mkdir command
obj/%.o: src/%.c
	@mkdir -p obj obj/parsing obj/free obj/init obj/utils obj/window obj/gnl
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(MLX_LIB) :
	make -C ./minilibx_linux

$(LIBFT_LIB) :
	make -C ./libft

clean :
	$(RM) -rf obj
	make clean -C ./minilibx_linux
	make clean -C ./libft

fclean : clean
	$(RM) $(NAME)
	make clean -C ./minilibx_linux
	make fclean -C ./libft

re : fclean all

.PHONY: all clean fclean re
