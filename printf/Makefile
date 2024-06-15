NAME = libftprintf.a

HEADER = ft_printf.h

SRCS =	ft_printf.c \
		ft_putchr.c \
		ft_putint.c \
		ft_putstr.c \
		ft_putdec.c \
		ft_puthex_min.c \
		ft_puthex_max.c \
		ft_putmem.c \

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

$(NAME): $(OBJS) 
	@ar rcs $(NAME) $(OBJS)

%.o:%.c Makefile ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean:     clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
