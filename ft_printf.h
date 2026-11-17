/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 09:45:40 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/17 19:00:58 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_printc(int c);
int ft_prints(char *s);
int ft_printp(void *p);
int ft_printd(int n);
int ft_printu(unsigned int n);
int ft_printx(unsigned int n);
int	ft_printX(unsigned int n);
int ft_printPERC(void);

