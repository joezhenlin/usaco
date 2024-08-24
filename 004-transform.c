#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 最大矩阵尺寸
#define MAX_SIZE 10

// 函数声明（原型）
void rotate(char start[MAX_SIZE][MAX_SIZE], char result[MAX_SIZE][MAX_SIZE], int size, int degrees);
void reflectHorz(char start[MAX_SIZE][MAX_SIZE], char result[MAX_SIZE][MAX_SIZE], int size);
void reflectVert(char start[MAX_SIZE][MAX_SIZE], char result[MAX_SIZE][MAX_SIZE], int size);
int isEqual(char start[MAX_SIZE][MAX_SIZE], char end[MAX_SIZE][MAX_SIZE], int size);
int change(char start[MAX_SIZE][MAX_SIZE], char end[MAX_SIZE][MAX_SIZE], int size);

// 旋转矩阵函数
void rotate(char start[MAX_SIZE][MAX_SIZE], char result[MAX_SIZE][MAX_SIZE], int size, int degrees) {
    int i, j;
    if (degrees == 180) {
        // 如果旋转180度，等价于水平和垂直翻转
        char temp[MAX_SIZE][MAX_SIZE];
        reflectVert(start, temp, size);
        reflectHorz(temp, result, size);
    } else if (degrees == 90) {
        // 旋转90度
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                result[i][j] = start[size - 1 - j][i];
            }
        }
    } else if (degrees == 270) {
        // 旋转270度
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                result[i][j] = start[j][size - 1 - i];
            }
        }
    }
}

// 水平反射
void reflectHorz(char start[MAX_SIZE][MAX_SIZE], char result[MAX_SIZE][MAX_SIZE], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            result[i][j] = start[i][size - j - 1];
        }
    }
}

// 垂直反射
void reflectVert(char start[MAX_SIZE][MAX_SIZE], char result[MAX_SIZE][MAX_SIZE], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            result[i][j] = start[size - i - 1][j];
        }
    }
}

// 比较两个矩阵是否相等
int isEqual(char start[MAX_SIZE][MAX_SIZE], char end[MAX_SIZE][MAX_SIZE], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (start[i][j] != end[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

// 判断变换类型
int change(char start[MAX_SIZE][MAX_SIZE], char end[MAX_SIZE][MAX_SIZE], int size) {
    char temp[MAX_SIZE][MAX_SIZE];

    rotate(start, temp, size, 90);
    if (isEqual(temp, end, size)) {
        return 1;
    }

    rotate(start, temp, size, 180);
    if (isEqual(temp, end, size)) {
        return 2;
    }

    rotate(start, temp, size, 270);
    if (isEqual(temp, end, size)) {
        return 3;
    }

    reflectHorz(start, temp, size);
    if (isEqual(temp, end, size)) {
        return 4;
    }

    char reflected[MAX_SIZE][MAX_SIZE];
    reflectHorz(start, reflected, size);

    rotate(reflected, temp, size, 90);
    if (isEqual(temp, end, size)) {
        return 5;
    }

    rotate(reflected, temp, size, 180);
    if (isEqual(temp, end, size)) {
        return 5;
    }

    rotate(reflected, temp, size, 270);
    if (isEqual(temp, end, size)) {
        return 5;
    }

    if (isEqual(start, end, size)) {
        return 6;
    }

    return 7;
}

// 主函数
int main() {
    FILE *fin = fopen("transform.in", "r");
    FILE *fout = fopen("transform.out", "w");

    if (fin == NULL || fout == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (!feof(fin)) {
        int size;
        fscanf(fin, "%d", &size);

        char start[MAX_SIZE][MAX_SIZE];
        char end[MAX_SIZE][MAX_SIZE];

        // 读取初始矩阵
        for (int i = 0; i < size; i++) {
            fscanf(fin, "%s", start[i]);
        }

        // 读取目标矩阵
        for (int i = 0; i < size; i++) {
            fscanf(fin, "%s", end[i]);
        }

        // 计算变换类型
        int result = change(start, end, size);
        fprintf(fout, "%d\n", result);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
