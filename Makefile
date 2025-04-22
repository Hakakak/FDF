NAME = fdf
CC = cc
LIBFT = libft/libft.a
MLX = minilibx/libmlx.a
CFLAGS = -Wall -Wextra -Werror -Iincludes -Iminilibx -Ilibft
CLINK = -Lminilibx -lmlx -L/usr/lib -lXext -lX11 -lm -Llibft -lft
SRC := ft_fdf.c ft_draw_line.c ft_draw_map.c ft_initmlx.c utils/ft_pixinit.c utils/ft_fill_map.c utils/ft_plstut.c utils/ft_draw_utils.c
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(CLINK) -o $(NAME)
	@echo "Created or modified the fdf"

%.o : %.c
	@$(CC) -c $(CFLAGS) $< -o $@

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
