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

workflow:		setup $(TARGET) print_usage

all:			workflow

integer:		workflow

string:			workflow

memory:			workflow

check:			workflow

list:			workflow

print:			workflow

input:			workflow

random:			workflow

linux:			workflow

ipv4:			workflow

error:			workflow

unit_test:		workflow

$(TARGET):	$(OBJ_C)
> $(call P_INF,Creating $(R)$(TARGET)$(RST))
> $(PRINTF) "\n\n"
> $(call PB_PRINT_ELAPSED)
> $(AR) rcs $(TARGET) $(OBJ_C)
> $(call PB_TARGET_DONE)

## objs
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables
# $(<)		: dependencies
# $(@)		: full target
# $(@D)		: dir target
$(OBJ_C):		$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
> $(call PB_PRINT,$(@))
> $(CC) $(CFLAGS) -o $@ -c $<

setup:	$(BIN_DIR) print_logo print_debug helper

help:
> $(PRINTF) "$$USAGE"

$(BIN_DIR):
> $(call MKDIR,$(BIN_DIR))

print_usage:
ifeq ($(DO_PRINT_USAGE),1)
> $(PRINTF) "%b" "$$USAGE"
endif

print_debug:
ifeq ($(shell [ $(DEBUG) -ge 1 ] && echo 1 || echo 0),1)
> $(call P_INF,RUNTIME INFOS)
> $(PRINTF) "\t%s"
> $(call P_WAR,DEBUG: $(DEBUG))
> $(PRINTF) "\t%s"
> $(call P_WAR,CFLAGS:)
> $(PRINTF) "\t\t%s\n" $(CFLAGS)
> $(PRINTF) "\t%s"
> $(call P_WAR,.SHELLFLAGS:)
> $(PRINTF) "\t\t%s\n"  $(.SHELLFLAGS)
> $(PRINTF) "\t%s"
> $(call P_WAR,OBJ_C:)
> $(PRINTF) "\t\t%s\n"  $(OBJ_C)
> $(PRINTF) "\t%s"
> $(call P_WAR,SRC_C:)
> $(PRINTF) "\t\t%s\n"  $(SRC_C)
> $(PRINTF) "\t$(bold)Switch$(reset)\n"
> $(PRINTF) "       $(font_color)INTEGER $(bold)%d$(reset)\n" $(INTEGER)
> $(PRINTF) "       $(font_color)STRING $(bold)%d$(reset)\n" $(STRING)
> $(PRINTF) "       $(font_color)MEMORY $(bold)%d$(reset)\n" $(MEMORY)
> $(PRINTF) "       $(font_color)CHECK $(bold)%d$(reset)\n" $(CHECK)
> $(PRINTF) "       $(font_color)LIST $(bold)%d$(reset)\n" $(LIST)
> $(PRINTF) "       $(font_color)PRINT $(bold)%d$(reset)\n" $(PRINT)
> $(PRINTF) "       $(font_color)INPUT $(bold)%d$(reset)\n" $(INPUT)
> $(PRINTF) "       $(font_color)RANDOM $(bold)%d$(reset)\n" $(RANDOM)
> $(PRINTF) "       $(font_color)LINUX $(bold)%d$(reset)\n" $(LINUX)
> $(PRINTF) "       $(font_color)NET_IPV4 $(bold)%d$(reset)\n" $(NET_IPV4)
> $(PRINTF) "       $(font_color)ERROR $(bold)%d$(reset)\n" $(ERROR)
> $(PRINTF) "\n"
> $(PRINTF) "      $(orange_star) $(font_color)ALL $(bold)%d$(reset)\n" $(ALL)
> $(PRINTF) "   $(orange_star) $(font_color)TARGET $(bold)%s$(reset)\n" $(TARGET)
> $(PRINTF) "   $(orange_star) $(bold)SRC_C$(reset)\n"
> $(PRINTF) "      $(orange_star) $(font_color)%s$(reset)\n" $(SRC_C)
> $(PRINTF) "   $(orange_star) $(bold)OBJ_C$(reset)\n"
> $(PRINTF) "      $(orange_star) $(font_color)%s$(reset)\n" $(OBJ_C)
> $(PRINTF) "$(orange_star) $(font_color)Building$(reset)\n"
endif

print_logo:
ifeq ($(LOGO_PRINTED),)
> $(PRINTF) "%b\n" "$(ASCII_COLOR)$$ASCII_BANNER$(RST)"
> $(eval export LOGO_PRINTED=1)
endif

### HELPER

helper:
ifneq ($(DISABLE_HELPER),1)
> HELPER_SETUP_NAME="ft_libft" ./rsc/helper/helper
endif

### CLEAN
clean:
> $(call P_FAI,Removing obj)
> rm -rf $(OBJ_DIR)

fclean:							clean
> $(call P_FAI,Removing $(TARGET))
> rm -rf $(TARGET)

### RE
re:						fclean workflow

## CI TEST
$(CI_BIN_DIR):
> $(call MKDIR,$@)

ci-compile: $(TARGET) $(CI_BIN_DIR)
> $(call MKDIR,$(CI_BIN_DIR)/$$(dirname $(CI_TARGET)))
> $(CC) -DCI_TEST=1 $(CFLAGS) $(CI_SRC_DIR)/$(CI_TARGET) $(TARGET) -o $(CI_BIN_DIR)/$(CI_TARGET:%.c=%)
> $(call P_PAS,compilation pass) \

ci-run: ci-compile
> $(CI_BIN_DIR)/$(CI_TARGET:%.c=%)
> $(call P_PAS,return value $(font_color)$(CI_BIN_DIR)/$(CI_TARGET:%.c=%)$(RST) [$(G)$${?}$(RST)])
