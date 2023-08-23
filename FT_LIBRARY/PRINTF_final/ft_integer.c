/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:11:20 by zzaludov          #+#    #+#             */
/*   Updated: 2023/04/04 19:55:59 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_integer(int i)
{
	char	*nb;
	int		size;

	size = 0;
	nb = ft_itoa(i);
	size = ft_string(nb);
	free(nb);
	return (size);
}
