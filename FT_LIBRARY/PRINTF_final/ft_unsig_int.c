/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsig_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:15:52 by zzaludov          #+#    #+#             */
/*   Updated: 2023/04/04 20:08:45 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsig_int(unsigned int i)
{
	char	*nb;
	size_t	size;

	size = 0;
	nb = ft_uitoa(i);
	size = ft_string(nb);
	free(nb);
	return (size);
}
