/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:05:35 by jroseiro          #+#    #+#             */
/*   Updated: 2024/06/20 11:04:51 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long nbr);
static char	*pre_conv(int len);

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*res;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	res = pre_conv(len);
	if (!res)
		return (NULL);
	i = len - 1;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr == 0)
		res[i] = '0';
	while (nbr > 0)
	{
		res[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		res[0] = '-';
	res[len] = '\0';
	return (res);
}

static char	*pre_conv(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	return (tmp);
}

static int	int_len(long nbr)
{
	int	j;

	j = 0;
	if (nbr <= 0)
		j++;
	while (nbr != 0)
	{
		nbr /= 10;
		j++;
	}
	return (j);
}
