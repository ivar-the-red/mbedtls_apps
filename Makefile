# Compiler and flags for the program
CC = gcc
CFLAGS = -Wall -Werror -g -I../mbedtls/include

# Directory
SRCDIR = .

# Source file for the program
SRC = $(wildcard $(SRCDIR)/*.c)

# Target program
PROGRAM = test_program

all: $(PROGRAM)

$(PROGRAM): $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC) -L../mbedtls/library -lmbedtls -lmbedcrypto -lmbedx509

clean:
	rm -f $(PROGRAM)

.PHONY: all clean