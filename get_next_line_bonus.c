/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:05:55 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/02 15:24:45 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		is_endl(char *str, char *st_chr);
void	complete_line(char *buf, char *st_chr, int flag);
int		check_read(int char_read, char *buf, char *st_chr);

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	st_chr[OPEN_MAX][BUFFER_SIZE + 1];
	int			endl;
	char		*next_line;
	int			char_read;

	if (fd < 0)
		return (NULL);
	next_line = ft_strdup(st_chr[fd]);
	if (is_endl(next_line, st_chr[fd]) == 1)
		return (next_line);
	endl = 0;
	while (endl == 0)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		char_read = read(fd, buf, BUFFER_SIZE);
		endl = check_read(char_read, buf, st_chr[fd]);
		next_line = ft_strjoin(next_line, buf);
		if (next_line[0] == '\0' && buf[0] == '\0')
		{	
			free(next_line);
			next_line = NULL;
		}	
	}
	return (next_line);
}

int	is_endl(char *buf, char *st_chr)
{
	int	a;

	a = 0;
	while (buf[a] != '\0')
	{
		if (buf[a] == '\n')
		{
			complete_line(buf, st_chr, 1);
			return (1);
		}
		a++;
	}
	return (0);
}

void	complete_line(char *buf, char *st_chr, int flag)
{
	int	a;

	a = 0;
	while (buf[a] != '\n' && buf[a] != '\0')
		a++;
	ft_strlcpy(st_chr, buf + a + flag, BUFFER_SIZE + 1);
	ft_strlcpy(buf, buf, ++a + flag);
}

int	check_read(int char_read, char *buf, char *st_chr)
{
	int	a;

	a = -1;
	if (char_read == -1 || char_read == 0)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		ft_bzero(st_chr, BUFFER_SIZE + 1);
		return (1);
	}
	else if (char_read > 0 && char_read < BUFFER_SIZE)
	{
		while (++a < char_read)
		{	
			if (buf[a] == '\n')
			{
				complete_line(buf, st_chr, 1);
				return (1);
			}
		}
		complete_line(buf, st_chr, 0);
		return (1);
	}			
	return (is_endl(buf, st_chr));
}
