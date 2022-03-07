/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:52:19 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/03/02 15:23:32 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_header.h"

int	amount_shifted(t_etris *tetr, t_help *help)
{
	uint64_t	copy;
	int			res;

	res = 0;
	copy = tetr->orig;
	while (copy != tetr->num)
	{
		copy /= 2;
		res++;
		if (res > help->size)
			return (0);
	}
	return (res);
}

int	find_set(t_etris *tetr, t_help *help, uint16_t *map)
{
	help->i = tetr->pos;
	help->x = help->size - tetr->width - amount_shifted(tetr, help);
	while (help->i + tetr->height - 1 < help->size)
	{
		while (help->x >= 0)
		{
			if (*(uint64_t *)&map[help->i] & tetr->num)
			{
				if (help->x-- > 0)
					tetr->num >>= 1;
			}
			else
			{
				*(uint64_t*)&map[help->i] |= tetr->num;
				tetr->pos = help->i;
				return (1);
			}
		}
		tetr->num = tetr->orig;
		help->x = help->size - tetr->width;
		help->i++;
	}
	tetr->pos = 0;
	return (0);
}

int	unset_num(uint16_t *map, t_etris *tetr, t_help *help)
{
	int	shifted;

	*(uint64_t*)&map[tetr->pos] ^= tetr->num;
	shifted = amount_shifted(tetr, help);
	if (shifted + tetr->width < help->size)
	{
		tetr->num >>= 1;
	}
	else
	{
		tetr->num = tetr->orig;
		tetr->pos++;
	}
	if (find_set(tetr, help, map))
		return (1);
	return (0);
}

int	solver(t_etris *tetr, t_help *help, uint16_t *map, int pos)
{
	if (help->size < tetr[pos].width || help->size < tetr[pos].height)
		return (0);
	if (find_set(&tetr[pos++], help, map))
	{
		if (pos < help->pieces)
		{
			while (!solver(tetr, help, map, pos))
			{
				if (!unset_num(map, &tetr[pos - 1], help))
					return (0);
			}
			return (1);
		}
		return (1);
	}
	return (0);
}
