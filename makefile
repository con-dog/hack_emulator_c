# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra

# Directory structure
COMPONENTS_DIR = components
COMB_DIR = $(COMPONENTS_DIR)/combinatorial
SEQ_DIR = $(COMPONENTS_DIR)/sequential
TYPES_DIR = types
UTILS_DIR = utils

# Logic gates directories
LOGIC_BIT_DIR = $(COMB_DIR)/logic-gates/bit
LOGIC_MULTI_DIR = $(COMB_DIR)/logic-gates/multi-bit
MUX_BIT_DIR = $(COMB_DIR)/multiplexers/bit
MUX_MULTI_DIR = $(COMB_DIR)/multiplexers/multi-bit
ARITH_DIR = $(COMB_DIR)/arithmetic

# Include paths
INCLUDES = \
					-I$(LOGIC_BIT_DIR)/nand \
          -I$(LOGIC_BIT_DIR)/not \
          -I$(LOGIC_BIT_DIR)/and \
          -I$(LOGIC_BIT_DIR)/or \
          -I$(LOGIC_BIT_DIR)/xor \
					\
          -I$(LOGIC_MULTI_DIR)/not16 \
          -I$(LOGIC_MULTI_DIR)/and16 \
          -I$(LOGIC_MULTI_DIR)/or16 \
          -I$(LOGIC_MULTI_DIR)/or-8way \
					\
          -I$(MUX_BIT_DIR)/mux \
          -I$(MUX_BIT_DIR)/dmux \
					\
          -I$(MUX_MULTI_DIR)/mux16 \
          -I$(MUX_MULTI_DIR)/mux16-4way \
          -I$(MUX_MULTI_DIR)/mux16-8way \
          -I$(MUX_MULTI_DIR)/dmux-4way \
          -I$(MUX_MULTI_DIR)/dmux-8way \
					\
          -I$(ARITH_DIR)/half-adder \
          -I$(ARITH_DIR)/full-adder \
          -I$(ARITH_DIR)/add16 \
          -I$(ARITH_DIR)/inc16 \
          -I$(ARITH_DIR)/alu \
					\
          -I$(TYPES_DIR) \
					\
          -I$(UTILS_DIR)


# Source files
LOGIC_BIT_SRC = $(wildcard $(LOGIC_BIT_DIR)/*/*.c)
LOGIC_MULTI_SRC = $(wildcard $(LOGIC_MULTI_DIR)/*/*.c)
MUX_BIT_SRC = $(wildcard $(MUX_BIT_DIR)/*/*.c)
MUX_MULTI_SRC = $(wildcard $(MUX_MULTI_DIR)/*/*.c)
ARITH_SRC = $(wildcard $(ARITH_DIR)/*/*.c)
SEQ_SRC = $(wildcard $(SEQ_DIR)/*/*.c)
UTILS_SRC = $(wildcard $(UTILS_DIR)/*.c)
MAIN_SRC = main.c
TEST_SRC = test.c

# All source files
SRC = $(MAIN_SRC) $(UTILS_SRC) $(LOGIC_BIT_SRC) $(LOGIC_MULTI_SRC) $(MUX_BIT_SRC) $(MUX_MULTI_SRC) $(ARITH_SRC) $(SEQ_SRC)

# Object files
OBJ = $(SRC:.c=.o)

# Test object files (similar to OBJ but with tests.c instead of main.c)
TEST_OBJ = $(filter-out main.o, $(OBJ)) $(TEST_SRC:.c=.o)

# Main target
TARGET = main
TEST_TARGET = test

# Targets
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ)
	$(CC) $(TEST_OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJ) $(TEST_SRC:.c=.o)

rebuild: clean all

.PHONY: all clean rebuild test