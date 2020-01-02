/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 21:51:41 by aazeroua          #+#    #+#             */
/*   Updated: 2019/11/20 21:29:46 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcat(char *dest, const char *src);
void	*ft_memset(void	*a, int c, size_t e);
char	*ft_strstr(const char *s1, const char *s2);
int		ft_atoi(const char *str);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
char	*ft_strdup(const char *src);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	ft_strclr(char *s);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memalloc(size_t size);
void	ft_memdel(void	**ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f) (char *));
void	ft_strdel(char **as);
void	ft_striteri(char *s, void (*f) (unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	*ft_itoa(int n);
char	**ft_strsplit(char const *s, char c);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
void	ft_swap(int *a, int *b);
char	*ft_strcase(char *s);
int		ft_abs(int n);
char	*ft_strrev(char *str);
int		ft_getindex(char *str, char c);
int		ft_cwordcount(const char *s, char c);
#endif
