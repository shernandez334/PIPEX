NAME = libft.a

HEADER = libft.h get_next_line/get_next_line.h

SRCS = 	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_strlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_split.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		ft_strcmp.c \
		ft_strjoin_ppx.c 
	
BSRCS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c			

OBJS = ${SRCS:.c=.o}

BOJCS = ${BSRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o:%.c Makefile ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS} ${BOJCS}

fclean: 	clean
	rm -f ${NAME} .do_bonus	

re: fclean all

bonus: do_bonus

do_bonus: ${NAME} ${BOJCS} Makefile ${HEADER} ${OBJS}
	@ar rcs	${NAME} ${BOJCS} ${OBJS}
	@touch .do_bonus

.PHONY: all clean fclean re bonus
