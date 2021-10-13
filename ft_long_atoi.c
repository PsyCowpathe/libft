/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:57:49 by agirona           #+#    #+#             */
/*   Updated: 2021/09/22 16:11:18 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	long_conv(const char *str, int i, int neg)
{
	long int		tmp;
	long int		res;

	tmp = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		if (res < tmp && neg == -1)
			return (0);
		else if (res < tmp)
			return (-1);
		tmp = res;
		i++;
	}
	return (res * neg);
}

long int	ft_long_atoi(const char *str)
{
	int				i;
	int				neg;

	i = 0;
	while (str[i] == '\r' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\t' || str[i] == '\f' || str[i] == ' ')
		i++;
	neg = 1;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (long_conv(str, i, neg));
}
