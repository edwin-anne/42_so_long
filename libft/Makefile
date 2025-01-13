# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eanne <eanne@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 19:43:35 by eanne             #+#    #+#              #
#    Updated: 2024/10/24 19:44:07 by eanne            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS += -Wall -Wextra -Werror

SRCS = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

%.o: %.c
		@$(CC) $(CFLAGS) -c -I ../includes $< -o $@

$(NAME): $(OBJS)
		@ar rcs $@ $^

all:		$(NAME)

clean:
		@rm -f $(OBJS) $(BONUS_OBJS)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

bonus: $(OBJS) $(BONUS_OBJS)
		@ar rcs $(NAME) $^

.PHONY:		all clean fclean re