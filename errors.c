/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvuorenl <rvuorenl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:23:10 by rvuorenl          #+#    #+#             */
/*   Updated: 2022/03/07 13:15:00 by rvuorenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_header.h"

int	er_lines(char *s)
{
	if (s[4] != '\n' || s[9] != '\n' || s[14] != '\n' || s[19] != '\n')
		return (0);
	if (s[20] != '\n' && s[20] != '\0')
		return (0);
	return (1);
}

int	er_chars(char *str)
{
	int	dots;
	int	hash;
	int	i;

	i = 0;
	hash = 0;
	dots = 0;
	while (str[i])
	{
		if (str[i] == '#')
			hash++;
		if (str[i] == '.')
			dots++;
		i++;
	}
	if (hash != 4 || dots != 12)
		return (0);
	return (1);
}

int	er_connect(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i > 0 && str[i - 1] == '#')
				res++;
			if (i >= 5 && str[i - 5] == '#')
				res++;
			if (i <= 13 && str[i + 5] == '#')
				res++;
			if (i < 18 && str[i + 1] == '#')
				res++;
		}
		i++;
	}
	return (res == 6 || res == 8);
}

int	error_checks(char *argv, t_help *h)
{
	int		res;

	h->fd = open(argv, O_RDONLY);
	if (h->fd == -1)
		return (0);
	h->pieces = 0;
	res = read(h->fd, h->str, 21);
	while (res >= 20)
	{
		h->str[res] = '\0';
		if (!er_chars(h->str) || !er_lines(h->str) || !er_connect(h->str))
			return (0);
		if (++h->pieces > 26)
			return (0);
		res = read(h->fd, h->str, 21);
	}
	close(h->fd);
	if (res > 0 || h->pieces == 0)
		return (0);
	return (1);
}
