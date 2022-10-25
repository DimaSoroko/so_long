/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:11:14 by dsoroko           #+#    #+#             */
/*   Updated: 2022/10/25 11:40:03 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int		len;

	n = nb;
	len = get_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		exit (1);
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

// #include <stdlib.h>
// #include <stdio.h>
// #include <limits.h>
// int main(void)
// {
// 	char *str = ft_itoa(INT_MIN);
// 	printf("%s\n", str);
// 	char *str2 = ft_itoa(INT_MAX);
// 	printf("%s\n", str2);
// 	char *str3 = ft_itoa(0);
// 	printf("%s\n", str3);
// 	return (0);
// }