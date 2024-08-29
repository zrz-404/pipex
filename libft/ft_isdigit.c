/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:08:38 by jroseiro          #+#    #+#             */
/*   Updated: 2024/06/17 17:24:46 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int	ft_isdigit(int arg)
{
	return ((arg >= '0') && (arg <= '9'));
}

/*int main()
{
    // Testing ft_isdigit
    printf("ft_isdigit('A') returned: %d\n", ft_isdigit('A'));
    printf("ft_isdigit('z') returned: %d\n", ft_isdigit('z'));
    printf("ft_isdigit('1') returned: %d\n", ft_isdigit('1'));

    // Testing isdigit from standard library
    printf("isdigit('A')we returned: %d\n", isdigit('A'));
    printf("isdigit('z') returned: %d\n", isdigit('z'));
    printf("isdigit('1') returned: %d\n", isdigit('1'));

    return 0;
}*/