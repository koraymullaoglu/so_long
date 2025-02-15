/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femullao <femullao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:46:40 by femullao          #+#    #+#             */
/*   Updated: 2024/11/02 15:22:13 by femullao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		i += ft_putchar(s[i]);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		n = -n;
		size += write(1, "-", 1);
	}
	if (n >= 10)
		size += ft_putnbr(n / 10);
	size += ft_putchar("0123456789"[n % 10]);
	return (size);
}

int	ft_printuns(unsigned int n)
{
	int	size;

	size = 0;
	if (n >= 10)
	{
		size = ft_printuns(n / 10);
		size += ft_putchar(n % 10 + '0');
	}
	else
		size += ft_putchar(n + '0');
	return (size);
}

int	ft_printhex(unsigned int n, char f)
{
	int	size;

	size = 0;
	if (n >= 16)
		size += ft_printhex(n / 16, f);
	if (f == 'x')
		size += ft_putchar("0123456789abcdef"[n % 16]);
	else if (f == 'X')
		size += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (size);
}

int	ft_putptr(unsigned long n, int f)
{
	int	size;

	size = 0;
	if (f == 1)
		size += ft_putstr("0x");
	if (n >= 16)
		size += ft_putptr(n / 16, 0);
	size += ft_putchar("0123456789abcdef"[n % 16]);
	return (size);
}
