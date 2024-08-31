// Practice 1-22

#include <stdio.h>

#define MAXLINELEN 50
#define TABINC 8

int isWhiteSpace (char c) {
    if (c == ' ' || c == '\t' || c == '\n') {
        return 1;
    } else {
        return 0;
    }
}

int findWhiteSpace (char line[MAXLINELEN]) {
    int pos = MAXLINELEN - 1;

    for (; pos >= 0; pos--) {
        if (!isWhiteSpace(line[pos])) {
            return pos;
        }
    }

    return 0;
}

int main(void) {
    FILE *fin = fopen("day008.in", "r");
    FILE *fout = fopen("day008.out", "w");

    int listPos = 0, linePos = 0, lastChar;
    char tmp, line[MAXLINELEN];

    while (1) {
        if (feof(fin)) {
            break;
        }

        tmp = fgetc(fin);

        if (linePos < MAXLINELEN) {
            if (tmp == '\n') {
                continue;
            } else if (tmp == '\t') {
                line[listPos++] = tmp;
                linePos += TABINC;
            } else {
                line[listPos++] = tmp;
                linePos++;
            }
        } else {
            lastChar = tmp == '\n' ? findWhiteSpace(line) : MAXLINELEN - 1;

            for (int i = 0; i <= lastChar; i++) {
                fputc(line[i], fout);
            }
            fputc('\n', fout);
            if (tmp != '\n') {fputc(tmp, fout);}

            listPos = 0;
            linePos = 0;
        }
    }

    line[listPos] = isWhiteSpace(tmp) ? ' ' : tmp;
    
    lastChar = tmp == '\n' ? findWhiteSpace(line) : listPos - 1;

    for (int i = 0; i < lastChar; i++) {
        fputc(line[i], fout);
    }

    fclose(fin);
    fclose(fout);
    
    return 0;

    //整个代码应该已经处理好所有情况了：D
}