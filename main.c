/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:50:12 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/02 17:25:35 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*test1;
	char	*test2;
	char	*test3;
	int		i;

	i = 1;
	fd1 = open("JKRowling_HP3.txt", O_RDONLY);
	fd2 = open("JKRowling_HP1.txt", O_RDONLY);
	fd3 = open("king_james_bible.txt", O_RDONLY);
	while (i < 100)
	{
	
		test1 = get_next_line(fd1);
		test2 = get_next_line(fd2);
		test3 = get_next_line(fd3);
		printf("%d:%s", i, test1);
		printf("\n");
		printf("%d:%s", i, test2);
		printf("\n");
		printf("%d:%s", i, test3);
		printf("\n");
		free(test1);
		free(test2);
		free(test3);
		i++;
	}	
	close(fd1);
	close(fd2);
	close(fd3);
//	system("leaks a.out");
}
