cc = gcc
CFLAGS = -c -Wall -pedantic
HEADERS = chessBoard.h 
SRCS = chessBoard.c
EXE = chessBoard

all: chessBoard

chessBoard: $(SRCS)
	$(cc) -o chessBoard chessBoard.c `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
clean:
	rm -f *.o $(EXE)


