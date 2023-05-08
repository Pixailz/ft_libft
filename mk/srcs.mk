### INTEGER
SRC_INT := integer/ft_get_base.c \
		   integer/ft_int4_chg.c \
		   integer/ft_int4_comp.c \
		   integer/ft_int4_dcomp.c \
		   integer/ft_int4_dec.c \
		   integer/ft_int4_inc.c \
		   integer/ft_itoa_base.c \
		   integer/ft_itoa.c \
		   integer/ft_ltoa_base.c \
		   integer/ft_ltoa.c \
		   integer/ft_nbrlen_base.c \
		   integer/ft_nbrlen.c \
		   integer/ft_rev_int.c \
		   integer/ft_utoa_base.c \
		   integer/ft_utoa.c

### STRING
SRC_STR := string/ft_atoi_base.c \
		   string/ft_atoi.c \
		   string/ft_atoll_base.c \
		   string/ft_atoll.c \
		   string/ft_atou_base.c \
		   string/ft_atou.c \
		   string/ft_get_words.c \
		   string/ft_patoi_base.c \
		   string/ft_patoi.c \
		   string/ft_patoll_base.c \
		   string/ft_patoll.c \
		   string/ft_patou_base.c \
		   string/ft_patou.c \
		   string/ft_splitb.c \
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
		   string/ft_strspn.c \
		   string/ft_strtok.c \
		   string/ft_strtrim.c \
		   string/ft_substr.c \
		   string/ft_tolower.c \
		   string/ft_toupper.c

### MEMORY
SRC_MEM := memory/ft_bzero.c \
		   memory/ft_calloc.c \
		   memory/ft_free_char_pp.c \
		   memory/ft_memchr.c \
		   memory/ft_memcmp.c \
		   memory/ft_memcpy.c \
		   memory/ft_memjoin.c \
		   memory/ft_memmove.c \
		   memory/ft_memnchr.c \
		   memory/ft_memset.c

### CHECK
SRC_CHK := check/ft_isalnum.c \
		   check/ft_isalpha.c \
		   check/ft_isascii.c \
		   check/ft_isblank.c \
		   check/ft_isdigit.c \
		   check/ft_isgoodi.c \
		   check/ft_isgoodll.c \
		   check/ft_isgoodu.c \
		   check/ft_isprint.c \
		   check/ft_isspace.c \
		   check/ft_is_str.c

### LIST
SRC_LST := print/ft_error.c \
		   print/ft_printf.c \
		   print/ft_printf_fd.c \
		   print/ft_putchar_fd.c \
		   print/ft_putendl_fd.c \
		   print/ft_putnbr_base_fd.c \
		   print/ft_putnbr_fd.c \
		   print/ft_putstr_fd.c \
		   print/ft_putunbr_fd.c

### PRINT
SRC_PRT := list/ft_lstadd_back.c \
		   list/ft_lstadd_front.c \
		   list/ft_lstclear.c \
		   list/ft_lstdelone.c \
		   list/ft_lstiter.c \
		   list/ft_lstlast.c \
		   list/ft_lstmap.c \
		   list/ft_lstnew.c \
		   list/ft_lstsize.c

### INPUT
SRC_INP := input/ft_get_next_line.c

### RANDOM
SRC_RDM := random/ft_randint.c \
		   random/ft_tmpfile.c

### LINUX
SRC_LNX := linux/ft_getgid.c \
		   linux/ft_getuid.c \
		   linux/ft_iscdable.c \
		   linux/ft_isdir.c \
		   linux/ft_isexec.c \
		   linux/ft_isfile.c

### NETWORK

#### IPV4
SRC_NET_IPV4	   := network/ipv4/ft_ipstr.c \
				   network/ipv4/ft_putip_fd.c

## if all, add all base to SRC_C
ifeq ($(ALL),1)
SRC_C				+= $(SRC_INT)
SRC_C				+= $(SRC_STR)
SRC_C				+= $(SRC_MEM)
SRC_C				+= $(SRC_CHK)
SRC_C				+= $(SRC_LST)
SRC_C				+= $(SRC_PRT)
SRC_C				+= $(SRC_INP)
SRC_C				+= $(SRC_RDM)
SRC_C				+= $(SRC_LNX)
SRC_C				+= $(SRC_NET_IPV4)

## add base part to SRC_C
else
ifeq ($(INTEGER),1)
SRC_C			+= $(SRC_INT)
endif
ifeq ($(STRING),1)
SRC_C			+= $(SRC_STR)
endif
ifeq ($(MEMORY),1)
SRC_C			+= $(SRC_MEM)
endif
ifeq ($(CHECK),1)
SRC_C			+= $(SRC_CHK)
endif
ifeq ($(PRINT),1)
SRC_C			+= $(SRC_PRT)
endif
ifeq ($(LIST),1)
SRC_C			+= $(SRC_LST)
endif
ifeq ($(INPUT),1)
SRC_C			+= $(SRC_INP)
endif
ifeq ($(RANDOM),1)
SRC_C			+= $(SRC_RDM)
endif
ifeq ($(LINUX),1)
SRC_C			+= $(SRC_LNX)
endif
ifeq ($(NET_IPV4),1)
SRC_C			+= $(SRC_NET_IPV4)
endif
endif

# OBJ
SRC_C				:= $(addprefix $(SRC_DIR)/,$(SRC_C))
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))


OBJ_C_NB			:= $(words $(OBJ_C))
OBJ_C_NB_LEN		:= $(shell printf "$(OBJ_C_NB)" | wc -c)
