# ALIAS
## check if $(1): is a dir and if $(1) not present, then make it
MKDIR			= \
[ -f $(1) ] && rm -f $(1)														; \
if [ ! -d $(1) ]; then															\
	mkdir -p $(1)																; \
	$(call P_INF,Dir $(1) not found creating it)								\
	$(eval CREATED_DIR:=true)													\
	printf "\n"																	; \
fi																				; \


## Timestamps function
GET_TS				= $(shell date +"%s%3N")
GET_ELAPSED			= $(shell echo $$(($(call GET_TS) - $(1))))

## Bash test function
IS_GE				= [ $(1) -ge $(2) ] && printf 1 || printf 0 ;
IS_Z_OR_E			= [ -z $(1) -o $(1) -eq 0 ] && printf 1 || printf 0 ;

## print function
P_ANSI				= printf "%b" "$(ESC)$(1)";
P_INF				= printf "[%b] %b" "$(I)" "$(1)"; $(call PB_PRINT_ELAPSED)
P_WAR				= printf "[%b] %b" "$(W)" "$(1)"; $(call PB_PRINT_ELAPSED)
P_PAS				= printf "[%b] %b" "$(P)" "$(1)"; $(call PB_PRINT_ELAPSED)
P_FAI				= printf "[%b] %b" "$(F)" "$(1)"; $(call PB_PRINT_ELAPSED)
## ansi mov cursor
GOTO_COL			= $(call P_ANSI,$(1)G)

# ANSI
ESC					:= \x1b[

## COLOR
RST					:= $(ESC)0m
R					:= $(ESC)31m
G					:= $(ESC)32m
Y					:= $(ESC)33m
B					:= $(ESC)34m
M					:= $(ESC)35m
C					:= $(ESC)36m
D					:= $(ESC)39m
O					:= $(ESC)38;5;208m

## MODIFIER
BOL					:= $(ESC)1m

### COMPOSITE
I					:= $(BOL)$(C)*$(RST)
W					:= $(BOL)$(O)!$(RST)
P					:= $(BOL)$(G)+$(RST)
F					:= $(BOL)$(R)-$(RST)
ASCII_COLOR			:= $(G)

## CURSOR
CU					:= $(ESC)1F
DL					:= $(ESC)2K
CUDL				:= $(CU)$(DL)

bold				:= $(D)
font_color			:= $(G)

define ASCII_BANNER
███████╗████████╗     ██╗     ██╗██████╗ ███████╗████████╗
██╔════╝╚══██╔══╝     ██║     ██║██╔══██╗██╔════╝╚══██╔══╝
█████╗     ██║        ██║     ██║██████╔╝█████╗     ██║
██╔══╝     ██║        ██║     ██║██╔══██╗██╔══╝     ██║
██║        ██║        ███████╗██║██████╔╝██║        ██║
╚═╝        ╚═╝        ╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝
endef
export ASCII_BANNER

define USAGE
$(bold)modulable$(font_color) ft_library
	You can make $(bold)any$(font_color) parts into the archive of the library.
		$(bold)exemple$(font_color):
			make $(bold)string$(font_color)
			make $(bold)string integer$(font_color)
			make re $(bold)string integer$(font_color)

	The following parts are available (non-exhaustive list of function):
		$(bold)integer$(font_color)\t\tmanipulate integer
			$(bold)ft_itoa$(font_color), $(bold)ft_nbrlen$(font_color), \
$(bold)ft_int4_comp

		string$(font_color)\t\tmanipulate string
			$(bold)ft_atoi$(font_color), $(bold)ft_strlen$(font_color), \
$(bold)ft_strjoin

		memory$(font_color)\t\tmanipulate / allocate memory
			$(bold)ft_calloc$(font_color), $(bold)ft_memchr$(font_color), \
$(bold)ft_memjoin

		check$(font_color)\t\tcheck something
			$(bold)ft_isalnum$(font_color), $(bold)ft_isgoodi

		list$(font_color)\t\twork with linked list
			$(bold)ft_lstnew$(font_color), $(bold)ft_lstadd_back

		print$(font_color)\t\tprint something
			$(bold)ft_printf$(font_color), $(bold)ft_dprintf$(font_color),\
$(bold)ft_putchar

		input$(font_color)\t\twork with input
			$(bold)ft_get_next_line

		random$(font_color)\t\twork with randomness
			$(bold)ft_randint$(font_color), $(bold)ft_tmpfile

		linux$(font_color)\t\twork with linux
			$(bold)ft_iscdable$(font_color), $(bold)ft_getuid$(font_color), \
$(bold)ft_getgid

		error$(font_color)\t\tfunction and enum to help with error
			$(bold)ft_perror

		unit_test$(font_color)\tfunction to make sure some other function work \
as expected
			$(bold)ft_assert

		parsing$(font_color)\t\tfunction to make parsing of scripting easy
			$(bold)ft_optadd$(font_color), $(bold)ft_optparse$(font_color), \
$(bold)ft_optget

		sort$(font_color)\t\tfunction to sort all sort of thing
			$(bold)ft_qsort$(font_color)

$(font_color)Version: $(bold)$(VERSION)$(RST)

endef
export USAGE
