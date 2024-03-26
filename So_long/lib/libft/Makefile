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
NAME = libft

# Source code files
SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_atol.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strjoin_free.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_len_nbr.c \
	ft_itoau.c \
	array_len.c \
	fd_to_array.c \
	get_next_line.c \
	memory_str_free.c \
	printf/ft_printchar.c \
	printf/ft_printdec.c \
	printf/ft_printhex.c \
	printf/ft_printptr.c \
	printf/ft_printstr.c \
	printf/ft_printf.c

# Object code files
OBJS = $(SRC:.c=.o)
#OBJS_PRINTF = $(SRC_PRINTF:.c=.o)

# Compilation flags
CFLAGS = -Wall -Werror -Wextra

# Compile command
CC = gcc

# Remove if exists
RM = rm -f
# \----------------------------------------------------/

# Rules:
# \---------------------------------------------------/
# Rule that generates SRC OBJS
.c.o:
	@echo "Compilando..."
	$(CC) -c $(CFLAGS) $< -o $@

# Rule that compiles the main program and generates the binary (executable) object
$(NAME):$(OBJS)
	ar -crs $(NAME) $(OBJS)
	@echo "$@ has been generated!"

# Run with the make command and compile the main file
all: $(NAME)

# Delete all .o files if any (-f)
clean:
	$(RM) *.o printf/*.o
	@echo "Deleted OBJS files"

# Delete all files and program
fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) deleted"

# Perform a re-make (delete and do make)
re: fclean all

# Indicates that these names are not files but actions
.PHONY: all clean fclean re
# \----------------------------------------------------/
