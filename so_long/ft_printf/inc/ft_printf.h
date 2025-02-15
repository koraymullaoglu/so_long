/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femullao <femullao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:09:33 by femullao          #+#    #+#             */
/*   Updated: 2024/11/02 16:17:29 by femullao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);

int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_printuns(unsigned int n);
int		ft_printhex(unsigned int n, char f);
int		ft_putptr(unsigned long n, int f);
int		ft_printf(const char *p, ...);

#endif