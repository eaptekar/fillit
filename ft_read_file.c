/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 08:57:54 by vzamyati          #+#    #+#             */
/*   Updated: 2018/01/22 13:27:24 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//need to free buf

char        *ft_read_file(char *av)
{
    int fd;
    char *buf;

    fd = open(av, O_RDONLY);
    if (fd == -1)
        ft_error();
    if (!(buf = ft_strnew(546)))
        ft_error();
    read(fd, buf, 546);
    if (ft_valid(buf) == 1)
        ft_error();
    close (fd);
    return (buf);
}

static int  count_blocks(char *buf)
{
    int nmb;
    int i;

    nmb = 1;
    i = 20;
    while (buf[i] && buf[i] == '\n')
    {
        nmb++;
        i += 21;
    }
    return (nmb);
}

void    fill_tetri(t_tetri **tmp, char *buf)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 20)
    {
        if (buf[i] == '#')
        {
            (*tmp)->x[j] = i % 5;
            (*tmp)->y[j] = i / 5;
        }
        i++;
        j++;
    }
}

t_tetri     *tetri_list(char *buf)
{
    char    c;
    int     nmb;
    t_tetri *tmp;

    nmb = count_blocks(buf);
    c == 'A';
    if (!(tmp = (t_tetri*)malloc(sizeof(t_tetri))))
        ft_error();
    while (nmb > 0)
    {

    }
}