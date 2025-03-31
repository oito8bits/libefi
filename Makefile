CC=x86_64-w64-mingw32-gcc
AR=x86_64-w64-mingw32-ar
LIB_NAME=libefi.a
OBJS=stdio.o init.o string.o stdlib.o

$(LIB_NAME): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) -O2 -ffreestanding -Iinclude/ -c -o $@ $<

.PHONY: clean

clean:
	rm -rf *.o $(LIB_NAME)
