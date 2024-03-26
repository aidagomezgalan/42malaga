# DEFINITIONS:
# $@ = Rule object $(NAME)
# $^ = Dependencies $(HDRS) and $(OBJS)
# $<: First dependency in the rule (.c source file being compiled)
# -o $(<:.c=.o): Object file name after compilation
# -C: Change directory
# -c: Compile the source file and generate the object, without performing the link stage

# Declaration of variables:
# \---------------------------------------------------/
# Program name and header
NAME = push_swap
HDRS = push_swap.h

# Source code files
SRC =  utils.c \
	data_checker.c \
	stack_commands.c \
	push_swap.c \
	sort_stack.c \
	stack_actions.c \
	movement_cost.c \
	stack_commands_actions.c

# Object code files
OBJS = $(SRC:.c=.o)

# LIBFT bookstore route
LIBFT_PATH = libft/libft.a

# Compilation flags
CFLAGS = -g -Wall -Werror -Wextra #-fsanitize=address

# Compile command
CC = gcc

# Remove if exists
RM = rm -f
# \----------------------------------------------------/

# Rules:
# \---------------------------------------------------/
# Rule that generates SRC OBJS.
.c.o:
	@echo "Compiling..."
	$(CC) -c $(CFLAGS) $< -o $@

# Rule that compiles the main program and generates the binary (executable) object.
$(NAME): $(LIBFT_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) -o $@
	@echo "$@ has been generated!"

# Run with the make command and compile the main file
all: $(NAME)

# Delete all .o files if any (-f)
clean:
	$(RM) *.o
	make -C libft clean
	@echo "Deleted OBJS files"

# Delete all files and program
fclean: clean
	$(RM) $(LIBFT_PATH) $(NAME)
	@echo "$(NAME) and libft deleted"

# Perform a re-make (delete and do make)
re: fclean all

# Library path to compile with your own Makefile
$(LIBFT_PATH):
	make -C libft all

# Indicates that these names are not files but actions
.PHONY: all clean fclean re
# \----------------------------------------------------/
