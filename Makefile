NAME = fdf

SRC  = ./sources/keys.c ./sources/fill_struct.c ./sources/init.c ./sources/main.c ./sources/reader.c ./sources/additional.c ./sources/drawer.c ./sources/image.c ./sources/hooks.c ./sources/colors.c ./sources/rotate.c ./sources/transform.c

OBJ  = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -O3

OSVER := $(shell uname -s)

ifeq ($(OSVER), Linux)
	LIBFLAGS = -lmlx -lXext -lX11 minilibx/libmlx.a -lm
else
	LIBFLAGS = -framework OpenGL -framework AppKit -lm -lmlx
endif

LIBFT = libft/libft.a

INC_LIB = libft

HEAD = libft/libft.h

RED= \033[1;31m
GREEN= \033[1;32m
YELLOW= \033[1;33m
BLUE= \033[1;34m
VIOLET= \033[1;35m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(FLAGS) $(OBJ) $(LIBFT) $(LIBFLAGS) -I$(INC_LIB) -o $(NAME)
	@echo "$(GREEN)Project is successfully compiled"

$(LIBFT):
	@echo "$(GREEN)Compiling library files$(VIOLET)"
	make -C libft/

%.o : %.c
	gcc $(FLAGS) -c $< -o $@ -I$(INC_LIB)

clean:
	@echo "$(RED)Suspending library files$(VIOLET)"
	make -C libft clean
	rm -rf *.o

fclean: clean
	@echo "$(RED)Suspending project files$(VIOLET)"
	make -C libft fclean
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all
