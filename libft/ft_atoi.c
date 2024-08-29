/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:25:40 by jroseiro          #+#    #+#             */
/*   Updated: 2024/06/21 13:09:18 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

/* while we are not at the end of the string and 
the str[i] is a digit between 0 and 9
we multiply the current result by 10, so we add another digit to the result.*/
/*then we add the decimal value of the current character -48 to the result*/
/*the -48 part comes from the ascii  table*/
/*the '0' character is the decimal value 48,
and we don't want to ass 48 to our int res, rather 0, so we subtract 48*/
/*this effectively places us at the 10 first
"houses" of the ascii table, from pos 0 to 9,
therefore allowing for the direct translation of char to integer*/

/*int main()
{
	// Testing ft_atoi
	printf("ft_atoi('A') returned: %d\n", ft_atoi("A"));
	printf("ft_atoi('z') returned: %d\n", ft_atoi("42"));
	printf("ft_atoi('1') returned: %d\n", ft_atoi("1"));
	printf("ft_atoi('+-+- --   -1') returned: %d\n", ft_atoi("+-+- --   -1"));

	// Testing atoi from standard library
	printf("atoi('A')we returned: %d\n", atoi("A"));
	printf("atoi('z') returned: %d\n", atoi("42"));
	printf("atoi('1') returned: %d\n", atoi("1"));
	printf("atoi('+-+- --   -1') returned: %d\n", atoi("+-+- --   -1"));

	return 0;
}*/