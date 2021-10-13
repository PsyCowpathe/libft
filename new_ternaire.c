/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ternaire.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:29:14 by agirona           #+#    #+#             */
/*   Updated: 2021/08/28 17:30:39 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	new_ternaire(int condition, int res1, int res2)
{
	if (condition == 0)
		return (res1);
	return (res2);
}
