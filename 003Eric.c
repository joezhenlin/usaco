/*
ID: ericjoe1
LANG: C
TASK: milk2
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 5001

typedef struct Milk{
    int start;
    int end;
} Milk;

Milk milking[MAX];

int milkCmp(const void *va, const void *vb) {
    Milk *a, *b;

    a = (Milk*)va;
    b = (Milk*)vb;

    if (a->start > b->start) {
        return 1;
    } else if (a->start < b->start) {
        return -1;
    } else {
        return 0;
    }
}

int main(void) {
    FILE *fin = fopen("milk2.in", "r");
    FILE *fout = fopen("milk2.out", "w");
    if (fin == NULL || fout == NULL) {
        return -1;
    }

    int n;

    fscanf(fin, "%d", &n);

    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d %d", &milking[i].start, &milking[i].end);
    }
    qsort(milking, n, sizeof(Milk), milkCmp);

    Milk curr;
    int maxMilk = 0, maxNoMilk = 0;

    curr = milking[0];
    
    for (int i = 1; i < n; i++) {
        if (milking[i].start > curr.end) {
            maxNoMilk = milking[i].start - curr.end > maxNoMilk ? milking[i].start - curr.end : maxNoMilk;
            maxMilk = curr.end - curr.start > maxMilk ? curr.end - curr.start : maxMilk;

            curr = milking[i];
        } else {
            if (milking[i].end > curr.end) {
                curr.end = milking[i].end;
            }
        }
    }
    maxMilk = curr.end - curr.start > maxMilk ? curr.end - curr.start : maxMilk;

    fprintf(fout, "%d %d\n", maxMilk, maxNoMilk);

    fclose(fin);
    fclose(fout);

    return 0;
}