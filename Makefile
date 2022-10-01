# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2022/10/01 18:20:47 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# config

VERSION				:= 1.0.0
MULTIPLE			:= 0

ifeq ($(findstring integer,$(MAKECMDGOALS)),integer)
INTEGER			:= 1
MULTIPLE		:= 1
endif
ifeq ($(findstring string,$(MAKECMDGOALS)),string)
STRING			:= 1
MULTIPLE		:= 1
endif
ifeq ($(findstring memory,$(MAKECMDGOALS)),memory)
MEMORY			:= 1
MULTIPLE		:= 1
endif
ifeq ($(findstring check,$(MAKECMDGOALS)),check)
CHECK			:= 1
MULTIPLE		:= 1
endif
ifeq ($(findstring list,$(MAKECMDGOALS)),list)
LIST			:= 1
MULTIPLE		:= 1
endif
ifeq ($(findstring print,$(MAKECMDGOALS)),print)
PRINT			:= 1
MULTIPLE		:= 1
endif
ifeq ($(findstring input,$(MAKECMDGOALS)),input)
INPUT			:= 1
MULTIPLE		:= 1
endif
ifeq ($(findstring random,$(MAKECMDGOALS)),random)
RANDOM			:= 1
MULTIPLE		:= 1
endif
ifeq ($(findstring linux,$(MAKECMDGOALS)),linux)
LINUX			:= 1
MULTIPLE		:= 1
endif
ifeq ($(MULTIPLE), 0)
ALL				:= 1
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
OBJ_DIR				:= obj
OBJ_SUBDIR			:= $(sort $(shell find $(SRC_DIR) -type d | \
										sed 's|$(SRC_DIR)|$(OBJ_DIR)|g'))
INC_DIR				:= -Iinc

# SRC
SRC_INT				:= integer/ft_get_base.c \
					   integer/ft_itoa.c \
					   integer/ft_itoa_base.c \
					   integer/ft_ltoa.c \
					   integer/ft_ltoa_base.c \
					   integer/ft_nbrlen.c \
					   integer/ft_nbrlen_base.c \
					   integer/ft_rev_int.c \
					   integer/ft_utoa.c \
					   integer/ft_utoa_base.c

ifneq ($(ALL),1)
SRC_INT				+= string/ft_strlen.c
endif

ifeq ($(INTEGER),1)
SRC_C_TMP			+= $(SRC_INT)
endif

SRC_STR				:= string/ft_atoi.c \
					   string/ft_atoi_base.c \
					   string/ft_atoll.c \
					   string/ft_atoll_base.c \
					   string/ft_atou.c \
					   string/ft_atou_base.c \
					   string/ft_get_words.c \
					   string/ft_patoi.c \
					   string/ft_patoi_base.c \
					   string/ft_patoll.c \
					   string/ft_patoll_base.c \
					   string/ft_patou.c \
					   string/ft_patou_base.c \
					   string/ft_split.c \
					   string/ft_splitb.c \
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
					   string/ft_strspn.c \
					   string/ft_strtok.c \
					   string/ft_strtrim.c \
					   string/ft_substr.c \
					   string/ft_tolower.c \
					   string/ft_toupper.c

ifneq ($(ALL),1)
SRC_STR				+= integer/ft_nbrlen_base.c \
					   integer/ft_nbrlen.c \
					   integer/ft_get_base.c \
					   memory/ft_calloc.c \
					   memory/ft_memset.c \
					   check/ft_isgoodi.c \
					   check/ft_isgoodll.c \
					   check/ft_isgoodu.c
endif

ifeq ($(STRING),1)
SRC_C_TMP			+= $(SRC_STR)
endif

SRC_MEM				:= memory/ft_bzero.c \
					   memory/ft_calloc.c \
					   memory/ft_memchr.c \
					   memory/ft_memcmp.c \
					   memory/ft_memcpy.c \
					   memory/ft_memjoin.c \
					   memory/ft_memmove.c \
					   memory/ft_memnchr.c \
					   memory/ft_memset.c

ifneq ($(ALL),1)
SRC_MEM				+= string/ft_strlen.c
endif

ifeq ($(MEMORY),1)
SRC_C_TMP			+= $(SRC_MEM)
endif

SRC_CHK				:= check/ft_isalnum.c \
					   check/ft_isalpha.c \
					   check/ft_isascii.c \
					   check/ft_isblank.c \
					   check/ft_isdigit.c \
					   check/ft_isdir.c \
					   check/ft_isfile.c \
					   check/ft_isgoodi.c \
					   check/ft_isgoodll.c \
					   check/ft_isgoodu.c \
					   check/ft_isprint.c \
					   check/ft_isspace.c

ifeq ($(CHECK),1)
SRC_C_TMP			+= $(SRC_CHK)
endif

SRC_LST				:= list/ft_lstadd_back.c \
					   list/ft_lstadd_front.c \
					   list/ft_lstclear.c \
					   list/ft_lstdelone.c \
					   list/ft_lstiter.c \
					   list/ft_lstlast.c \
					   list/ft_lstmap.c \
					   list/ft_lstnew.c \
					   list/ft_lstsize.c

ifeq ($(LIST),1)
SRC_C_TMP			+= $(SRC_LST)
endif

SRC_PRT				:= print/ft_error.c \
					   print/ft_printf.c \
					   print/ft_printf_fd.c \
					   print/ft_putchar_fd.c \
					   print/ft_putendl_fd.c \
					   print/ft_putnbr_fd.c \
					   print/ft_putstr_fd.c \
					   print/ft_putunbr_fd.c

ifneq ($(ALL),1)
SRC_PRT				+= integer/ft_itoa_base.c \
					   string/ft_strlen.c \
					   print/ft_putnbr_fd.c \
					   print/ft_putunbr_fd.c \
					   integer/ft_nbrlen_base.c \
					   integer/ft_nbrlen.c \
					   memory/ft_calloc.c \
					   memory/ft_memset.c
endif

ifeq ($(PRINT),1)
SRC_C_TMP			+= $(SRC_PRT)
endif

SRC_INP				:= input/ft_get_next_line.c

ifneq ($(ALL),1)
SRC_INP				+= memory/ft_memchr.c \
					   memory/ft_memjoin.c \
					   string/ft_strlen.c
endif

ifeq ($(INPUT),1)
SRC_C_TMP			+= $(SRC_INP)
endif

SRC_RDM				:= random/ft_randint.c \
					   random/ft_tmpfile.c

ifneq ($(ALL),1)
SRC_RDM				+= string/ft_strlen.c \
					   memory/ft_calloc.c \
					   string/ft_strncpy.c
endif

ifeq ($(RANDOM),1)
SRC_C_TMP			+= $(SRC_RDM)
endif

SRC_LNX				:= linux/ft_getgid.c \
					   linux/ft_getuid.c \
					   linux/ft_iscdable.c

ifneq ($(ALL),1)
SRC_LNX				+= check/ft_isdir.c \
					   random/ft_tmpfile.c
endif

ifeq ($(LINUX),1)
SRC_C_TMP			+= $(SRC_LNX)
endif

SRC_C				:= $(SRC_C_TMP)

ifeq ($(ALL),1)
SRC_C				:= $(SRC_INT)
SRC_C				+= $(SRC_STR)
SRC_C				+= $(SRC_MEM)
SRC_C				+= $(SRC_CHK)
SRC_C				+= $(SRC_LST)
SRC_C				+= $(SRC_PRT)
SRC_C				+= $(SRC_INP)
SRC_C				+= $(SRC_RDM)
SRC_C				+= $(SRC_LNX)
endif

SRC_C				:= $(addprefix $(SRC_DIR)/,$(SRC_C))

# OBJ
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))

# LIB DIR
CFLAGS				+= $(INC_DIR)

#  Bash Color / unicode char

get_random		= \033[38;5;$(shell seq 0 256 | shuf | head -n1)m
green				:= \033[38;5;82m
blue				:= \033[38;5;75m
red					:= \033[38;5;196m
orange				:= \033[38;5;214m

blinking			:= \033[5m
reset				:= \033[0m

font_color			:= $(blue)
bold				:= $(green)
ascii_color			:= $(bold)

green_plus			:= $(font_color)[$(green)+$(font_color)]$(reset)
red_minus			:= $(font_color)[$(red)-$(font_color)]$(reset)
orange_star			:= $(font_color)[$(orange)*$(font_color)]$(reset)
blinking_arrow		:= $(blinking)$(font_color)->$(reset)

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
███████╗████████╗     ██╗     ██╗██████╗ ███████╗████████╗
██╔════╝╚══██╔══╝     ██║     ██║██╔══██╗██╔════╝╚══██╔══╝
█████╗     ██║        ██║     ██║██████╔╝█████╗     ██║
██╔══╝     ██║        ██║     ██║██╔══██╗██╔══╝     ██║
██║        ██║        ███████╗██║██████╔╝██║        ██║
╚═╝        ╚═╝        ╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝
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

# rules that does not create file
.PHONY:					clean fclean setup call_logo $(OBJ_SUBDIR)

all:					setup $(TARGET)
	@printf "$$usage"

integer:	setup $(TARGET)
	@printf ""

string:		setup $(TARGET)
	@printf ""

memory:		setup $(TARGET)
	@printf ""

check:		setup $(TARGET)
	@printf ""

list:		setup $(TARGET)
	@printf ""

print:		setup $(TARGET)
	@printf ""

input:		setup $(TARGET)
	@printf ""

random:		setup $(TARGET)
	@printf ""

linux:		setup $(TARGET)
	@printf ""

$(TARGET):				$(OBJ_C)
	@printf "$(green_plus) $(font_color)Creation of $(bold)$@$(reset)\n"
	@ar rcs $(TARGET) $(OBJ_C)

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.c
	$(call print_padded,$^,$@)
	@$(CC) $(CFLAGS) -o $@ -c $<

setup:					call_logo $(OBJ_SUBDIR)
ifeq ($(DEBUG),1)
	@printf "$(orange_star) $(font_color)Info$(reset)\n"
	@printf "   $(orange_star) $(bold)Switch$(reset)\n"
	@printf "      $(orange_star) $(font_color)INTEGER $(bold)%d$(reset)\n" $(INTEGER)
	@printf "      $(orange_star) $(font_color)STRING $(bold)%d$(reset)\n" $(STRING)
	@printf "      $(orange_star) $(font_color)MEMORY $(bold)%d$(reset)\n" $(MEMORY)
	@printf "      $(orange_star) $(font_color)CHECK $(bold)%d$(reset)\n" $(CHECK)
	@printf "      $(orange_star) $(font_color)LIST $(bold)%d$(reset)\n" $(LIST)
	@printf "      $(orange_star) $(font_color)PRINT $(bold)%d$(reset)\n" $(PRINT)
	@printf "      $(orange_star) $(font_color)INPUT $(bold)%d$(reset)\n" $(INPUT)
	@printf "      $(orange_star) $(font_color)RANDOM $(bold)%d$(reset)\n" $(RANDOM)
	@printf "      $(orange_star) $(font_color)LINUX $(bold)%d$(reset)\n" $(LINUX)
	@printf "      $(orange_star) $(font_color)ALL $(bold)%d$(reset)\n" $(ALL)
	@printf "   $(orange_star) $(font_color)TARGET $(bold)%s$(reset)\n" $(TARGET)
	@printf "   $(orange_star) $(bold)SRC_C$(reset)\n"
	@printf "      $(orange_star) $(font_color)%s$(reset)\n" $(SRC_C)
	@printf "   $(orange_star) $(bold)OBJ_C$(reset)\n"
	@printf "      $(orange_star) $(font_color)%s$(reset)\n" $(OBJ_C)
	@printf "$(orange_star) $(font_color)Building$(reset)\n"
endif

call_logo:
	@printf "$(ascii_color)$$ascii_art"

$(OBJ_SUBDIR):
	$(foreach dir,$@,$(call make_dir,$(dir)))

clean:
ifneq ($(wildcard $(OBJ_DIR)),)
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(OBJ_DIR)$(reset)\n"
	@$(RM) $(OBJ_DIR)
endif

fclean:					clean
ifneq ($(wildcard $(TARGET)),)
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(TARGET)$(reset)\n"
	@$(RM) $(TARGET)
endif

re:						fclean all

# **************************************************************************** #
