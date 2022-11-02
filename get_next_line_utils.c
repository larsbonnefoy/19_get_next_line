/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:26:30 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/02 15:21:16 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	int		a;
	int		b;
	char	*str;

	if (!s1 || !s2)
	{	
		free(s1);
		return (0);
	}	
	a = -1;
	b = -1;
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (s1[++a] != '\0')
		str[a] = (char)s1[a];
	free(s1);
	while (s2[++b] != '\0')
		str[a + b] = (char)s2[b];
	str[a + b] = '\0';
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*str;
	int		a;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	str = malloc((len +1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	a = 0;
	while (s1[a] != '\0' && a < len)
	{
		str[a] = s1[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	srclen;

	a = 0;
	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (dstsize == 0)
		return (srclen);
	while (src[a] != '\0' && a < dstsize -1)
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (srclen);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}
