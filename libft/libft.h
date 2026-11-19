/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olfhal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:49:42 by olfhal            #+#    #+#             */
/*   Updated: 2025/11/12 13:51:07 by olfhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
char		*ft_itoa(int n);
void		*ft_memset(void *s, int c, size_t n);
char		**ft_split(char const *s, char c);
int			ft_strchr(char *str, char *cmp);
char		*ft_strdup(char *src);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strlen(const char *str);
char		*ft_strnstr(const char *haystack, const char *needle,
				size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			gnl(int fd, char **str);
void		ft_putnbr(long long n, int *count);
void		ft_putchar(char c);
void		ft_putstr(char *s);

#endif