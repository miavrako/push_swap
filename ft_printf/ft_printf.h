/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:39:49 by mirarand          #+#    #+#             */
/*   Updated: 2026/02/25 14:27:21 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NULL_MESSAGE "(null)"
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <unistd.h>

void	print_hex(uintptr_t number, char delimiter, int *counter);

int		ft_printf(const char *str, ...);

void	ft_putnbr(int number, int *counter);

void	print_memory(void *add, int *counter);

void	print_unsigned(unsigned int number, int *counter);

void	ft_putchar(char c, int *counter);

void	print_str(const char *str, int *counter);

#endif
