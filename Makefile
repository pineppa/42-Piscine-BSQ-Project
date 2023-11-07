SRCDIR	= ./srcs/
HEAD	= ./includes/
SRCNAME	= *.c
SRCS	= ${addprefix ${SRCDIR}, ${SRCNAME}}

OBJS	= ${SRCS:.c=.o}

NAME	= bsq

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all: 		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.SILENT:
.PHONY:		clean fclean re all
