NAME = pipex

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

HEAD = pipex.h 

SRCS = main.c \
	   util.c \
	   pipe_init.c \

LIBFT = libft/libft.a

PRINTF = printf/libftprintf.a
 
OBJS = $(SRCS:.c=.o)

all : $(NAME)

libs :
	make -C libft

prints:
	make -C printf

%.o: %.c $(HEAD) Makefile 
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS) libs prints 
	$(CC) $(FLAGS) $(OBJS)  -o $(NAME) -Llibft -lft -Lprintf -lftprintf

clean :
	make clean -C libft
	make clean -C printf
	$(RM) $(OBJS)

fclean :    clean
	make fclean -C libft
	make fclean -C printf
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re libs
