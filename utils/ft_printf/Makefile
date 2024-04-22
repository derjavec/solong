
NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRC = ft_printf.c ft_printf_c.c ft_printf_s.c ft_printf_p.c ft_printf_di.c ft_printf_u.c ft_printf_x.c ft_printf_xx.c

IDR = ft_printf.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<  -o $@  -I
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ)
	
re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
