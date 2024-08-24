#include <stdio.h>
#include <string.h>

int n = 10;
char before[10][10], after[10][10], temp[10][10];

void rotate() {
    int r, c;
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            after[c][n - 1 - r] = temp[r][c];
        }
    }
}

void reflect() {
    int r, c;
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            after[r][n - 1 - c] = temp[r][c];
        }
    }
}

int eqboard() {
    int r, c;
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            if (before[r][c] != after[r][c]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    FILE *fout = fopen("transform.out", "w");
    FILE *fin = fopen("transform.in", "r");
    int r, c, change = 7;

    fscanf(fin, "%d", &n);

    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            fscanf(fin, " %c", &before[r][c]);
        }
    }

    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            fscanf(fin, " %c", &after[r][c]);
        }
    }

    // Copy the before board to temp
    memcpy(temp, before, sizeof(before));

    // Check rotations
    for (int i = 1; i <= 3; i++) {
        rotate();
        if (eqboard()) {
            change = i;
            break;
        }
    }

    // 重置
    memcpy(temp, before, sizeof(before));
    reflect();
    for (int i = 0; i <= 3; i++) {
        if (eqboard()) {
            change = 4 + (i > 0);
            break;
        }
        rotate();
    }

    // 检查一下
    memcpy(temp, before, sizeof(before));
    if (eqboard()) {
        change = 6;
    }

    fprintf(fout, "%d\n", change);

    //跟你学会关上文件了
    fclose(fin);
    fclose(fout);
    
    return 0;
}
