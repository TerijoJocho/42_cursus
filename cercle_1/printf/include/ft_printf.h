/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:16:32 by daavril           #+#    #+#             */
/*   Updated: 2024/11/12 16:26:04 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/header/libft.h"
# include <assert.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_print_char(char c);
void	ft_print_id(int value, int *writtenCarac);
int		ft_print_str(char *value, int *writtenCarac);
void	ft_print_p(unsigned long long value, int *writtenCarac);
void	ft_print_undec(unsigned int value, int *writtenCarac);
void	ft_print_hexa(unsigned int value, int *writtenCarac, char c);

#endif
