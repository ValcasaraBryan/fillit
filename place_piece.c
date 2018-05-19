/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 21:47:33 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/18 21:47:35 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *place_piece(char *piece, char c, char *sq, int sqsize)
{
    char letter;
    int start;
    int i;
    int j;

    start = 0;
    i = 0;
    j = 0;

    while (piece[j] != '\0')
    {
        if (piece[j] == '$')
            i = i + sqsize - 1;
        if (piece[j] == '<')
            i = i + sqsize - 2;
        if (piece[j] == '-')
            i = i + sqsize - 3;

        if (piece[j] == '#')
        {
            if (sq[start + i] == '.')
                sq[start + i] = c;
            else
            {
                if ((start + i) > (sqsize * (sqsize + 1) - 2))
                    return (NULL);


                sq = erase_piece(sq, c);
                j = -1;
                i = -1;
                start++;
            }
        }
        i++;
        j++;
    }
    if (piece[j] == '\0')
        return (sq);
    return (NULL);
}

char	*erase_piece(char *sq, char c)
{
    int i;

    i = 0;
    while (sq[i] != '\0')
    {
        if (sq[i] == c)
            sq[i] = '.';
        i++;
    }
    return (sq);
}
