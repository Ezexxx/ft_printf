CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

AR = ar rcs

SRCS =  ft_printf_apphex.c \
		ft_printf.c          ft_putnbr.c \
		ft_printf_lowhex.c   ft_putstr.c \
		ft_printf_ptrhex.c \
		ft_putchar.c         ft_unsputnbr.c \

OBGS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c ft_printf.h 
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBGS)
	$(AR) $(NAME) $(OBGS)

clean :
	rm -rf $(OBGS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean all re
