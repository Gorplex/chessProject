cc = gcc
CFLAGS = -c -Wall -pedantic
HEADERS = chess.h 
SRCS = chessBoard.c
EXE = chessBoard

all: chessBoard

chessBoard: $(SRCS)
	$(cc) -o chessBoard chessBoard.c `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`



