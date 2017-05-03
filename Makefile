NAME = lem-in

SRC = ./srcs/main.c ./srcs/edit_poid.c ./srcs/ft_resolv.c ./srcs/ft_pars.c ./srcs/get_htag.c ./srcs/get_bridg.c ./srcs/resolv_start.c

FLAGS = -Wall -Wextra -Werror

SRC2 = ./main.o ./edit_poid.o ./ft_resolv.o ./ft_pars.o ./get_htag.o ./get_bridg.o ./resolv_start.o

all: $(NAME)

%.o : %.c
	gcc -c -o $@ $^

$(NAME): $(SRC)
	@echo "mpinson" > auteur
	@make -C ./libft all
	@make -C ./ft_printf
	@cp ./libft/libft.a ./lib
	@cp ./ft_printf/libftprintf.a ./lib
	gcc $(FLAGS) -I ./include/ -L ./lib -lft -lftprintf -o $(NAME) $(SRC)


clean:
	/bin/rm -f $(SRC2)
	@make -C ./libft clean
	@make -C ./ft_printf clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ./libft fclean
	@make -C ./ft_printf fclean

re: fclean all
