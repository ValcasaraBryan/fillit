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
	char	*id;
	char	*str;
	char	**piece;
	char 	*map;
	int 	i;

	str = ft_memalloc(BUFF_SIZE + 1);
	i = 0;
	if (argc == 2)
		id = ft_check_file(argv[1], str);
	else
		printf("Too Many Arguments\n");
	if (!str)
		free(str);
	if (id)
	{

		if (!(map = ft_memalloc((ft_strlen(id) * (ft_strlen(id) + 1)))))
			return (0);
		if (!(piece = (char **)malloc(sizeof(char *) * ft_strlen(id) + 1)))
			return (0);
														// id = string où chaque case contient le code du tetriminos par rapport a la list
														// ft_strlen(id) = correspond donc au nombre de pieces

		piece = ft_piece(ft_strlen(id), id, init_db(), piece); // generation des pieces dans un tableau a deux dimension
		
		ft_smallest_square(ft_strlen(id) + 1, map);     // generation de la map en fonction du nombre de piece + 1



///////////////////////////////////////
		while (piece[i])                           // affichage piece
			printf("piece = [%s]\n", piece[i++]);
		printf("%s", map);						   // affichage map
//////////////////////////////////////
	}
 	printf("-------------\n");
	return (0);
}
