NAME = lem-in

SRC =

FLAGS = -Wall -Wextra -Werror

SRC2 =

all: $(NAME)

$(NAME): $(SRC)
	@echo "mpinson" > auteur
	@make -C ./libft all
	@cp ./libft/libft.a ./lib
	gcc $(FLAGS) -I ./include/ -L/usr/local/lib/ -L./lib -I/usr/local/include -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(SRC)


clean:
	/bin/rm -f $(SRC2)
	@make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
