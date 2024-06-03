/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:16:32 by daavril           #+#    #+#             */
/*   Updated: 2024/06/03 19:09:34 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

# include "../libft/libft.h"
# include <assert.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_print_char(char c);
int		ft_print_id(int value, int *writtenCarac);
int		ft_print_str(char *value, int *writtenCarac);
char	*ft_print_p(char *str, int *writtenCarac);

#endif