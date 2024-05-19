SRCS = fdf.c ./utils/get_next_line.c ./utils/get_next_line_utils.c \
    ./utils/ft_split.c ./utils/ft_strlcpy.c ./utils/ft_bzero.c ./utils/ft_atoi.c \
	 ./utils/dda_algo.c ./utils/map.c ./utils/rotation.c ./utils/ft_atoi_base.c ./utils/ft_strchr.c ./utils/ft_strlen.c ./utils/closing_hook.c\
	 ./utils/zoom_shift.c ./utils/dda_helper.c ./utils/utils.c ./utils/map_utils.c \
	 ./utils/free_mem.c ./utils/mlx_handler.c ./utils/map_handler.c
BSRC = fdf_bonus.c ./utils/hooks.c ./utils/get_next_line.c ./utils/get_next_line_utils.c \
	 ./utils/ft_split.c ./utils/ft_strlcpy.c ./utils/ft_bzero.c ./utils/ft_atoi.c\
	 ./utils/map.c ./utils/rotation.c ./utils/ft_atoi_base.c ./utils/ft_strchr.c ./utils/ft_strlen.c ./utils/closing_hook.c\
	 ./utils/zoom_shift.c ./utils/dda_helper.c ./utils/map_utils.c ./utils/utils_bonus.c ./utils/dda_algo_bonus.c ./utils/free_mem.c\
	./utils/mlx_handler.c ./utils/utils2_bonus.c ./utils/map_handler.c

OBJS = $(SRCS:.c=.o)
BOBJ = $(BSRC:.c=.o)

CC = cc
CFLAGS =  -Wall -Wextra -Werror -g -lmlx -framework OpenGL -framework AppKit
OFLAGS = -Wall -Wextra -Werror -c

NAME = fdf
BNAME = fdf_bonus

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c fdf.h ./includes/get_next_line.h ./includes/libft.h
	$(CC) $(OFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJ)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all

bonus : $(BNAME)

$(BNAME): $(BOBJ)
	$(CC) $(CFLAGS) -o $(BNAME) $(BOBJ)
.PHONY: clean
