// Practice 1-21

#include <stdio.h>

#define TABINC 8

int main(void) {
    FILE *fin = fopen("day007.in", "r");
    FILE *fout = fopen("day007.out", "w");

    char c;
    int pos = 0;

    while (1) {
        c = fgetc(fin);

        if (feof(fin)) {
            break;
        }

        if (c == ' ') {
            int initialPos = pos;

            while (c == ' ') {
                pos++;

                c = fgetc(fin);

                if (feof(fin)) {
                    break;
                }
            }

            for (int i = pos ; i - initialPos > 0; i -= 4) {
                fputc(i % TABINC == 1 ? ' ' : '\t', fout);
            }
            fputc(c, fout);
        } else {
            fputc(c, fout);
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}