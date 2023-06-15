SRCS	=	srcs/Base.cpp\
			main.cpp

INCLUDES=	includes

OBJS	=	${SRCS:.cpp=.o}

NAME	=	identify

CC		=	c++

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

%.o:	%.cpp
	${CC} ${CFLAGS} -I${INCLUDES} -c $< -o $@

${NAME}:	${OBJS}
	${CC} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean
	make all

.PHONY:	all clean fclean re