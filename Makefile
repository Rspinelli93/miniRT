NAME        = minirt

# --- Manual File Listing ---
SRCS        = main.c \
              src/initalisation.c \
              src/my_mlx_functions.c \
              src/put_blue_screen.c \
              src/parsing/parse.c \
			  src/parsing/sub_parsing1.c \
			  src/parsing/sub_parsing2.c \
			  src/parsing/sub_parsing_utils1.c \
			  src/parsing/sub_parsing_utils2.c \
			  src/parsing/ft_atof.c \
			  src/free/free.c \
			  src/free/safe_free_lst.c
			  src/init/init.c \
			  src/init/init_shapes.c \

# This converts src/xxx.c to obj/xxx.o
OBJS        = $(SRCS:src/%.c=obj/%.o)

# --- Compilation Settings ---
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -ffast-math
INCLUDE     = -Isrc -I./minilibx_linux -I./libft -I./libftprintf -I./gnl
RM          = rm -f

# --- Library Paths ---
MLX_LIB     = ./minilibx_linux/libmlx.a
PRINTF_LIB  = ./libftprintf/libftprintf.a
LIBFT_LIB   = ./libft/libft.a
GNL_LIB     = ./gnl/get_next_line.a

# Linking: MiniLibX usually needs these specific flags for X11
MLX_FLAGS   = -L./minilibx_linux -lmlx_Linux -lXext -lX11 -lm

all : $(NAME)

$(NAME) : $(MLX_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB) -o $(NAME)

# --- Manual Directory Creation ---
# Add every new subdirectory to this mkdir command
obj/%.o: src/%.c
	@mkdir -p obj obj/parsing obj/free
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(MLX_LIB) :
	make -C ./minilibx_linux

$(PRINTF_LIB) :
	make -C ./libftprintf

$(LIBFT_LIB) :
	make -C ./libft

$(GNL_LIB) :
	make -C ./gnl

clean :
	$(RM) -rf obj
	make clean -C ./minilibx_linux
	make clean -C ./libftprintf
	make clean -C ./libft
	make clean -C ./gnl

fclean : clean
	$(RM) $(NAME)
	make fclean -C ./libftprintf
	make fclean -C ./libft
	make fclean -C ./gnl

re : fclean all

.PHONY: all clean fclean re
