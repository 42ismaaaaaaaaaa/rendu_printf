# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iouali <iouali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 14:09:06 by iouali            #+#    #+#              #
#    Updated: 2021/02/03 13:32:56 by iouali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC        =    gcc
CFLAGS    =    -Wall -Wextra -Werror

SRCS    =   ft_printf.c \
			ft_handle_str.c \
			ft_printf_utils.c \
			ft_handle_int.c \
			ft_handle_hexa.c \
			ft_handle_flags_int.c \
			ft_parse_flags.c \
			ft_printf_utils_v2.c \
			ft_handle_flags_hexa.c \
			ft_handle_pointers.c \
			ft_handle_percent.c \
			ft_handle_flags_pointers.c

OBJS    =    ${SRCS:.c=.o}

NAME    =    libftprintf.a

LIBDIR    =    ./libft/
LIBFT    =    libft.a

RM        =    rm -f

.c.o:
		${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:    ${OBJS}
			make all -C $(LIBDIR)
			cp $(LIBDIR)/$(LIBFT) $(NAME)
			ar -rc ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}
			make clean -C $(LIBDIR)

fclean:		clean
			${RM} ${NAME}
			make fclean -C $(LIBDIR)

re:			fclean all

.PHONY:		all clean fclean re