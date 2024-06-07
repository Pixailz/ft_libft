### INTEGER
SRC_INT := integer/ft_get_base.c \
		   integer/ft_int4_chg.c \
		   integer/ft_int4_comp.c \
		   integer/ft_int4_dcomp.c \
		   integer/ft_int4_dec.c \
		   integer/ft_int4_inc.c \
		   integer/ft_itoa.c \
		   integer/ft_itoa_base.c \
		   integer/ft_ltoa.c \
		   integer/ft_ltoa_base.c \
		   integer/ft_nbrlen.c \
		   integer/ft_nbrlen_base.c \
		   integer/ft_rev_int.c \
		   integer/ft_utoa.c \
		   integer/ft_utoa_base.c

### STRING
SRC_STR := string/ft_atoi.c \
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

### PARSING
SRC_PAR := parsing/cmd/ft_try_help_usage.c \
		   parsing/cmd/ft_unknown_arg.c \
		   parsing/cmd/ft_version.c \
		   parsing/ft_is_optpresent.c \
		   parsing/ft_opt.c \
		   parsing/ft_opt_add.c \
		   parsing/ft_opt_free.c \
		   parsing/ft_opt_get.c \
		   parsing/ft_opt_long.c \
		   parsing/ft_opt_order.c \
		   parsing/ft_opt_other.c \
		   parsing/ft_opt_other_last_parsed.c \
		   parsing/ft_opt_parse.c \
		   parsing/ft_opt_perr.c \
		   parsing/ft_opt_print.c \
		   parsing/ft_opt_short.c \
		   parsing/ft_post_parse.c \
		   parsing/ft_post_parse_cmd.c

### ERROR
SRC_ERR := error/ft_error.c

### CHECK
SRC_CHK := check/ft_is_str.c \
		   check/ft_isalnum.c \
		   check/ft_isalpha.c \
		   check/ft_isascii.c \
		   check/ft_isblank.c \
		   check/ft_isdigit.c \
		   check/ft_isgoodi.c \
		   check/ft_isgoodll.c \
		   check/ft_isgoodu.c \
		   check/ft_isprint.c \
		   check/ft_isspace.c

### LIST
SRC_LST := list/ft_lstadd_back.c \
		   list/ft_lstadd_front.c \
		   list/ft_lstclear.c \
		   list/ft_lstdelone.c \
		   list/ft_lstiter.c \
		   list/ft_lstlast.c \
		   list/ft_lstmap.c \
		   list/ft_lstnew.c \
		   list/ft_lstsize.c

### PRINT
SRC_PRT := print/ft_dprintf.c \
		   print/ft_pdeb.c \
		   print/ft_perr.c \
		   print/ft_printf.c \
		   print/ft_printf/flag/hash.c \
		   print/ft_printf/flag/minus.c \
		   print/ft_printf/flag/plus.c \
		   print/ft_printf/flag/space.c \
		   print/ft_printf/flag/zero.c \
		   print/ft_printf/fmt/addr.c \
		   print/ft_printf/fmt/begin.c \
		   print/ft_printf/fmt/char.c \
		   print/ft_printf/fmt/hexa.c \
		   print/ft_printf/fmt/integer.c \
		   print/ft_printf/fmt/string.c \
		   print/ft_printf/fmt/unsigned.c \
		   print/ft_printf/ft_printf_buffer.c \
		   print/ft_printf/ft_printf_flags.c \
		   print/ft_printf/ft_printf_main.c \
		   print/ft_printf/ft_printf_padding.c \
		   print/ft_printf/ft_printf_precision.c \
		   print/ft_printf/ft_printf_type.c \
		   print/ft_printf/ft_printf_width.c \
		   print/ft_printf/padding/addr.c \
		   print/ft_printf/padding/char.c \
		   print/ft_printf/padding/hex.c \
		   print/ft_printf/padding/integer.c \
		   print/ft_printf/padding/string.c \
		   print/ft_putchar_fd.c \
		   print/ft_putendl_fd.c \
		   print/ft_putnbr_base_fd.c \
		   print/ft_putnbr_fd.c \
		   print/ft_putstr_fd.c \
		   print/ft_putunbr_fd.c \
		   print/ft_rainbow_c.c \
		   print/ft_vdprintf.c \
		   print/ft_vprintf.c

### INPUT
SRC_INP := input/ft_get_next_line.c

### RANDOM
SRC_RDM := random/ft_randchar.c \
		   random/ft_randint.c \
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
SRC_NET_IPV4 := network/ipv4/ft_getip_str.c \
				network/ipv4/ft_htoi4.c \
				network/ipv4/ft_htonl.c \
				network/ipv4/ft_htons.c \
				network/ipv4/ft_i4toh.c \
				network/ipv4/ft_ipstr.c \
				network/ipv4/ft_is_goodhost.c \
				network/ipv4/ft_ltoaddr.c \
				network/ipv4/ft_ntohl.c \
				network/ipv4/ft_ntohs.c \
				network/ipv4/ft_ntop.c \
				network/ipv4/ft_putip_fd.c \
				network/ipv4/htoi4_socket/init_packet.c \
				network/ipv4/htoi4_socket/init_socket.c \
				network/ipv4/htoi4_socket/main.c \
				network/ipv4/htoi4_socket/recv_packet.c \
				network/ipv4/htoi4_socket/send_packet.c \
				network/ipv4/i4toh_socket/init_packet.c \
				network/ipv4/i4toh_socket/init_socket.c \
				network/ipv4/i4toh_socket/main.c \
				network/ipv4/i4toh_socket/recv_packet.c \
				network/ipv4/i4toh_socket/send_packet.c

#### PACK
SRC_NET_PACK := network/packet/checksum.c \
				network/packet/dns/dnsq_fill.c \
				network/packet/dns/dnsq_get.c \
				network/packet/dns/dnsq_len.c \
				network/packet/dns/dnsr_get.c \
				network/packet/dns/get.c \
				network/packet/dns/get_a_record.c \
				network/packet/dns/get_domain_fmt.c \
				network/packet/dns/get_ptr_record.c \
				network/packet/dns/get_record/main.c \
				network/packet/dns/ip_to_domain.c \
				network/packet/dns/name_get.c \
				network/packet/dns/print.c \
				network/packet/ft_packet_get.c \
				network/packet/icmp/checksum.c \
				network/packet/icmp/get.c \
				network/packet/icmp/print.c \
				network/packet/icmp/set_seq.c \
				network/packet/ip/default.c \
				network/packet/ip/fragment_offset.c \
				network/packet/ip/get.c \
				network/packet/ip/print.c \
				network/packet/print_raw.c \
				network/packet/udp/get.c \
				network/packet/udp/print.c

SRC_NET := $(SRC_NET_IPV4) $(SRC_NET_PACK)

### ERROR
SRC_UNI_TEST := unit_test/ft_assert.c

### HASHTABLE
SRC_HASHTABLE := hashtable/ft_ht_free.c \
				 hashtable/ft_ht_get.c \
				 hashtable/ft_ht_hash_key.c \
				 hashtable/ft_ht_item.c \
				 hashtable/ft_ht_len.c \
				 hashtable/ft_ht_new.c \
				 hashtable/ft_ht_set.c

## if all, add all base to SRC_C
ifeq ($(ALL),1)
SRC_C				+= $(SRC_INT)
SRC_C				+= $(SRC_STR)
SRC_C				+= $(SRC_MEM)
SRC_C				+= $(SRC_PAR)
SRC_C				+= $(SRC_ERR)
SRC_C				+= $(SRC_CHK)
SRC_C				+= $(SRC_LST)
SRC_C				+= $(SRC_PRT)
SRC_C				+= $(SRC_INP)
SRC_C				+= $(SRC_RDM)
SRC_C				+= $(SRC_LNX)
SRC_C				+= $(SRC_NET)
SRC_C				+= $(SRC_UNI_TEST)
SRC_C				+= $(SRC_HASHTABLE)

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
ifeq ($(PARSING),1)
SRC_C			+= $(SRC_PAR)
endif
ifeq ($(ERROR),1)
SRC_C			+= $(SRC_ERR)
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
ifeq ($(NET),1)
SRC_C			+= $(SRC_NET)
endif
ifeq ($(NET_IPV4),1)
SRC_C			+= $(SRC_NET_IPV4)
endif
ifeq ($(NET_PACK),1)
SRC_C			+= $(SRC_NET_PACK)
endif
ifeq ($(UNIT_TEST),1)
SRC_C			+= $(SRC_UNI_TEST)
endif
ifeq ($(HASHTABLE),1)
SRC_C			+= $(SRC_HASHTABLE)
endif
endif

# OBJ
SRC_C				:= $(addprefix $(SRC_DIR)/,$(SRC_C))
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))

OBJ_C_NB			:= $(words $(OBJ_C))
OBJ_C_NB_LEN		:= $(shell printf "$(OBJ_C_NB)" | wc -c)
