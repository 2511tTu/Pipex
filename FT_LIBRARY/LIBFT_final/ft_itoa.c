/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:09:48 by zzaludov          #+#    #+#             */
/*   Updated: 2023/03/07 22:16:21 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>*/
#include "libft.h"

int	digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*int_to_char(char *nb, int n, int j)
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

char	*ft_itoa(int n)
{
	char	*nb;
	int		j;

	j = digits(n);
	nb = (char *) malloc (j + 1);
	if (!nb)
		return (NULL);
	if (n == -2147483648)
	{
		nb[0] = '-';
		nb[1] = '2';
		n = 147483648;
	}
	else if (n < 0)
	{
		nb[0] = '-';
		n *= -1;
	}
	nb = int_to_char(nb, n, j);
	return (nb);
}
/*
int main ()
{
	int i = 0;
	char *a = ft_itoa(i);

	printf("%s", a);
	return 0;
}*/
