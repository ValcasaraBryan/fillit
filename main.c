/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:27:03 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/15 18:27:41 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char 	*str;
	char	*sur;

 	fd = 0;
 	ret = 4;
 	str = NULL;
 	sur = NULL;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)))
		{
			while (ret-- != 0)
			{
				str = ft_get_next_piece(fd);
				if (str)
				{
					//sur = tetridetector(str);
					printf("%s\n", str);
				}
				else
					printf("--- Error ---\n");
			}
		}
	}
	else
		printf("error\n");
	return (0);
}
