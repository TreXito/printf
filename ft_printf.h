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

static void *ft_printc(char *input);
static void *ft_prints(char *input);
static void *ft_printp(char *input);
static void *ft_printd(char *input);
static void *ft_printi(char *input);
static void *ft_printu(char *input);
static void *ft_printx(char *input);
static void *ft_printX(char *input);
static void	*ft_printPERC(char *input);

