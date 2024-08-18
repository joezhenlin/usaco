// A string cointaining only 'a's and 'b's,
// capitalization is unimportant. Change the
// string so that 'a's become 'b's and 'b's
// become 'a's.

#include <stdio.h>
#include <string.h>

#define MAXLEN 2000

int main(void) {
    FILE *fin = fopen("day001.in", "r");
    FILE *fout = fopen("day001.out", "w");

    char str[MAXLEN];
    char tmp;
    int cnt = 0;

    fscanf(fin, "%s", str);

    for (int i = 0; i < strlen(str); i++) {
        fprintf(fout, "%c", (str[i] == 'a' ? 'b' : 'a'));
    }

    fclose(fin);
    fclose(fout);

    return 0;
}