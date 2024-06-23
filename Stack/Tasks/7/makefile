CC = gcc
CFLAGS: -Wall -Wextra -g -Wno-implicit-function-declaration

CFILES = 7.c stack.c
OBJECTS = $(CFILES:.c=.o)

BINARY = final.exe

all: $(BINARY)

$(BINARY) : $(OBJECTS)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	del $(OBJECTS) $(BINARY)