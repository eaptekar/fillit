/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 09:07:19 by vzamyati          #+#    #+#             */
/*   Updated: 2018/01/22 13:20:02 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     main(int ac, char **av)
{
    char    *buf;
<<<<<<< HEAD
	int     nmb;

=======
	char    **map;
	int     nmb;
>>>>>>> 9779050bef29a01e7fabb9cd42cefa1478209904
	t_tetri *list;

    buf = ft_read_file(av[1]);
    if (ac == 2)
        printf("%s", buf);
    else
        write(1, "usage: ./fillit map_file\n", 25);
    nmb = count_blocks(buf);
	list = parse_tetri(buf);
	print_list(list);
<<<<<<< HEAD
    solve_map(list, nmb);
=======
    map = gen_map(nmb);
	print_map(map);
>>>>>>> 9779050bef29a01e7fabb9cd42cefa1478209904
    free(buf);
    return (0);
}
