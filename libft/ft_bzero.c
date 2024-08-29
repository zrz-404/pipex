/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:17:23 by jroseiro          #+#    #+#             */
/*   Updated: 2024/06/11 17:58:26 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	size_t	p;

	p = 0;
	while (n != 0)
	{
		((unsigned char *)ptr)[p] = 0;
		p++;
		n--;
	}
}
