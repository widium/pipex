/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:51:09 by ebennace          #+#    #+#             */
/*   Updated: 2021/10/28 16:55:46 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}t_list;
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_isalpha(int i);
int		ft_isdigit(int n);
int		ft_isalnum(int a);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
int		ft_memcmp( const void *pointer1, const void *pointer2, size_t size );
int		ft_strncmp( const char *first, const char *second, size_t n);
int		ft_atoi( const char *str);

char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int find);
char	*ft_strnstr(const char *str, const char *find, size_t len);
char	*ft_strdup( const char *source );
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

void	ft_putendl_fd(char *s, int fd);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *destination, const void *source, size_t size );
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize );
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int find);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);

#endif
