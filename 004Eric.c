/*
ID: ericjoe1
LANG: C
TASK: transform
*/

#include <stdio.h>

#define MAXSIZE 10

typedef struct Board {
    int size;
    char board[MAXSIZE][MAXSIZE];
} Board;

Board rotate90(Board initial);
// #define rotate180(initial) (rotate90(rotate90(initial)));
// #define rotate270(initial) (rotate90(rotate180(initial)));
// #define reflV_rotate90(initial) (rotate90(reflectV(initial)));
// #define reflV_rotate180(initial) (rotate180(reflectV(initial)));
// #define reflV_rotate270(initial) (rotate270(reflectV(initial)));

// for some reason the #define method doesn't work? Maybe it's my problem - Eric

Board rotate90(Board initial) {
    Board after;
    after.size = initial.size;

    for (int a = 0; a < after.size; a++) {
        for (int b = 0; b < after.size; b++) {
            after.board[b][after.size - a - 1] = initial.board[a][b];
        }
    }

    return after;
}

Board reflectV(Board initial) {
    Board after;
    after.size = initial.size;
    
    for (int a = 0; a < after.size; a++) {
        for (int b = 0; b < after.size; b++) {
            after.board[a][after.size - b - 1] = initial.board[a][b];
        }
    }

    return after;
}

int eqboard(Board input1, Board input2) {
    int size = input1.size;

    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; b++) {
            if (input1.board[a][b] != input2.board[a][b]) {
                return 0;
            }
        }
    }

    return 1;
}

int main(void) {
    FILE *fin = fopen("transform.in", "r");
    FILE *fout = fopen("transform.out", "w");

    Board b, target;
    fscanf(fin, "%d", &b.size);
    target.size = b.size;

    fgetc(fin);

    for (int i = 0; i < b.size; i++) {
        for (int j = 0; j < b.size; j++) {
            fscanf(fin, "%c", &b.board[i][j]);
        } fgetc(fin);
    }

    for (int i = 0; i < target.size; i++) {
        for (int j = 0; j < target.size; j++) {
            fscanf(fin, "%c", &target.board[i][j]);
        } fgetc(fin);
    }

    // Board tmp;
    // tmp = rotate90(b);

    // for (int i = 0; i < tmp.size; i++) {
    //     for (int j = 0; j < tmp.size; j++) {
    //         putchar(tmp.board[i][j]);
    //         printf("\tHI\t");
    //     } putchar('\n');
    // }

    if (eqboard(rotate90(b), target)) {
        fprintf(fout, "1\n");
    } else if (eqboard(rotate90(rotate90(b)), target)) {
        fprintf(fout, "2\n");
    } else if (eqboard(rotate90(rotate90(rotate90(b))), target)) {
        fprintf(fout, "3\n");
    } else if (eqboard(reflectV(b), target)) {
        fprintf(fout, "4\n");
    } else if (eqboard(rotate90(reflectV(b)), target)
                || eqboard(rotate90(rotate90(reflectV(b))), target)
                || eqboard(rotate90(rotate90(rotate90(reflectV(b)))), target)) {
        fprintf(fout, "5\n");
    } else if (eqboard(b, target)) {
        fprintf(fout, "6\n");
    } else {
        fprintf(fout, "7\n");
    }

    fclose(fin);
    fclose(fout);
    
    return 0;
}

// int main(void) {
//     FILE *fin = fopen("transform.in", "r");

//     Board a;
//     a.size = 1; fgetc(fin); fgetc(fin);
//     fscanf(fin, "%c", &a.board[0][0]);
//     printf("%c", a.board[0][0]);

//     return 0;
// }