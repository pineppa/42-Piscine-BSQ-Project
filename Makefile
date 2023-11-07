SRCDIR	= ./srcs/
HEAD	= ./includes/
SRCNAME	= main.c utils.c ft_file_check.c ft_file_check_utils.c ft_print_sol.c ft_solver.c ft_reader.c
SRCS	= ${addprefix ${SRCDIR}, ${SRCNAME}}

OBJS	= ${SRCS:.c=.o}

NAME	= bsq

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I ./includes/ $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all: 		${NAME}

sanitize:	${OBJS}
			${CC} -o ${NAME} ${OBJS} "-fsanitize=address"

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.SILENT:
.PHONY:		clean fclean re all
