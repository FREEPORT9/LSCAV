# Compiler Settings
CC = gcc

# Directory Locations
SRC_DIR      = ../src
OBJ_DIR      = ../obj
BIN_DIR      = ../bin
INCLUDE_DIR  = ../include

# Source and Object File Definitions
SOURCE_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJECT_FILES = $(SOURCE_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler Flags
CFLAGS_BASE = -std=c99 -Wall -Wextra -Wpedantic -Werror \
              -I$(INCLUDE_DIR)

# Debug Build Flags (includes sanitizers and debugging options)
CFLAGS_DEBUG = $(CFLAGS_BASE) -g -O0 -fno-inline -fno-omit-frame-pointer \
               -fwrapv -fdiagnostics-show-option -fsanitize=undefined,leak,address

# Production Build Flags (optimized for performance and security)
CFLAGS_PROD  = $(CFLAGS_BASE) -O3 -fstack-protector-strong -D_FORTIFY_SOURCE=3 \
               -fPIE -pie -fvisibility=hidden -fno-common -fstack-clash-protection \
               -march=native -mtune=native -flto -fno-strict-aliasing \
               -funroll-loops -finline-functions -fno-plt

# Linker Flags
LDFLAGS_PROD = -flto -Wl,-z,relro -Wl,-z,now -Wl,-z,defs -Wl,-z,noexecstack

# Default Target: Builds the 'lscav' executable
all: $(BIN_DIR)/lscav

# Compile .c files into .o object files (using base flags)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS_BASE) -c $< -o $@

# Link Object Files into the Debug Executable
debug: $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) $(CFLAGS_DEBUG) -o $(BIN_DIR)/lscav_debug

# Link Object Files into the Production Executable
release: $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) $(CFLAGS_PROD) $(LDFLAGS_PROD) -o $(BIN_DIR)/lscav_release

# Default Build: Link the Object Files with Base Flags
$(BIN_DIR)/lscav: $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) $(CFLAGS_BASE) -o $(BIN_DIR)/lscav_standard

# Clean Build Artifacts
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/*

# Phony Targets (Avoid conflicts with filenames)
.PHONY: all clean debug release
