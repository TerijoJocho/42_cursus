/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:33:59 by terijo            #+#    #+#             */
/*   Updated: 2024/05/04 14:39:32 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void    *ft_calloc(int count, size_t size)
{
   void *ptr;
   ptr = (void *) malloc(count * size);
   while (count)
   {
        *(unsigned char*)(ptr + count) = 0;
        count--;
   }
   return (ptr);
}
/*#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    //int *ptr = (int *) calloc(3, sizeof (int));
    int *ptr = (int *) ft_calloc(3, sizeof (int));
    printf("ptr :%d, %d, %d", ptr[0], ptr[1], ptr[2]);
    return (0);
}*/
//fonctinone sur terminal mais vscode veut pas j'comprend pas