/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:16:55 by jroseiro          #+#    #+#             */
/*   Updated: 2024/06/22 12:55:17 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*t_dst;
	char	*t_src;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	t_dst = (char *) dst;
	t_src = (char *) src;
	i = -1;
	if (t_dst > t_src)
		while (len-- > 0)
			t_dst[len] = t_src[len];
	else
		while (++i < len)
			t_dst[i] = t_src[i];
	return (dst);
}

// !var - this expression is used to check weather the pointer is NULL.
// When used with other data types "!" works as a validator, 
// ex.: !int checks if int true(if int == 0) or false(if int != 0)
//
/* -- assigning converted values of src and dst to temp pointers so that
we don't touch the original values -- */
// if (t_dst > t_src)
//		while (len-- > 0)
//			t_dst[len] = t_src[len];
//
/* else statement -> if the address of the dst is not greater than src, then
we'll copy it from start to end like normally -- */
/*

int main() {
    char src[] = "Hello, World!";
    char dest[20];

    printf("Source string: %s\n", src);
    ft_memmove(dest, src, sizeof(src));

    printf("After memmove_custom(), dest string: %s\n", dest);

    return 0;
}

*/