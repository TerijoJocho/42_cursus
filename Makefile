# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terijo <terijo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 23:34:41 by terijo            #+#    #+#              #
#    Updated: 2024/05/09 16:56:01 by terijo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# #creation des sources et des objets
SRCS			=	ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit \
	  				ft_isprint ft_memcpy ft_memmove ft_memset ft_strchr ft_strlcat \
	  				ft_strlcpy ft_strlen ft_strncmp ft_strnstr ft_strrchr ft_tolower \
	  				ft_toupper ft_memchr ft_memcmp ft_strdup ft_substr ft_strjoin \
					ft_strtrim ft_slpit
OBJS			= $(SRCS:.c=.o)
#regle compiler, flags et supp
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a
#creation d'une archive statique "libft.a"
all:			$(NAME)
$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
#efface les *.o
clean:
				$(RM) $(OBJS) $(BONUS_OBJS)
#appelle clean et efface l'executable all
fclean:			clean
				$(RM) $(NAME)
#appelle fclean et reconstruit le projet à partir de 0
re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus