/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:45:27 by zzaludov          #+#    #+#             */
/*   Updated: 2023/04/04 20:02:23 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digits(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*int_to_char(char *nb, unsigned int n, unsigned int j)
{
	if (n == 0)
		nb[0] = '0';
	nb[j] = '\0';
	while (n > 0)
	{
		nb[j - 1] = (n % 10) + '0';
		j--;
		n = n / 10;
	}
	return (nb);
}

char	*ft_uitoa(unsigned int n)
{
	char	*nb;
	size_t	j;

	j = digits(n);
	nb = (char *) malloc (j + 1);
	if (!nb)
		return (NULL);
	nb = int_to_char(nb, n, j);
	return (nb);
}
