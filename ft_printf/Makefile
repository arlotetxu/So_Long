# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 19:54:12 by jflorido          #+#    #+#              #
#   Updated: 2022/10/22 10:34:33 by jflorido         ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_printf.c ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putnbr_u.c \
		ft_putstr.c ft_strlen.c

#SRC_Bonus =

OBJS = $(SRC:.c=.o)
OBJS_Bonus = $(SRC_Bonus:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

AR      = ar
AFLAG   = -rc

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(AFLAG) $(NAME) $^

#bonus: $(OBJS) $(OBJS_Bonus)
#	$(AR) $(AFLAG) $(NAME) $^

clean:
	$(RM) $(OBJS) $(OBJS_Bonus)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
