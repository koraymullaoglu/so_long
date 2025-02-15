/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femullao <femullao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:05:01 by femullao          #+#    #+#             */
/*   Updated: 2024/10/27 16:30:17 by femullao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	spcheck(char c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}

int	archeck(char c, va_list a)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(a, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(a, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(a, int)));
	else if (c == 'u')
		return (ft_printuns(va_arg(a, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_printhex(va_arg(a, unsigned int), c));
	else if (c == 'p')
		return (ft_putptr(va_arg(a, unsigned long), 1));
	else
		return (0);
}

int	ft_printf(const char *p, ...)
{
	int		i;
	int		r;
	va_list	a;

	i = 0;
	r = 0;
	va_start(a, p);
	while (p[i])
	{
		if (p[i] == '%')
		{
			if (spcheck(p[i + 1]))
			{
				r += archeck(p[i++ + 1], a);
			}
			i++;
		}
		else
		{
			r += ft_putchar(p[i]);
			i++;
		}
	}
	va_end(a);
	return (r);
}
