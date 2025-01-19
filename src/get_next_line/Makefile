NAME = get_next_line.a

CC = cc

CFLAGS = -Wextra -Wall -Werror

AR = ar -rc

SRC = get_next_line.c get_next_line_utils.c

OBJCS = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJCS}
	${AR} ${NAME} ${OBJCS} 

%.o : %.c get_next_line.h
	${CC} ${CFLAGS} -c $< -o $@

clean : 
	rm -rf ${OBJCS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : clean