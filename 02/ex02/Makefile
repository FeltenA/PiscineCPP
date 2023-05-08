SRCS	=	src/Fixed.cpp\
			main.cpp

INCLUDES=	include

OBJS	=	${SRCS:.cpp=.o}

NAME	=	fixedPoint

CC		=	c++

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

%.o:	%.cpp
	${CC} ${CFLAGS} -Iinclude -c $< -o $@

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