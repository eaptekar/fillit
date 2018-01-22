/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:15:56 by eaptekar          #+#    #+#             */
/*   Updated: 2018/01/22 12:45:40 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			((unsigned char*)s)[i] = '\0';
			i++;
		}
	}
}