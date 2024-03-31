# BASE
TARGET				:= libft.a
CC					:= gcc
AR					:= ar
PRINTF				:= @printf
VERSION				:= 1.6.0
CFLAGS				:= -Wall -Wextra -DVERSION='"$(VERSION)"'

# check if the makefile is called from another or directly called
ifeq ($(MAIN),1)
DO_PRINT_USAGE		:= 0
else
DO_PRINT_USAGE		:= 1
endif

MAIN				:= 1
export MAIN

# SPECIFY MAKEFILE FLAGS (not working with re)
# MAKEFLAGS			:= --jobs=$(shell nproc)	# number of jobs
# MAKEFLAGS			+= --output-sync=target		# sync output, avoid intermixed result
MAKEFLAGS			:= --no-print-directory

# BASH
SHELL				:= /usr/bin/bash			# set bash path
.SHELLFLAGS			:= -eu -o pipefail -c		# set bash strict mode

# Always use GNU Make.
ifeq ($(origin .RECIPEPREFIX), undefined)
  $(error This Make does not support .RECIPEPREFIX. Please use GNU Make 4.0 or later)
endif
## Use '>' to instead of tab.
.RECIPEPREFIX		= >

## DEBUG
ifeq ($(shell [ -z $(DEBUG) ] && printf 1 || printf 0),1)
DEBUG				:= 0
endif
CFLAGS				+= -DDEBUG=$(DEBUG) -DDEBUG_FD=420

ifeq ($(shell [ -z $(DEBUG_MAKE) ] && printf 1 || printf 0),1)
DEBUG_MAKE			:= 0
endif

ifeq ($(DEBUG),0)
CFLAGS				+= -Werror
else
ifeq ($(shell [ $(DEBUG) -ge 1 ] && printf 1 || printf 0),1)
CFLAGS				+= -g3
endif
ifeq ($(shell [ $(DEBUG) -ge 2 ] && printf 1 || printf 0),1)
.SHELLFLAGS			+= -x
endif
endif

## PARSE_VARIABLE
### LIB_PART
MULTIPLE			:= 0
ifeq ($(findstring integer,$(MAKECMDGOALS)),integer)
INTEGER			:= 1
MULTIPLE		:= 1
# dependecies
STRING			:= 1
endif
ifeq ($(findstring string,$(MAKECMDGOALS)),string)
STRING			:= 1
MULTIPLE		:= 1
# dependecies
INTEGER			:= 1
CHECK			:= 1
MEMORY			:= 1
endif
ifeq ($(findstring memory,$(MAKECMDGOALS)),memory)
MEMORY			:= 1
MULTIPLE		:= 1
# dependecies
STRING			:= 1
endif
ifeq ($(findstring parsing,$(MAKECMDGOALS)),parsing)
PARSING			:= 1
MULTIPLE		:= 1
# dependecies
MEMORY			:= 1
PRINT			:= 1
endif
ifeq ($(findstring error,$(MAKECMDGOALS)),error)
ERROR			:= 1
MULTIPLE		:= 1
# dependecies
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
# dependecies
STRING			:= 1
MEMORY			:= 1
INTEGER			:= 1
endif
ifeq ($(findstring input,$(MAKECMDGOALS)),input)
INPUT			:= 1
MULTIPLE		:= 1
# dependecies
STRING			:= 1
MEMORY			:= 1
endif
ifeq ($(findstring random,$(MAKECMDGOALS)),random)
RANDOM			:= 1
MULTIPLE		:= 1
# dependecies
STRING			:= 1
MEMORY			:= 1
endif
ifeq ($(findstring linux,$(MAKECMDGOALS)),linux)
LINUX			:= 1
MULTIPLE		:= 1
# dependecies
RANDOM			:= 1
CHECK			:= 1
endif
ifeq ($(findstring ipv4,$(MAKECMDGOALS)),ipv4)
NET_IPV4		:= 1
MULTIPLE		:= 1
# dependecies
PRINT			:= 1
INTEGER			:= 1
CHECK			:= 1
STRING			:= 1
MEMORY			:= 1
endif
ifeq ($(findstring error,$(MAKECMDGOALS)),error)
ERROR			:= 1
MULTIPLE		:= 1
# dependecies
PRINT			:= 1
endif
ifeq ($(findstring unit_test,$(MAKECMDGOALS)),unit_test)
UNIT_TEST		:= 1
MULTIPLE		:= 1
# dependecies
PRINT			:= 1
endif
ifeq ($(MULTIPLE), 0)
ALL				:= 1
endif

## SOME DIRS
BIN_DIR				:= ./
SRC_DIR				:= src
OBJ_DIR				:= obj
INC_DIR				:= inc
MK_DIR				:= mk
CI_DIR				:= test
CI_BIN_DIR			:= $(CI_DIR)/bin
CI_SRC_DIR			:= $(CI_DIR)/src

INC_DIR				:= $(addprefix -I,$(INC_DIR))
CFLAGS				+= $(INC_DIR)

ifeq ($(ANSI_NO_COLOR),1)
CFLAGS				+= -DANSI_NO_COLOR
endif

ifeq ($(ANSI_NO_MODIFIER),1)
CFLAGS				+= -DANSI_NO_MODIFIER
endif
