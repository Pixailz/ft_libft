# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stales <stales@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 18:23:35 by stales            #+#    #+#              #
#    Updated: 2022/04/04 18:48:20 by stales           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  Bash Color

green			:= \033[38;5;82m
blue			:= \033[38;5;75m
red				:= \033[38;5;196m
yellow			:= \033[38;5;226m

blinking		:= \033[5m
reset			:= \033[0m

font_color		:= $(blue)
bold			:= $(red)

define print_ascii
	@printf "$(red)"
	@printf "██▓     ██▓ ▄▄▄▄     █████▒▄▄▄█████▓\n"
	@printf "▓██▒    ▓██▒▓█████▄ ▓██   ▒ ▓  ██▒ ▓▒\n"
	@printf "▒██░    ▒██▒▒██▒ ▄██▒████ ░ ▒ ▓██░ ▒░\n"
	@printf "▒██░    ░██░▒██░█▀  ░▓█▒  ░ ░ ▓██▓ ░\n"
	@printf "░██████▒░██░░▓█  ▀█▓░▒█░      ▒██▒ ░\n"
	@printf "░ ▒░▓  ░░▓  ░▒▓███▀▒ ▒ ░      ▒ ░░\n"
	@printf "░ ░ ▒  ░ ▒ ░▒░▒   ░  ░          ░\n"
	@printf "  ░ ░    ▒ ░ ░    ░  ░ ░      ░\n"
	@printf "    ░  ░ ░   ░\n"
	@printf "                  ░\n"
	@printf "$(reset)"
endef

# **************************************************************************** #

# **************************************************************************** #
# config

BASE_SRC		:= ft_atoi.c \
				   ft_bzero.c \
				   ft_calloc.c \
				   ft_get_words.c \
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
				   ft_nbrlen.c \
				   ft_putchar_fd.c \
				   ft_putendl_fd.c \
				   ft_putnbr_fd.c \
				   ft_putstr_fd.c \
				   ft_split.c \
				   ft_strcchr.c \
				   ft_strchr.c \
				   ft_strdup.c \
				   ft_striteri.c \
				   ft_strcpy.c \
				   ft_strcat.c \
				   ft_strjoin.c \
				   ft_strlcat.c \
				   ft_strlcpy.c \
				   ft_strlen.c \
				   ft_strmapi.c \
				   ft_strncat.c \
				   ft_strncmp.c \
				   ft_strncpy.c \
				   ft_strnstr.c \
				   ft_strrchr.c \
				   ft_strtrim.c \
				   ft_substr.c \
				   ft_tolower.c \
				   ft_toupper.c

BONUS_SRC		:= $(BASE_SRC) \
				   ft_lstadd_back_bonus.c \
				   ft_lstadd_front_bonus.c \
				   ft_lstclear_bonus.c \
				   ft_lstdelone_bonus.c \
				   ft_lstiter_bonus.c \
				   ft_lstlast_bonus.c \
				   ft_lstmap_bonus.c \
				   ft_lstnew_bonus.c \
				   ft_lstsize_bonus.c

BONUS_SRC		:= $(sort $(BONUS_SRC))

OBJ				:= $(BASE_SRC:.c=.o)
BONUS_OBJ		:= $(BONUS_SRC:.c=.o)
CFLAGS			:= -Wall -Wextra -Werror -I.
NAME			:= libft.a
LIBSHARE		:= libft.so

# **************************************************************************** #

# **************************************************************************** #
# Building rules

all:			$(NAME)

%.o: %.c
	@tabs 18
	@printf "$(font_color)[$(green)+$(font_color)] Creation of the object $(bold)$< $(blinking)$(font_color)\t-> $(reset)$(bold) $@ $(reset)\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):		$(OBJ)
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)libft.a$(reset)\n"
	@ar rcs $(NAME) $(OBJ)
	$(print_ascii)

so:
	$(CC) -c -fPIC $(CFLAGS) $(BASE_SRC)
	gcc -nostartfiles -shared -o $(LIBSHARE) $(OBJ)

clean:
	@printf "$(font_color)[$(red)-$(font_color)] Deleting object files$(reset)\n"
	@$(RM) $(OBJ)
	@$(RM) $(BONUS_OBJ)
	@$(RM) $(LIBSHARE)

fclean:			clean
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)$(NAME)$(reset)\n"
	@$(RM) $(NAME) $(LIBSHARE)

re:				fclean $(NAME)

bonus:			$(BONUS_OBJ)
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)libft.a$(font_color) with bonus $(reset)\n"
	@ar rcs $(NAME) $(BONUS_OBJ)
	$(print_ascii)

.PHONY:			all clean fclean re

# **************************************************************************** #
