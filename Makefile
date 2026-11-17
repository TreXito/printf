NAME = libftprintf.a
all: $(NAME)
CC = cc
CFLAGS = -Wextra -Werror -Wall -Wfatal-errors
CFILES = ft_printf.c ft1.c ft2.c
OFILES = $(CFILES:.c=.o)
$(NAME) : $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean: 
	$(RM) $(OFILES)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean redas