# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 01:30:36 by aidgomez          #+#    #+#              #
#    Updated: 2022/11/03 01:30:36 by aidgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Declaración de variables:
# \---------------------------------------------------/
# Nombre del programa y header
NAME = libft.a
HDRS = libft.h

# Archivos de código fuente
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
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

# Archivos de código objeto
OBJS = $(SRC:.c=.o)

# Archivos de código fuente BONUS
BONUS =	ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \

# Archivos de código objeto
BONUSOBJS = $(BONUS:.c=.o)

# Flags de compilación
CFLAGS = -Wall -Werror -Wextra

# Comando de compilación
CC = gcc

# Remove si existen
RM = rm -f
# \----------------------------------------------------/

# Reglas:
# \---------------------------------------------------/
# Regla que genera los OBJS de SRC.
.c.o:
	@echo "Compilando..."
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

# Regla que compila el programa principal.
$(NAME):$(OBJS) $(HDRS)
	ar -crs $(NAME) $(OBJS)
	@echo "$(NAME) se ha generado!"

# Se ejecuta con el comando make y compila el archivo principal
all: $(NAME)

# Borra todos los archivos .o si los hubiese (-f)
clean:
	$(RM) *.o
	@echo "Archivos borrados"

# Borra todos los archivos y el programa
fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) borrado"

# Realiza un re-make (borra y hace make)
re: fclean all

bonus: $(OBJS) $(BONUSOBJS)
	ar -crs $(NAME) $(OBJS) $(BONUSOBJS)

# Indica que estos nombres no son archivos sino acciones
.PHONY: all clean fclean re bonus
# \----------------------------------------------------/