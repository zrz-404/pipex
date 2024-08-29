/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:26:58 by jroseiro          #+#    #+#             */
/*   Updated: 2024/06/17 17:29:22 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isalpha(int arg)
{
	return ((arg >= 65 && arg <= 90) || (arg >= 97 && arg <= 122));
}
/*int main()
{
    // Testing ft_isalpha
    printf("ft_isalpha('A') returned: %d\n", ft_isalpha('A'));
    printf("ft_isalpha('z') returned: %d\n", ft_isalpha('z'));
    printf("ft_isalpha('1') returned: %d\n", ft_isalpha('1'));

    // Testing isalpha from standard library
    printf("isalpha('A')we returned: %d\n", isalpha('A'));
    printf("isalpha('z') returned: %d\n", isalpha('z'));
    printf("isalpha('1') returned: %d\n", isalpha('1'));

    return 0;
}*/