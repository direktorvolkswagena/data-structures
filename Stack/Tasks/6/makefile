CC = gcc
CFLAGS: -Wall -Wextra -g -Wno-implicit-function-declaration

CFILES = 6.c stack.c
OBJECTS = $(CFILES:.c=.o)

BINARY = res.exe

all: $(BINARY)

$(BINARY) : $(OBJECTS)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	del $(BINARY) $(OBJECTS)