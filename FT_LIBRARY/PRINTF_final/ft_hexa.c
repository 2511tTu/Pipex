/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:17:12 by zzaludov          #+#    #+#             */
/*   Updated: 2023/04/04 20:02:07 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digits(unsigned int n)
{
	int	digits;

	digits = 0;
	while (n > 0)
	{
		n = n / 16;
		digits++;
	}
	return (digits);
}

char	*to_hexa(unsigned int n, char fcase)
{
	size_t	i;
	size_t	j;
	char	*hexa;

	i = digits(n);
	j = 0;
	hexa = (char *) malloc (digits(n) + 1);
	hexa[i--] = '\0';
	while (n > 0)
	{
		j = n % 16;
		if (j <= 9)
			hexa[i--] = (char)j + '0';
		else
			hexa[i--] = (char)j + fcase - 33;
		n = n / 16;
	}
	return (hexa);
}

int	ft_hexa(unsigned int n, char fcase)
{
	int		size;
	char	*hexa;

	size = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	hexa = to_hexa(n, fcase);
	size = ft_string(hexa);
	free (hexa);
	return (size);
}
/*
int	main()
{
	int i = ft_hexa(0x1c7, 'X');
	return 0;
}*/
