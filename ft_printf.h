/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppodobri <ppodobri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 09:45:40 by ppodobri          #+#    #+#             */
/*   Updated: 2026/11/13 21:23:16 by ppodobri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

static void *ft_printc(void *input);
static void *ft_prints(void *input);
static void *ft_printp(void *input);
static void *ft_printd(void *input);
static void *ft_printi(void *input);
static void *ft_printu(void *input);
static void *ft_printx(void *input);
static void *ft_printX(void *input);
static void	*ft_printPERC(void *input);

