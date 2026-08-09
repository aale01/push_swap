/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:32:01 by alebe             #+#    #+#             */
/*   Updated: 2024/12/23 02:07:03 by alebe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	recursive(int n, char *num, int *i)
{
	if (n / 10 != 0)
		recursive(n / 10, num, i);
	num[*i] = n % 10 + '0';
	(*i)++;
}

char	*ft_itoa(int n)
{
	int		i;
	char	*num;

	i = 0;
	num = (char *)malloc((count_digit(n) + 1) * sizeof(char));
	if (!num)
		return (NULL);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_strlcpy(num, "-2147483648", 12);
			return (num);
		}
		num[i++] = '-';
		n *= -1;
	}
	recursive(n, num, &i);
	num[i] = '\0';
	return (num);
}
