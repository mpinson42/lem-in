NAME = libftprintf.a

SRC = 	./srcs/ft_printf.c ./srcs/ft_choise.c ./srcs/ft_lecture.c ./libft/ft_putchar.c ./libft/ft_putstr.c ./libft/ft_strchr.c ./libft/ft_strjoin.c \
		./libft/ft_strsub.c ./libft/ft_toupper.c ./libft/ft_absolut.c ./libft/ft_isdigit.c ./libft/ft_itoa.c ./libft/ft_itoa_base.c ./libft/ft_itoa.c \
		./libft/ft_atoi.c ./libft/ft_strcpy.c ./libft/ft_bzero.c ./libft/ft_strlen.c ./libft/ft_strcmp.c ./libft/ft_atoi.c ./libft/ft_unsigned_itoa_base.c \
		./libft/ft_memcpy.c ./libft/ft_uni_putchar.c ./libft/ft_uni_strlen.c ./libft/ft_uni_strsub.c ./libft/ft_uni_putstr.c ./libft/ft_pushback.c \
		./libft/ft_uni_strcmp.c ./libft/ft_atoi_base.c ./srcs/ft_string.c ./srcs/ft_uni_string.c ./srcs/ft_int.c ./srcs/ft_char.c ./srcs/ft_base.c \
		./libft/ft_ftoa.c ./libft/ft_strjoin_free.c ./libft/ft_strdel.c ./srcs/largeur_int.c ./srcs/conv_int.c ./srcs/ft_largeur_int2.c \
		./srcs/ft_conv_base.c ./srcs/ft_ptr.c ./srcs/ft_largeur_str.c ./srcs/presision_str.c ./srcs/ft_largeur_uni.c ./srcs/ft_presision_uni.c \
		./srcs/ft_lecture2.c ./libft/ft_strrev.c ./libft/ft_strdup.c ./libft/ft_uni_strdup.c

FLAGS = -Wall -Wextra -Werror

SRC2 = 	ft_printf.o ft_choise.o ft_lecture.o ft_putchar.o ft_putstr.o ft_strchr.o ft_strjoin.o \
		ft_strsub.o ft_toupper.o ft_absolut.o ft_isdigit.o ft_itoa.o ft_itoa_base.o ft_itoa.o \
		ft_atoi.o ft_strcpy.o ft_bzero.o ft_strlen.o ft_strcmp.o ft_atoi.o ft_unsigned_itoa_base.o \
		ft_memcpy.o ft_uni_putchar.o ft_uni_strlen.o ft_uni_strsub.o ft_uni_putstr.o ft_pushback.o \
		ft_atoi_base.o ft_uni_strcmp.o ./ft_string.o ./ft_uni_string.o ./ft_int.o ./ft_char.o ./ft_base.o \
		./ft_ftoa.o ft_strjoin_free.o ./ft_strdel.o ./largeur_int.o ./conv_int.o ft_largeur_int2.o ft_conv_base.o \
		ft_ptr.o ft_largeur_str.o presision_str.o ft_largeur_uni.o ft_presision_uni.o ft_lecture2.o ft_strrev.o ft_strdup.o \
		./ft_uni_strdup.o

all: $(NAME)

$(NAME): $(SRC)
	@echo "mpinson" > auteur
	gcc -c $(FLAGS) $(SRC)
	ar rc $(NAME) $(SRC2)
	ranlib $(NAME)

clean:
	/bin/rm -f $(SRC2)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME) libft/libft.a
	make -C ./libft fclean

re: fclean all
