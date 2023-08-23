/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:20:55 by zzaludov          #+#    #+#             */
/*   Updated: 2023/04/04 20:07:18 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digits(uintptr_t n)
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

char	*ptr_to_hexa(uintptr_t n)
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
			hexa[i--] = (char)j + 87;
		n = n / 16;
	}
	return (hexa);
}

int	ft_ptr(uintptr_t ptr)
{
	int		size;
	char	*hexa;

	size = 0;
	if (ptr == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	hexa = ptr_to_hexa(ptr);
	size = ft_string(hexa) + 2;
	free(hexa);
	return (size);
}
