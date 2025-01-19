NAME			=	so_long

LIBB			=	so_long.a

GET_NEXT_LINE	=	src/get_next_line/get_next_line.a

PRINTF			=	src/ft_printf/libftprintf.a

SRCS 			= 	src/check.c src/map.c src/init.c src/render.c src/utils.c

MLX				= 	mlx/libmlx.a

GCC 			= 	cc

OBJS			=	${SRCS:.c=.o}

LFLAGS			=	-L. -lXext -L. -lX11

CFLAGS			=	-Wall -Werror -Wextra

AR 				= 	 ar -rc

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
PURPLE= \033[38;2;255;105;180m

all				:	${NAME}

$(NAME) : $(OBJS)
	@echo "\t\t\t${GREEN}===========================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}===== MAKE ${PURPLE}SO_LONG ⌛${DEF_COLOR}${GREEN}=====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}===========================${DEF_COLOR}"
	${AR} ${LIBB} ${OBJS}
	@echo "\t\t\t${GREEN}=======================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}===== MAKE ${PURPLE}MLX ⌛${DEF_COLOR}${GREEN}=====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}=======================${DEF_COLOR}"
	@make -C mlx/
	@echo "\t\t\t${GREEN}=================================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}===== MAKE ${PURPLE}get_next_line ⌛${DEF_COLOR}${GREEN}=====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}=================================${DEF_COLOR}"
	@make -C src/get_next_line
	@echo "\t\t\t${GREEN}=============================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}===== MAKE ${PURPLE}FT_PRINTF${DEF_COLOR} ⌛${GREEN} =====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}=============================${DEF_COLOR}"
	@make -C src/ft_printf
	@echo "\t\t\t${GREEN}==============================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}==== ALL IS ${PURPLE}COMPILATED${DEF_COLOR} ✅${GREEN} ====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}==============================${DEF_COLOR}"
	@${GCC} ${LIBB} ${MLX} ${LFLAGS} ${GET_NEXT_LINE} ${PRINTF} -o $(NAME)

%.o : %.c include/so_long.h
	@${CC} ${CFLAGS} -c $< -o $@

clean			:
					make clean -C src/ft_printf
					make clean -C src/get_next_line
					make clean -C mlx/
					rm -rf ${OBJS}
					rm -rf ${LIBB}

fclean			:	clean
					make fclean -C src/ft_printf
					make fclean -C src/get_next_line
					rm -rf ${MLX}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	clean