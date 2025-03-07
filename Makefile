#Compiler settings
CC = gcc

#Stricter compiler flags
CFLAGS = -Wall -Wextra -Werror -pedantic -g

#Directories
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
INC_DIR = ./include

#Source files and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Output executable
TARGET = $(BIN_DIR)/lscav

# Include directories
INCLUDES = -I$(INC_DIR)

# Default target: Build the program (compile and link)
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET)

# Compile the source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Target to compile the executable directly without object files (no objects created)
noobjs:
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_FILES) -o $(TARGET)

# Target to compile object files without linking them (useful for separate compilation)
compile: $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up generated files (object files and executable)
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Phony targets (targets that don't correspond to files)
.PHONY: all clean compile noobjs
