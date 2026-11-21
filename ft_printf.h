/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 09:45:40 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/21 17:00:53 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *input, ...);
int	ft_printc(int c, int counter);
int	ft_prints(char *s, int counter);
int	ft_printp(void *p, int counter);
int	ft_printd(int n, int counter);
int	ft_printu(unsigned int n, int counter);
int	ft_printxlow(unsigned long n, int counter);
int	ft_printxup(unsigned long n, int counter);
int	ft_printperc(int counter);
int	modstring(char input_mod, va_list *args, int counter);
