CC = gcc -std=c99
CFLAGS=-Wall -g

ChessServer: message main
	$(CC) -o ChessServer message.o Server.o

message: message.c message.h
	$(CC) $(CFLAGS) -c message.c

main: Server.c
	$(CC) $(CFLAGS) -c Server.c

clean:
	rm -f *.o ChessServer


