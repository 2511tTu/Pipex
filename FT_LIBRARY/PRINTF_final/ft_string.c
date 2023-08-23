/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:16:35 by zzaludov          #+#    #+#             */
/*   Updated: 2023/04/04 18:00:50 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include <stdio.h>
//# include <stdlib.h>
//# include <unistd.h>
#include "ft_printf.h"

int	ft_string(char *str)
{
	int	size;

	size = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[size])
	{
		write (1, &str[size], 1);
		size++;
	}
	return (size);
}
/*
int	main()
{
	int i = ft_string("-2");
	printf("\n%i", i);
	return 0;
}*/
