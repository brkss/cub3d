# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adriouic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 23:09:51 by adriouic          #+#    #+#              #
#    Updated: 2022/05/11 22:25:34 by adriouic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
FILES	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		   	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		   	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		   	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strstr.c ft_strreplace.c

B_FILES	=	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

objs	=	${FILES:.c=.o}

bobjs	=	${B_FILES:.c=.o}

NAME	=	libft.a

FLAGS		=	-Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o  ${<:.c=.o}
	ar rcs $(NAME) ${<:.c=.o}

$(NAME): $(objs)


bonus: $(bobjs)

clean:
	rm -f $(objs) $(bobjs)

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: fclean clean bonus re all
