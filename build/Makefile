# Compiler settings
CC = gcc

# Directories
SRC_DIR      = ../src
OBJ_DIR      = ../obj
BIN_DIR      = ../bin
INCLUDE_DIR  = ../include

# Source and Object files
SRC_FILES    = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES    = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Common compiler flags for both debug and production
CFLAGS_COMMON = -std=c99 -Wall -Wextra -Wpedantic -Werror \
                -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700 \
                -I$(INCLUDE_DIR)

# Debug flags (including UBSan and other debugging tools)
CFLAGS_DEBUG = $(CFLAGS_COMMON) -g -O0 -fno-inline -fno-omit-frame-pointer \
               -fwrapv -fdiagnostics-show-option -fsanitize=undefined,leak,address

# Production flags (optimized for speed, security, and no debug info)
CFLAGS_PROD  = $(CFLAGS_COMMON) -O3 -fstack-protector-strong -D_FORTIFY_SOURCE=3 \
               -fPIE -pie -fvisibility=hidden -fno-common -fstack-clash-protection \
               -march=native -mtune=native -flto -fno-strict-aliasing \
               -funroll-loops -finline-functions -fno-plt

# Linker flags
LDFLAGS_DEBUG =
LDFLAGS_PROD  = -flto -Wl,-z,relro -Wl,-z,now -Wl,-z,defs -Wl,-z,noexecstack

# Default target (debug build)
all: $(BIN_DIR)/lscav_debug

# General rule to compile .c files into .o files (with variable flags)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Debug build rule: link object files into the final binary
$(BIN_DIR)/lscav_debug: $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(CFLAGS_DEBUG) $(LDFLAGS_DEBUG) -o $(BIN_DIR)/lscav_debug

# Production build rule: link object files into the final binary
prod: $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(CFLAGS_PROD) $(LDFLAGS_PROD) -o $(BIN_DIR)/lscav_prod

# Clean target: remove object files and binaries
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/*

# Phony targets (to avoid conflicts with file names)
.PHONY: all clean prod
