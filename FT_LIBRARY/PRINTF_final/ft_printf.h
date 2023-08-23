/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzaludov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:06:21 by zzaludov          #+#    #+#             */
/*   Updated: 2023/04/04 20:04:48 by zzaludov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_char(char c);
int		ft_string(char *str);
int		ft_integer(int i);
int		ft_unsig_int(unsigned int i);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_hexa(unsigned int i, char fcase);
int		ft_ptr(uintptr_t ptr);

#endif
