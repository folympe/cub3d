# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olfhal <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 11:28:07 by olfhal            #+#    #+#              #
#    Updated: 2025/11/10 11:28:10 by olfhal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isdigit.c \
		ft_itoa.c ft_memset.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c \
		ft_strnstr.c ft_substr.c ft_gnl.c ft_putnbr.c

SRCS_ALL = ${SRCS} ${SRCS_BONUS}

NAME = libft.a

OBJS = ${SRCS:.c=.o}

OBJS_ALL = ${SRCS_ALL:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar -rsc ${NAME} ${OBJS}

bonus: ${OBJS_ALL}
	ar -rsc ${NAME} ${OBJS_ALL}

all: ${NAME}

clean:
		rm -f ${OBJS_ALL}

fclean:	clean;
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus