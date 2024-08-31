/*
ID: ericjoe1
LANG: C
TASK: namenum
*/

#include <stdio.h>
#include <string.h>

int tmp, cnt = 0, digits;
char num[12], name[12], ans[81][12];
int dictMap[91];

int confirm(char *num, char *name) {
    int digits = strlen(num), nameLen = strlen(name);
    if (digits != nameLen) {return 0;}

    for (int i = 0; i < digits; i++) {
        printf("%s: NAME[%d] IS %d IN IF STATEMENT\n", name, i, dictMap[name[i]]);
        if (dictMap[name[i]] != (int)(num[i] - '0')) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    FILE *fin = fopen("namenum.in", "r");
    FILE *fout = fopen("namenum.out", "w");
    FILE *dict = fopen("dict.txt", "r");

    tmp = 3;
    for (int i = 2; i < 10; i++) {
        for (int j = tmp - 3; j < tmp; j++) {
            dictMap['A' + (3 * (i - 2)) + j] = i;
            if (j == 0 && i == 7) {
                tmp++;
                j++;
            }
        }
    }

    fscanf(fin, "%s", num);
    printf("INDEX: %s\n", num);
    digits = strlen(num);

    while (1) {
        if (feof(dict)) {break;}

        fscanf(dict, "%s", name);
        fgetc(dict);

        if (strlen(name) == strlen(num)) {
            tmp = confirm(num, name);
            if (tmp == 1) {
                for (int i = 0; i < strlen(name); i++) {
                    ans[cnt][i] = name[i];
                }
                cnt++;
            }
        }
    }

    if (cnt == 0) {
        fprintf(fout, "NONE\n");
    } else {
        for (int i = 0; i < cnt; i++) {
            fprintf(fout, "%s\n", ans[i]);
        }
    }

    fclose(fin);
    fclose(dict);
    fclose(fout);
    
    return 0;
}