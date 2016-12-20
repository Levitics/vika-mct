# Makefile - Top level GNU Makefile
#
# To build the 
# 	make DEBUG=1|0
# Build objects will be stored under obj directory
#

#The triple has the general format <arch><sub>-<vendor>-<sys>-<abi>, where:
#
#        arch = x86, arm, thumb, mips, etc.
#        sub = for ex. on ARM: v5, v6m, v7a, v7m, etc.
#        vendor = pc, apple, nvidia, ibm, etc.
#        sys = none, linux, win32, darwin, cuda, etc.
#        abi = eabi, gnu, android, macho, elf, etc.


BUILD?=build
VERBOSE?=0
PARALLEL_JOBS?=1
CMAKE?=cmake
TOOLCHAIN_FILE=#./cmake/rpi-toolchain.cmake

all: package

$(BUILD)/Makefile:
	mkdir $(BUILD) || exit 0
	cd $(BUILD) && $(CMAKE) -DCMAKE_VERBOSE_MAKEFILE=$(VERBOSE) -DCMAKE_TOOLCHAIN_FILE=$(TOOLCHAIN_FILE) ..

build: $(BUILD)/Makefile
	cd $(BUILD) && make -j $(PARALLEL_JOBS)

install: build
	cd $(BUILD) && sudo make install

clean:
	rm -rf $(BUILD)

doc: $(BUILD)/Makefile
	cd $(BUILD) && make doc

package: $(BUILD)/Makefile
	cd $(BUILD) && make package

test: $(BUILD)/Makefile
	cd $(BUILD) && make test

cdash: $(BUILD)/Makefile
	cd $(BUILD) && make Experimental

cdash-cov: $(BUILD)/Makefile
	cd $(BUILD) && $(CMAKE) -DUSE_GCOV=True .. && make Experimental

cdash-mem: $(BUILD)/Makefile
	cd $(BUILD) && make NightlyMemoryCheck

clean: clean-release clean-debug

clean-release:
	( cd bin/release && $(MAKE) --no-print-directory clean )

clean-debug:
	( cd bin/debug && $(MAKE) --no-print-directory clean )

veryclean:
	rm -rf $(BUILDDIR)


again: clean all


rebuild: veryclean all


release: rebuild

.PHONY: build install clean doc package test cdash cdash-cov cdash-mem

.PHONY:	all generate install rclean clean

default: generate
	
ifndef	OPSYS
OPSYS		:= $(shell uname - 2>/dev/null)
ARCH		:= $(shell uname -m 2>/dev/null)
SUB		:= $(shell uname -n 2>/dev/null)
VENDOR		:= $(shell uname -m 2>/dev/null)
SYS		:= $(shell uname -s 2>/dev/null)
ABI		:= $(shell uname -o 2>/dev/null)
endif

BUILD_MAKE		= $(MAKE)

ifeq ($(OPSYS),Msys)
    CMAKE_GENERATOR			:= "MSYS Makefiles"
else
    ifeq ($(OPSYS),MinGW)
	CMAKE_GENERATOR			:= "MinGW Makefiles"
    else
	ifeq ($(OPSYS),Windows-MSVC)
	    CMAKE_GENERATOR		:= "NMake Makefiles"
	    BUILD_MAKE			:= nmake
	    BUILD_MAKEFLAGS		=
	    override MAKEFLAGS		=
	else
	    CMAKE_GENERATOR		:= "Unix Makefiles"
	endif
    endif
endif

ifeq ("$(CONF)","Release")
    CMAKE_BUILD_TYPE	= Release
else
    ifeq ("$(CONF)","Debug")
	CMAKE_BUILD_TYPE	= Debug
    else
	CMAKE_BUILD_TYPE	= Release
    endif
endif
BUILD_TYPE              := $(shell echo $(CMAKE_BUILD_TYPE) | tr '[A-Z]' '[a-z]')
CMAKE_ARGS		=  -DALLOW_COMPILER_WARNINGS=$(ALLOW_COMPILE_WARNINGS) -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE)

BUILD_DIR		= $(ARCH)-$(SUB)-$(VENDOR)-$(SYS)-$(ABI)-$(BUILD_TYPE)

all:
	
generate:
	@echo "$(BUILD_DIR)"
	
$(BUILD_DIR)/Makefile: Makefile
	@mkdir -p $(BUILD_DIR)
	(cd $(BUILD_DIR) && cmake -G $(CMAKE_GENERATOR) $(CMAKE_ARGS) $(CURDIR))
rclean clean: 
	rm -rf $(BUILD_DIR)	