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
	char 	*str;
	char	*sur;
	char	*id;
	int		id_piece;

 	str = ft_memalloc(BUFF_SIZE + 1);
 	sur = ft_strdup("");
	if (argc == 2)
	{
		if (ft_detection_error(open(argv[1], O_RDONLY), str) == 1)
		{
			fd = open(argv[1], O_RDONLY);
			while ((str = ft_get_next_piece(fd)))
			{
				printf("%s", str);
				id = tetridetector(str);
				id_piece = tetricmp(id, init_db());
				printf("piece = [%s]\n", id);
				printf("piece = [%d]\n\n", id_piece);
				sur = library_generator(id_piece, sur);
			}
		}
	}
	else
		printf("--- Error Too Many Arguments ---\n");
	return (0);
}
