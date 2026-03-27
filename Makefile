NAME = minirt
SRC_DIR = src
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.c)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INCLUDE = $(SRC_DIR)/minirt.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -O3 -ffast-math
MLX = ./minilibx_linux
PRINTF = ./libftprintf

MLX_LNK = -L $(MLX) -lmlx_Linux -lXext -lX11 -lm
PRINTF_LNK = -L $(PRINTF) -lftprintf

MLX_INC = I $(MLX)
MLX_LIB = $(MLX)/libmlx.a
PRINTF_LIB = $(PRINTF)/libftprintf.a

$(NAME) : $(MLX_LIB) $(PRINTF_LIB) $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(MLX_LNK) $(PRINTF_LNK) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE) | $(OBJ_DIR)
	gcc $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(MLX_LIB) :
	make -C $(MLX)

$(PRINTF_LIB) :
	make -C $(PRINTF)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make clean -C $(MLX)
	make fclean -C $(PRINTF)

clean :
	$(RM) -rf $(OBJ_DIR)
	make clean -C $(MLX)
	make clean -C $(PRINTF)

re : fclean all
