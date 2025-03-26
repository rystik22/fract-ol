NAME	=	fractol
CC		= cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm	-rf

SRCS 	=	main.c mandelbrot.c julia.c renderer.c controls.c tricorn.c utils.c

GREEN	=	\033[1;32m
RESET	=	\033[0m

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(SRCS)
	$(MAKE) all -C mlx
	$(CC) $(CFLAGS) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)Compilation finished: Try  ./$(NAME) "0/ 1/ 2" or any two double "-1.0" "0.5"$(RESET)"

clean:
	$(MAKE) clean -C mlx

fclean: clean
	$(RM) $(NAME)
	$(MAKE) clean -C mlx

re: fclean $(NAME)

.PHONY = all clean fclean re
