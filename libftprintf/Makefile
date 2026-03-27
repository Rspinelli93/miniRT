NAME = libftprintf.a
SRCS = ft_printarg.c \
	ft_printf.c \
	ft_putchar.c \
	ft_putnbr_hexa.c \
	ft_putnbr_hexalong.c \
	ft_putnbr_u.c \
	ft_putnbr.c \
	ft_putptr.c \
	ft_putfloat.c \
	ft_putstr.c \
	is_in.c \
	parseur.c


OBJS = ${SRCS:.c=.o}
INCLUDE = libftprintf.h
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror


.c.o :
	${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}


clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
