/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:57:28 by terijo            #+#    #+#             */
/*   Updated: 2024/05/02 17:40:40 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The strnstr() function locates the first occurrence of the
     null-terminated string needle in the string haystack, where not
     more than len characters are searched.  Characters that appear
     after a ‘\0’ character are not searched.  Since the strnstr()
     function is a FreeBSD specific API, it should only be used when
     portability is not a concern.*/
char *ft_strnstr(const char *haystack, const char *needle, int len)
{
     int  i;
     int  j;

     i = 0;
     if (*needle == '\0')
          return ((char *)haystack);
     while (haystack[i] != 0 && i < len)
     {
          j = 0;
          while (haystack[i + j] == needle[j] && needle[j] != '\0' && i + j < len)
          {
               /*I don't understand why the incrementation is before the if*/
               j++;
               if (needle[j] == '\0')
                    return ((char *)&haystack[i]);
          }
          i++;
     }
     return (0);
}
/*#include <string.h>
#include <stdio.h>
int  main(void)
{
     char haystack[] = "Bonjour tout le monde, ou les gens";
     char needle[] = " ";

     printf("vrai :%s\n", strnstr(haystack, needle, 5));
     printf("moi :%s", ft_strnstr(haystack, needle, 5));
     return (0);
}*/
//fini mais j'ai utilisé int len au lieu de size_t len