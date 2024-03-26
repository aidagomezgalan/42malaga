/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:41:52 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/26 18:29:53 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//Constants
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define HEX_LOWERCASE "0123456789abcdef"
# define HEX_UPPERCASE "0123456789ABCDEF"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(char *str);
long	ft_atol(char *str);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_node	*ft_lstnew(void *content);
void	ft_lstadd_front(t_node **lst, t_node *new);
int		ft_lstsize(t_node *lst);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstdelone(t_node *lst, void (*del)(void *));
void	ft_lstclear(t_node **lst, void (*del)(void *));
void	ft_lstiter(t_node *lst, void (*f)(void*));
t_node	*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *));
int		ft_str_count(char const *s, char c);
char	*get_next_line(int fd);
int		ft_len_nbr(long n);
char	*ft_itoau(unsigned int n);
int		array_len(char **str);
char	**fd_to_array(char *str);
int		ft_printf(const char *str, ...);
int		ft_printchar(int c);
int		ft_putnbr(int nb);
int		ft_putnbru(unsigned int nb);
int		ft_printhex(unsigned long long n, int base);
int		ft_printptr(unsigned long ptr);
int		ft_printstr(char *str);
void	memory_str_free(char **temp);

#endif
