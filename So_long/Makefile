# DEFINITIONS:
# $@ = Rule object $(NAME)
# $^ = Dependencies $(HDRS) and $(OBJS)
# $<: First dependency in the rule (.c source file being compiled)
# -o $(<:.c=.o): Object file name after compilation
# -C: Change directory
# -c: Compile the source file and generate the object, without performing the link stage

# Declaration of variables:
# \---------------------------------------------------/
# Program name
NAME = so_long
NAME_BONUS = so_long_bonus

# Source code files
SRC =  src/map_checker.c \
	src/map_checker_utils.c \
	src/map_display.c \
	src/so_long.c \
	src/msg.c \
	src/flood_fill.c \
	src/player_actions.c \
	src/key_actions.c \
	src/exit_actions.c \
	src/collectable_actions.c

SRC_BONUS =  src/BONUS/map_checker_bonus.c \
	src/BONUS/map_checker_utils_bonus.c \
	src/BONUS/map_display_bonus.c \
	src/BONUS/so_long_bonus.c \
	src/BONUS/msg_bonus.c \
	src/BONUS/flood_fill_bonus.c \
	src/BONUS/player_actions_bonus.c \
	src/BONUS/key_actions_bonus.c \
	src/BONUS/exit_actions_bonus.c \
	src/BONUS/collectable_actions_bonus.c \
	src/BONUS/enemy_actions_bonus.c

# Object code files
OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

# LIBFT bookstore route
LIBFT_PATH = lib/libft/libft

# MLX42 bookstore route MACOS
MLX42_PATH = lib/MLX42/libmlx42.a

# Compilation flags
CFLAGS = -g -Wall -Werror -Wextra

# Compilation flag MLX42 MACOS
#EXTRA = -Iinclude -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"

# Compilation flag MLX42 Linux
EXTRA = -Iinclude -ldl -lglfw -pthread -lm

# Compile command
CC = gcc

# Remove if exists
RM = rm -f
# \----------------------------------------------------/

# Rules:
# \---------------------------------------------------/
# Rule that generates SRC OBJS
.c.o:
	@echo "Compiling..."
	$(CC) -c $(CFLAGS) $< -o $@

# Rule that compiles the main program and generates the binary (executable) object
$(NAME): $(OBJS) $(LIBFT_PATH) $(MLX42_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) $(MLX42_PATH) $(EXTRA) -o $@
	@echo "$@ has been generated!"

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_PATH) $(MLX42_PATH)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_PATH) $(MLX42_PATH) $(EXTRA) -o $@
	@echo "$@ has been generated!"

# Run with the make command and compile the main file
all: $(NAME)

# Delete all .o files if any (-f)
clean:
	$(RM) src/*.o src/BONUS/*.o
	make -C lib/libft clean
	make -C lib/MLX42 clean
	@echo "Deleted OBJS files"

# Delete all files and program
fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) $(LIBFT_PATH) $(MLX42_PATH)
	rm -rf *.dSYM
	@echo "$(NAME), $(NAME_BONUS), libft and MLX42 deleted"

# Perform a re-make (delete and do make)
re: fclean all

# Bonus compile
bonus: $(NAME_BONUS)

# Library path to compile with your own Makefile
$(LIBFT_PATH):
	make -C lib/libft all
$(MLX42_PATH):
	make -C lib/MLX42 all
# Indicates that these names are not files but actions
.PHONY: all clean fclean re bonus
# \----------------------------------------------------/
