# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 19:06:53 by mel-hadj          #+#    #+#              #
#    Updated: 2021/09/27 13:19:03 by mel-hadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = minishell

CC = gcc -g

DIR_HEADERS =	./headers/

SANITIZE = -fsanitize=address

DIR_LIBFT = ./libft/
DIR_SRCS = ./src/
DIR_LEXER = ./src/lexer/
DIR_ERROR = ./src/error/
DIR_HELPER = ./src/helper/
DIR_PARSER = ./src/parser/
DIR_EXECUTION= ./src/execution/

READLINE = -lreadline -L ~/goinfre/.brew/opt/readline/lib -I ~/goinfre/.brew/opt/readline/include
# CPPFLAGS = 

SRC_LIBFT = ft_bzero.c ft_strlen.c ft_calloc.c ft_strncmp.c ft_strdup.c\
	ft_atoi.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_isalpha.c\
	ft_isalnum.c ft_toupper.c ft_tolower.c ft_strnstr.c ft_putchar_fd.c\
	ft_strlcat.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memcmp.c\
	ft_memmove.c ft_strchr.c ft_strrchr.c ft_split.c\
	ft_putstr_fd.c ft_putnbr_fd.c ft_memchr.c  ft_strlcpy.c\
	ft_putendl_fd.c ft_itoa.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_strjoin.c\
	ft_lstadd_back_bonus.c ft_lstnew_bonus.c  ft_lstsize_bonus.c
	

SRC_SHELL = 
SRC_LEXER = lexer.c token_list.c
SRC_ERROR = error.c 
SRC_HELPER = helper_functions.c helper_functions1.c  helper_functions2.c  error_functions.c lexer_helper1.c lexer_helper.c parser_helper.c parser_helper1.c lexer_norm_functions.c lexer_norm_functions1.c lexer_norm_functions2.c
SRC_PARSER = parser.c  parser_token_list.c redirect_list.c
SRC_EXECUTION = path.c path_fixer.c exec_builtins.c exec_builtins2.c env_data.c process.c redirections.c z_pipeline.c ft_echo.c ft_cd.c ft_cd_fncts.c ft_exit.c ft_unset.c ft_env.c\
	ft_export.c ft_export_utils.c ft_pwd.c process_forker.c redirections2.c redirections3.c redirections4.c


SRCS =  $(addprefix $(DIR_SRCS), $(SRC_SHELL)) $(addprefix $(DIR_LIBFT), $(SRC_LIBFT)) $(addprefix $(DIR_LEXER), $(SRC_LEXER))\
		$(addprefix $(DIR_ERROR), $(SRC_ERROR)) $(addprefix $(DIR_HELPER), $(SRC_HELPER)) $(addprefix $(DIR_PARSER), $(SRC_PARSER))\
		$(addprefix $(DIR_EXECUTION), $(SRC_EXECUTION))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : 
			@gcc  ${FLAGS} -I ${DIR_HEADERS}  ${SRCS} minishell.c -lreadline $(READLINE) -o $(NAME) #-fsanitize=address

clean  :

fclean : clean
		@rm -f $(NAME)

re : fclean
		@make all
