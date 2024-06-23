CC = gcc
CFLAGS: -Wall -Wextra -Wno-implicit-function-declaration -g

CFILES = 13.c stack.c 
OBJECTS = $(CFILES:.c=.o)

BINARY = final.exe

all: $(BINARY)

$(BINARY) : $(OBJECTS)
	$(CC) -o $@ $^

%.o : %.c 
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	del $(BINARY) $(OBJECTS)