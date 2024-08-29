/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:45:15 by jroseiro          #+#    #+#             */
/*   Updated: 2024/06/11 17:58:56 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;

	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	t_dst = (unsigned char *) dst;
	t_src = (unsigned char *) src;
	while (n > 0)
	{
		*(t_dst++) = *(t_src++);
		n--;
	}
	return (dst);
}
// returns a pointer to the memory location where the copied data will be stored
// dst - destination
// src - source
// n - number of bytes to be copied