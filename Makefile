# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2022/06/30 22:10:05 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# config

VERSION				:= 1.0.0
ifeq ($(findstring integer,$(MAKECMDGOALS)),integer)
INTEGER				:= 1
else
ifeq ($(findstring string,$(MAKECMDGOALS)),string)
STRING				:= 1
else
ALL					:= 1
endif
endif
TARGET				:= libft.a
CFLAGS				:= -Wall -Wextra -pthread
RM					:= rm -rf
CC					:= gcc
MAKE				:= make -C
$(eval export MAIN=1)

ifneq ($(PADDING),35)
PADDING				:= 35
endif

ifeq ($(DEBUG),)
CFLAGS				+= -Werror
else
CFLAGS				+= -g3
endif

# DIR
SRC_DIR				:= src
OBJ_DIR				:= obj_bonus
OBJ_SUBDIR			:= $(sort $(shell find $(SRC_DIR) -type d | \
										sed 's|$(SRC_DIR)|$(OBJ_DIR)|g'))
INC_DIR				:= -Iincludes

# SRC
SRC_INT				:= integer/ft_atoi.c \
					   integer/ft_atol.c \
					   integer/ft_atoll.c \
					   integer/ft_nbrlen.c \
					   integer/ft_rev_int.c

SRC_STR				:= string/ft_get_words.c \
					   string/ft_itoa.c \
					   string/ft_ltoa.c \
					   string/ft_split.c \
					   string/ft_strcat.c \
					   string/ft_strcchr.c \
					   string/ft_strchr.c \
					   string/ft_strclr.c \
					   string/ft_strcmp.c \
					   string/ft_strcpy.c \
					   string/ft_strcspn.c \
					   string/ft_strdel.c \
					   string/ft_strdup.c \
					   string/ft_striteri.c \
					   string/ft_strjoin.c \
					   string/ft_strlcat.c \
					   string/ft_strlcpy.c \
					   string/ft_strlen.c \
					   string/ft_strmapi.c \
					   string/ft_strncat.c \
					   string/ft_strncmp.c \
					   string/ft_strncpy.c \
					   string/ft_strnstr.c \
					   string/ft_strrchr.c \
					   string/ft_strtrim.c \
					   string/ft_substr.c \
					   string/ft_tolower.c \
					   string/ft_toupper.c
ifeq ($(INTEGER),1)
SRC_C				:= $(SRC_INT)
else
ifeq ($(STRING),1)
SRC_C				:= $(SRC_STR)
else
SRC_C				:= $(SRC_INT)
SRC_C				+= $(SRC_STR)
endif
endif

# OBJ
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))

# LIB DIR
CFLAGS				+= $(INC_DIR)

#  Bash Color / unicode char

#get_random		= $(shell seq 0 256 | shuf | head -n1)
green				:= \033[38;5;82m
blue				:= \033[38;5;75m
red					:= \033[38;5;196m
orange				:= \033[38;5;214m

blinking			:= \033[5m
reset				:= \033[0m

font_color			:= $(blue)
bold				:= $(green)
ascii_color			:= $(bold)

green_plus			:= $(font_color)[$(green)+$(font_color)]
red_minus			:= $(font_color)[$(red)-$(font_color)]
orange_star			:= $(font_color)[$(orange)*$(font_color)]
blinking_arrow		:= $(blinking)$(font_color)->
#font_color			:= \033[38;5;$(get_random)m
#bold				:= \033[38;5;$(get_random)m
#ascii_color		:= \033[38;5;$(get_random)m

UL="\xe2\x95\x94"
HO="\xe2\x95\x90"
UR="\xe2\x95\x97"
VE="\xe2\x95\x91"
LL="\xe2\x95\x9a"
LR="\xe2\x95\x9d"

# **************************************************************************** #

# **************************************************************************** #
# utils

define ascii_art
██████╗ ██╗  ██╗██╗██╗      ██████╗
██╔══██╗██║  ██║██║██║     ██╔═══██╗
██████╔╝███████║██║██║     ██║   ██║
██╔═══╝ ██╔══██║██║██║     ██║   ██║
██║     ██║  ██║██║███████╗╚██████╔╝
╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝
$(reset)
endef
export ascii_art

define print_padded
	@printf '   $(orange_star) $(font_color)Creation of $(bold)$1'
	$(eval OBJ_LEN := $(shell printf $1 | wc -c))
	$(eval PAD_LEN := $(shell expr $(PADDING) - $(OBJ_LEN)))
	@printf '%-$(PAD_LEN)s' ' '
	@printf '$(blinking_arrow) $(reset)$(bold)$2 $(reset)'
	@printf '\n'
endef

define usage
$(orange_star) $(bold)$(TARGET)$(font_color): $(bold)needed_args \
$(font_color)[$(bold)optional_args$(font_color)]$(reset)
        $(bold)arg$(font_color): eplanation
        $(bold)arg$(font_color): eplanation
        $(bold)arg$(font_color): eplanation, $(bold)WARNING$(reset)
$(font_color)Version: $(bold)$(VERSION)$(reset)

endef
export usage

define make_dir
	@if [ ! -d $1 ]; then														\
		mkdir $1;																\
		printf "$(green_plus) $(font_color)Create dir $(bold)$1$(reset)\n";		\
	fi
endef

# **************************************************************************** #

# **************************************************************************** #
# Rules

all:					setup $(TARGET)
	@printf "$$usage"

bonus:					setup $(TARGET)
	@printf "$$usage"

$(TARGET):				$(OBJ_C)
	@printf "$(green_plus) $(font_color)Creation of $(bold)$@$(reset)\n"
	@$(CC) $(CFLAGS) -o $@ $(OBJ_C)

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.c
	$(call print_padded,$^,$@)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(BIN_DIR):
	@printf "$(green_plus) $(font_color)Create dir $(bold)$(BIN_DIR)$(reset)\n"
	@mkdir $(BIN_DIR)

setup:					call_logo $(OBJ_SUBDIR) $(BIN_DIR)

call_logo:
	@printf "$(ascii_color)$$ascii_art"

$(OBJ_SUBDIR):
	$(foreach dir,$@,$(call make_dir,$(dir)))

clean:
ifneq ($(wildcard ./obj),)
	@printf "$(red_minus) $(font_color)Deleting $(bold)obj$(reset)\n"
	@$(RM) ./obj
endif
ifneq ($(wildcard ./obj_bonus),)
	@printf "$(red_minus) $(font_color)Deleting $(bold)obj_bonus$(reset)\n"
	@$(RM) ./obj_bonus
endif

fclean:					clean
ifneq ($(wildcard ./bin/philo),)
	@printf "$(red_minus) $(font_color)Deleting $(bold)bin/philo$(reset)\n"
	@$(RM) ./bin/philo
endif
ifneq ($(wildcard ./bin/philo_bonus),)
	@printf "$(red_minus) $(font_color)Deleting $(bold)bin/philo_bonus$(reset)\n"
	@$(RM) ./bin/philo_bonus
endif
ifneq ($(wildcard $(BIN_DIR)),)
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(BIN_DIR)$(reset)\n"
	@$(RM) -rf $(BIN_DIR)
endif

re:						fclean all

re_bonus:				fclean bonus

.PHONY:					all clean fclean re setup call_logo bonus

# **************************************************************************** #
