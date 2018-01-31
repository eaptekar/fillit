/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:16:27 by vzamyati          #+#    #+#             */
/*   Updated: 2018/01/31 16:04:49 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		new_coord(t_tetri **list, int i, int j)
{
	int			count;

	count = 3;
	while (count >= 0)
	{
		(*list)->x[count] += i - (*list)->x[0];
		(*list)->y[count] += j - (*list)->y[0];
		count--;
	}
}

static char		**rec_alg(char **map, char **fmap, t_tetri *list, int n)
{
	int			i;
	int			j;

	j = 0;
	if (list->next == NULL)
		return (map);
	fmap = NULL;
	while (j < n)
	{
		i = 0;
		while (i < n)
		{
			new_coord(&list, i, j);
			if (!check_insert_tetri(list, map, n))
			{
				fmap = rec_alg(write_tetri(list, map, n), fmap, list->next, n);
				if (fmap)
					return (fmap);
				map = clear_tetri(list, map, n);
			}
			i++;
		}
		j++;
	}
	return (NULL);
}

void			solve_map(t_tetri *list, int nmb)
{
	int			n;
	char		**map;
	char		**final_map;
	char		**result;

	n = size_map(nmb);
	map = gen_map(n);
	final_map = NULL;
	while (!(result = rec_alg(map, final_map, list, n)))
	{
		n++;
		free(map);
		map = gen_map(n);
	}
	print_map(result);
	free(result);
}
