CC=gcc
CFLAGS=-Wall -Wextra -Iprimitive_gates/nand -Iprimitive_gates/not -Iprimitive_gates/and -Iprimitive_gates/or -Iprimitive_gates/xor -Iprimitive_gates/mux

SRC=main.c primitive_gates/nand/nand.c primitive_gates/not/not.c primitive_gates/and/and.c primitive_gates/or/or.c primitive_gates/xor/xor.c primitive_gates/mux/mux.c
OBJ=$(SRC:.c=.o)

main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f main $(OBJ)