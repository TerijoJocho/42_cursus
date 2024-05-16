/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:16:22 by terijo            #+#    #+#             */
/*   Updated: 2024/05/09 16:55:53 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if macro LIBFT_H is not defined
#ifndef LIBFT_H
//make this
#define LIBFT_H
//include lib that functions use
#include <unistd.h>
#include <stdlib.h>
//first part
int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);
int     ft_strlen(char const *str);
void    *ft_memset(void *b, int c, size_t len);
void    bzero(void *s, size_t n);
void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t len);
size_t  ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
size_t  ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
int     ft_toupper(int c);
int     ft_tolower(int c);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
int     ft_strncmp(const char *s1, const char *s2, int n);
void    *ft_memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
char    *ft_strnstr(const char *haystack, const char *needle, int len);
int     ft_atoi(const char *str);
void    *ft_calloc(int count, size_t size);
char    *strdup(const char *s1);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s1, char const *set);
char    **ft_split(char const *s, char c);
//end 
#endif