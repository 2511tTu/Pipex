/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:11:05 by zzaludov          #+#    #+#             */
/*   Updated: 2023/04/04 20:02:49 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_specifier(va_list args, char C)
{
	int	size;

	size = 0;
	if (C == 'c')
		size = ft_char(va_arg(args, int));
	else if (C == 's')
		size = ft_string(va_arg(args, char *));
	else if (C == 'p')
		size = ft_ptr(va_arg(args, uintptr_t));
	else if (C == 'd' || C == 'i')
		size = ft_integer(va_arg(args, int));
	else if (C == 'u')
		size = ft_unsig_int(va_arg(args, unsigned int));
	else if (C == 'X' || C == 'x')
		size = ft_hexa(va_arg(args, int), C);
	else if (C == '%')
		size = ft_char('%');
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_specifier(args, str[i + 1]);
			i++;
		}
		else
			size += ft_char(str[i]);
		i++;
	}
	va_end(args);
	return (size);
}
