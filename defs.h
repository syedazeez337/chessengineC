#ifndef DEFS_H
#define DEFS_H

typedef unsigned long long U64;

#define NAME "vice 1.0"
#define BRD_SQ_NUM 120

#define MAXGAMEMOVES 2048

enum {
    EMPTY,
    wP,
    wN,
    wB,
    wR,
    wQ,
    wK,
    bP,
    bN,
    bB,
    bR,
    bQ,
    bK,
};

enum {
    FILE_A,
    FILE_B,
    FILE_C,
    FILE_D,
    FILE_E,
    FILE_F,
    FILE_G,
    FILE_H,
    FILE_NONE,
};

enum {
    RANK_1,
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_NONE,
};

enum {
    WHITE,
    BLACK,
    BOTH,
};

enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ,
};

enum {
    FALSE,
    TRUE,
};

typedef struct {

    int move;
    int castlePerm;
    int enPas;
    int fiftyMove;
    U64 posKey;

} S_UNDO;

typedef struct {
    int pieces[BRD_SQ_NUM];
    U64 pawns[3];

    int KingSq[2];

    int side;
    int enPas;
    int fiftyMove;

    int ply;
    int hisPly;

    int castlePerm;

    U64 posKey;

    int pceNum[13];
    int bigPce[3];
    int majPce[3];
    int minPce[3];

    S_UNDO history[MAXGAMEMOVES];

} S_BOARD;

enum {
    WKCA = 1,
    WQCA = 2,
    BKCA = 4,
    BQCA = 8,
};

#endif


/*
Explanation : These represent the white pieces :
wP: White Pawn
wN: White Knight
wB: White Bishop
wR: White Rook
wQ: White Queen
wK: White King
Each of these constants is assigned an integer value starting from 1 (since EMPTY is 0). So:
wP = 1
wN = 2
wB = 3
wR = 4
wQ = 5
wK = 6

Explanation : These represent the black pieces :
bP: Black Pawn
bN: Black Knight
bB: Black Bishop
bR: Black Rook
bQ: Black Queen
bK: Black King
These constants continue from where the white pieces left off. Since wK was 6, the black pieces start at 7:
bP = 7
bN = 8
bB = 9
bR = 10
bQ = 11
bK = 12
Why it's written like this : Similar to the white pieces, these constants allow you to uniquely identify black pieces on the board. The separation between white and black pieces (using different ranges of integers) makes it easy to distinguish between them in your code
*/