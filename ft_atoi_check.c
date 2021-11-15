/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:33:25 by agirona           #+#    #+#             */
/*   Updated: 2021/11/15 12:32:23 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	conv_check(const char *str, int i, int neg, int *isint)
{
	unsigned int	res;
	int				final;
	char			*tmp;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9' && *isint == 1)
		res = res * 10 + str[i++] - 48;
	final = res * neg;
	tmp = ft_itoa(final);
	if (tmp == NULL)
	{
		*isint = 0;
		return (0);
	}
	if (ft_strcmp((char *)str, tmp) != 0)
		*isint = 0;
	free(tmp);
	return (res);
}

int	ft_atoi_check(const char *str, int *isint)
{
	int		i;
	int		neg;

	i = 0;
	*isint = 1;
	while (ft_ischar("\r\n\v\t\f ", str[i]) == 1)
		i++;
	neg = 1;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (conv_check(str, i, neg, isint));
}
