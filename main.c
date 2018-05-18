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
		int nb_piece = ft_strlen(id);
		int index;
		index = 1;
		if (!(map = ft_memalloc((nb_piece * (nb_piece + 1)))))
			return (0);
		if (!(piece = (char **)malloc(sizeof(char *) * nb_piece + 1)))
			return (0);
														// id = string où chaque case contient le code du tetriminos par rapport a la list
														// ft_strlen(id) = correspond donc au nombre de pieces

		piece = ft_piece(nb_piece, id, init_db(), piece); // generation des pieces dans un tableau a deux dimension
		
		int carre;

		carre = ft_smallest_square((nb_piece + index), map); // generation de la map en fonction du nombre de piece + 1



///////////////////////////////        essaye de poser chaque # en fonction de la piece
		int x;
		int z;
		int y;
		char *tmp;
		x = 0;
		z = 0;
		y = 0;
		index = 0;

		tmp = ft_strdup(map);
		while (index < 1)
		{
			x = 0;
			y = 0;
			while (piece[y])
			{
				while (piece[y][z])
				{
					if (piece[y][z] == '$')
					{
						x = x + carre;
						map[x] = '#';
					}
					if (piece[y][z] == '<')
					{
						x = x + carre - 1;
						map[x] = '#';
					}
					if (piece[y][z] == '-')
					{
						x = x + carre - 2;
						map[x] = '#';
					}
					if (piece[y][z] == '#')
					{
						x++;
						map[x] = '#';
					}
					z++;
				}
				z = 0;
				y++;
			}
			printf("x = %d\n", x);
			printf("carre = %d\n", ((carre * carre) + carre));
			if (index > 2)          ///////////////////////////////////////// back tracking // regeneration de la map avec 1 carre incrémenté
			{
				index++;
				carre = ft_smallest_square((nb_piece + index), tmp); // generation de la map en fonction du nombre de piece + 1
				map = ft_strdup(tmp);
			}
			index++;
			printf("index = %d\n", index);
		}

///////////////////////////////////////
		while (piece[i])                           // affichage piece
			printf("piece = [%s]\n", piece[i++]);
		printf("%s", map);						   // affichage map
//////////////////////////////////////
	}
 	printf("\n-------------\n");
	return (0);
}
