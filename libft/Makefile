NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../includes -fPIE
EXCFILES := ft_lstnew.c ft_lstsize.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstadd_back.c ft_lstadd_front.c 
EXOBJ = $(EXCFILES:.c=.o)
SRC := ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_bzero.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c ft_isalnum.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strncmp.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_isdigit.c ft_memset.c ft_striteri.c ft_strrchr.c ft_isprint.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c ft_raise.c ft_countc_fd.c ft_identify.c ft_printf.c ft_putnbrc_fd.c ft_putnbr_hex_fd.c ft_putptr_fd.c ft_putstrc_fd.c get_next_line.c get_next_line_utils.c ft_hex_to_nbr.c ft_numlen.c
OBJ = $(SRC:.c=.o)
HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ) $(EXOBJ)
	echo "\033[0m"
	ar rcs $(NAME) $(OBJ) $(EXOBJ)

%.o : %.c
	echo -n "\033[32m| Compiled - $@ |"
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	make

.PHONY: all clean fclean re 
