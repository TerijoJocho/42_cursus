/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:40:34 by daavril           #+#    #+#             */
/*   Updated: 2025/02/10 15:50:38 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int parser()


char *expand_variable(char *var_name) {
    char *value = getenv(var_name);
    if (value)
        return ft_strdup(value);  // Si défini, retourner la valeur
    return ft_strdup("");         // Sinon, retourner une string vide
}
