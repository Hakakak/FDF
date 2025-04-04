NAME = fdf
CC = cc
LIBFT = libft/libft.a
MLX = minilibx/libmlx.a
HDRS = includes/fdf.h includes/fdf_types.h
CFLAGS = -Wall -Wextra -Werror -Iincludes -Iminilibx -I/usr/include -Ilibft -fsanitize=address
CLINK = -Lminilibx -lmlx -L/usr/lib -lXext -lX11 -lm -Llibft -lft
SRC := ft_fdf.c ft_draw_line.c ft_draw_map.c ft_initmlx.c utils/ft_pixinit.c utils/ft_fill_map.c utils/ft_plstut.c
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ) $(HDRS)
	@$(CC) $(CFLAGS) $(OBJ) $(CLINK) -o $(NAME)
	@echo "Created or modified the fdf"

#%.o : %.c
#	$(CC) -c $(CFLAGS) $(CLINK) $< -o $@

clean:
	@make -C libft clean
	@make -C minilibx clean
	@rm -f $(OBJ)
	@echo "Cleared compiled files"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "Also the fdf"

re: fclean all

$(MLX):
	@make -C minilibx

$(LIBFT):
	@make -C libft

.PHONY: all clean fclean re
