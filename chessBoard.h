#ifndef CHESS_H
#define CHESS_H

enum piece{NONE=0, WPAWN=1, WROOK=2, WKNIGHT=3, WBISHOP=4, WQUEEN=5, WKING=6, BPAWN=-1, BROOK=-2, BKNIGHT=-3, BBISHOP=-4, BQUEEN=5, BKING=-6};

typedef struct Point Point;
struct Point{
    int x;
    int y;
}

typedef struct MoveState MoveState;
struct MoveState{
    Point 
    enum piece[8][8];
}



#endif
