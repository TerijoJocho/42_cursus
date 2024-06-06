/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:16:32 by daavril           #+#    #+#             */
/*   Updated: 2024/06/06 13:51:45 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

# include "../libft/libft.h"
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

#endif