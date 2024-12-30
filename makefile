# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra

# Directory structure
GATES_DIR = gates
CHIPS_DIR = chips
	COMB_DIR = $(CHIPS_DIR)/combinatorial
	SEQ_DIR = $(CHIPS_DIR)/sequential
TYPES_DIR = types

# Include paths for header files
INCLUDES = -I$(GATES_DIR)/nand \
          -I$(GATES_DIR)/not \
          -I$(GATES_DIR)/and \
          -I$(GATES_DIR)/or \
          -I$(GATES_DIR)/xor \
					\
          -I$(COMB_DIR)/mux \
          -I$(COMB_DIR)/dmux \
					-I$(COMB_DIR)/not16 \
          -I$(COMB_DIR)/and16 \
					-I$(COMB_DIR)/or16 \
					-I$(COMB_DIR)/mux16 \
					-I$(COMB_DIR)/or-8-way \
					-I$(COMB_DIR)/mux16-4-way \
					-I$(COMB_DIR)/mux16-8-way \
					-I$(COMB_DIR)/dmux-4-way \
					\
					-I$(TYPES_DIR) \


# Source files
GATES_SRC = $(wildcard $(GATES_DIR)/*//*.c)
COMB_SRC = $(wildcard $(COMB_DIR)/*//*.c)
SEQ_SRC = $(wildcard $(SEQ_DIR)/*//*.c)
MAIN_SRC = main.c

# All source files
SRC = $(MAIN_SRC) $(GATES_SRC) $(COMB_SRC) $(SEQ_SRC)

# Object files
OBJ = $(SRC:.c=.o)

# Main target
TARGET = main

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

# Compilation
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean
clean:
	rm -f $(TARGET) $(OBJ)

# Clean and rebuild
rebuild: clean all

# Phony targets
.PHONY: all clean rebuild