# include
include mk/config.mk			# base config
include mk/utils.mk				# utils function / var
include mk/srcs.mk				# srcs.mk
include mk/pb.mk				# ui thing, progress bar etc

$(call PB_INIT)

# rule
## config
.SILENT:

.PHONY: setup

.DEFAULT: all

all:			setup $(TARGET) print_usage

integer:		setup $(TARGET) print_usage

string:			setup $(TARGET) print_usage

memory:			setup $(TARGET) print_usage

check:			setup $(TARGET) print_usage

list:			setup $(TARGET) print_usage

print:			setup $(TARGET) print_usage

input:			setup $(TARGET) print_usage

random:			setup $(TARGET) print_usage

linux:			setup $(TARGET) print_usage

ipv4:			setup $(TARGET) print_usage

### TARGETS
$(TARGET):		$(OBJ_C)
> $(call P_INF,Creating $(R)$(TARGET)$(RST))
> printf "\n\n"
> $(call PB_PRINT_ELAPSED)
> ar rcs $(TARGET) $(OBJ_C)
> $(call PB_TARGET_DONE)


## objs
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables
# $(<)		: dependencies
# $(@)		: full target
# $(@D)		: dir target
$(OBJ_C):		$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
> $(call PB_PRINT,$(@))
> gcc $(CFLAGS) -o $@ -c $<

### LIBS
$(LIBFT):
ifeq ($(USE_LIBFT),1)
> make -C lib/ft_libft all
endif

$(MINI_LIBX):
ifeq ($(USE_MINI_LIBX),1)
> make -C lib/minilibx-linux all
endif

setup:	$(BIN_DIR) print_logo print_debug corrector

help:
> printf "$$USAGE"

$(BIN_DIR):
> $(call MKDIR,$(BIN_DIR))

print_usage:
> printf "%b" "$$USAGE"

print_debug:
ifeq ($(shell [ $(DEBUG) -ge 1 ] && printf 1 || printf 0),1)
> $(call P_INF,RUNTIME INFOS)
> printf "\t%s"
> $(call P_WAR,DEBUG: $(DEBUG))
> printf "\t%s"
> $(call P_WAR,CFLAGS:)
> printf "\t\t%s\n" $(CFLAGS)
> printf "\t%s"
> $(call P_WAR,.SHELLFLAGS:)
> printf "\t\t%s\n"  $(.SHELLFLAGS)
> printf "\t%s"
> $(call P_WAR,OBJ_C:)
> printf "\t\t%s\n"  $(OBJ_C)
> printf "\t%s"
> $(call P_WAR,SRC_C:)
> printf "\t\t%s\n"  $(SRC_C)
> printf "\t$(bold)Switch$(reset)\n"
> printf "       $(font_color)INTEGER $(bold)%d$(reset)\n" $(INTEGER)
> printf "       $(font_color)STRING $(bold)%d$(reset)\n" $(STRING)
> printf "       $(font_color)MEMORY $(bold)%d$(reset)\n" $(MEMORY)
> printf "       $(font_color)CHECK $(bold)%d$(reset)\n" $(CHECK)
> printf "       $(font_color)LIST $(bold)%d$(reset)\n" $(LIST)
> printf "       $(font_color)PRINT $(bold)%d$(reset)\n" $(PRINT)
> printf "       $(font_color)INPUT $(bold)%d$(reset)\n" $(INPUT)
> printf "       $(font_color)RANDOM $(bold)%d$(reset)\n" $(RANDOM)
> printf "       $(font_color)LINUX $(bold)%d$(reset)\n" $(LINUX)
> printf "       $(font_color)NET_IPV4 $(bold)%d$(reset)\n" $(NET_IPV4)
> printf "\n"
> printf "      $(orange_star) $(font_color)ALL $(bold)%d$(reset)\n" $(ALL)
> printf "   $(orange_star) $(font_color)TARGET $(bold)%s$(reset)\n" $(TARGET)
> printf "   $(orange_star) $(bold)SRC_C$(reset)\n"
> printf "      $(orange_star) $(font_color)%s$(reset)\n" $(SRC_C)
> printf "   $(orange_star) $(bold)OBJ_C$(reset)\n"
> printf "      $(orange_star) $(font_color)%s$(reset)\n" $(OBJ_C)
> printf "$(orange_star) $(font_color)Building$(reset)\n"
endif

print_logo:
ifeq ($(LOGO_PRINTED),)
> printf "%b\n" "$(ASCII_COLOR)$$ASCII_BANNER$(RST)"
> $(eval export LOGO_PRINTED=1)
endif

### CORRECTOR

corrector:				export_vars
> ./rsc/corrector/run

export_vars:
export MK_DIR
export SRC_DIR

### RUN
run:					re
> ./$(TARGET)

### CLEAN
clean:
> $(call P_FAI,Removing obj)
> rm -rf $(OBJ_DIR)

clean_all:				clean
> make -C lib/ft_libft clean
> make -C lib/minilibx-linux clean

fclean:							clean
> $(call P_FAI,Removing $(TARGET))
> rm -rf $(TARGET)

fclean_all:				fclean
> make -C lib/ft_libft fclean
> make -C lib/minilibx-linux clean

### RE
re:						setup fclean $(TARGET)
