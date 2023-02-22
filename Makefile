CC = c++
CFLAGS = -Wall -Wextra -Werror

all: main

main: main.cpp aes.o
	$(CC) $(CFLAGS) main.cpp aes.o -o main

aes.o: aes.cpp aes.h
	$(CC) $(CFLAGS) -c aes.cpp -o aes.o

clean:
	rm -f *.o main
