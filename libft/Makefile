# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 16:57:08 by shrimech          #+#    #+#              #
#    Updated: 2025/04/02 10:04:09 by shrimech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
FUNCTIONS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
       ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
       ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
       ft_putstr_fd.c ft_strdup.c ft_strchr.c ft_strjoin.c \
       ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strnstr.c \
       ft_strrchr.c ft_strtrim.c ft_substr.c ft_striteri.c ft_strncmp.c \
       ft_tolower.c ft_toupper.c ft_split.c ft_itoa.c ft_putnbr_fd.c 

OBJS = $(FUNCTIONS:.c=.o)
NAME = libft.a
all: $(NAME)
$(NAME): $(OBJS)
	@ar rcs $@ $^
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 


clean:
	@rm -f $(OBJS)


fclean: clean
	@rm -f $(NAME)

re: fclean all
