# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 22:33:35 by abenouda          #+#    #+#              #
#    Updated: 2019/10/29 17:12:19 by abenouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_bzero.c ft_strlen.c ft_calloc.c ft_atoi.c ft_isdigit.c ft_isascii.c\
		ft_isprint.c ft_isalpha.c ft_isalnum.c ft_toupper.c ft_tolower.c\
		ft_strnstr.c ft_putchar_fd.c ft_strncmp.c ft_strdup.c ft_strjoin.c\
		ft_strlcat.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memcmp.c\
		ft_memmove.c ft_strchr.c ft_strrchr.c ft_split.c ft_substr.c\
		ft_putstr_fd.c ft_putnbr_fd.c ft_memchr.c ft_strlcpy.c\
		ft_putendl_fd.c ft_itoa.c ft_strmapi.c ft_strtrim.c

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_back_bonus.c\
        	ft_lstadd_front_bonus.c ft_lstlast_bonus.c\
        	ft_lstdelone_bonus.c ft_lstsize_bonus.c\
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

FLAGS = -Werror -Wall -Wextra

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: all
	gcc $(FLAGS) -c $(SRC_BONUS) 
	ar rc $(NAME) $(OBJ_BONUS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(OBJ_BONUS)
	
fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
