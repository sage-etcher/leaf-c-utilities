# simple makefile for windows mingw based systems. 
#
# MAKE PHONY THINGS
# "make build" takes every item in $(SRC_DIR) and compiles them into object 
# files, then links all the object files into one executable, $(TARGET_EXEC).
#
# "make install" installs the executable and other dependencies to the system
#
# "make clean" cleans out the $(BUILD_DIR) to do a fresh build


# directory variables 
SRC_DIR := ./src
BUILD_DIR := ./build
INSTALL_DIR := 


# files 
# source files 
SRC_FILENAMES := $(shell dir /a:-d /b "$(subst /,\,$(SRC_DIR)/*.c)")
SRC_FILES := $(addprefix $(SRC_DIR)/,$(SRC_FILENAMES))

# compiled object files 
OBJ_FILES := $(foreach file,$(SRC_FILES),$(BUILD_DIR)/$(file).o)

# executable name
TARGET_EXEC := test.exe


# build variables
# Compiler 
CC := gcc
# Include
INCLUDE_DIRS := -I$(SRC_DIR)
BUILD_FLAGS := -pedantic -std=c89 -O3 -Wall -Werror $(INCLUDE_DIRS)

# linker variables
# Linker 
LD := gcc 
# Libararies 
LIBRARIES :=
LINKER_FLAGS := $(INCLUDE_DIRS) $(LIBRARIES)

# Phony declarations 
# Build source into an executable
.PHONY: build
build: $(BUILD_DIR)/$(TARGET_EXEC)

# Install the program to the system
.PHONY: install
install: $(INSTALL_DIR)/$(TARGET_EXEC)

# clean build dirrectory	
.PHONY: clean
clean:
	if exist "$(BUILD_DIR)" del /s /q "$(BUILD_DIR)" & rmdir /s /q "$(BUILD_DIR)"


# actual do stuffs
# compile SRC_FILES -> OBJ_FILES
$(BUILD_DIR)/$(SRC_DIR)/%.c.o: $(SRC_DIR)/%.c
	if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) -c -o $@ $(BUILD_FLAGS) $<

# link OBJ_FILES into TARGET_EXEC
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJ_FILES)
	if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(LD) -o $@ $(LINKER_FLAGS) $(OBJ_FILES)
	