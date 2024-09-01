// Practice 1-23

// Question: Write a code which deletes all comments
// 题目：写一个删除程序中所有注释的程序

#include <stdio.h>
#include <string.h>

#define MAXLEN 100

int isWhiteSpace(char c) {
    if (c == ' ' || c == '\t' || c == '\n') {
        return 1;
    } else {return 0;}
}

int main(void) {
    FILE *fin = fopen("day009.in", "r");
    FILE *fout = fopen("day009.out", "w");

    char line[MAXLEN];
    int comment = 0, noNewLine = 0;

    while (1) {
        fgets(line, MAXLEN, fin);

        for (int i = 0; i < strlen(line) - 1; i++) {
            if (comment == 0 && line[i] == '/') {
                comment = 1;
            } else if (comment == 1 && line[i] != '/' && line[i] != '*') {
                fprintf(fout, "/%c", line[i]);
                comment = 0;
            } else if (comment == 1 && line[i] == '/') {
                comment = 2; noNewLine = -1; break;
            } else if (comment == 1 && line[i] == '*') {
                comment = 3;
            } else if (comment == 3 && line[i] == '*') {
                comment = 4;
            } else if (comment == 4 && line[i] == '/') {
                comment = 5;
            } else if (comment != 3 && comment != 4) {
                fputc(line[i], fout);
            }
        }

        if (comment == 2 || comment == 5) {
            noNewLine = noNewLine == -1 ? 0 : 1;
            comment = 0;
        } else if (comment == 3) {
            noNewLine = 1;
            continue;
        }

        if (feof(fin)) {
            fputc(line[strlen(line) - 1], fout);
            break;
        } else if (noNewLine != 1) {
            fputc('\n', fout);
        } else if (noNewLine == 1 && comment != 3) {
            noNewLine = 0;
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}

// Hehe IT WORKS! Wiped all comments off of the face of the Earth :DDDDD
// 成功！把所有注释从地球表面抹除了（顺便还在曾经有注释的地方留下个换行符纪念一下）