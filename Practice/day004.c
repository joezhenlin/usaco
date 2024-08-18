//编写一个程序,从4个整数中找出最小的数,并显示此数
//读取的文件中，第一行表示有多个需要计算的数，第二行开始，每一行表示具体需要计算的数，其中，数字之间用逗号分隔
//输出到文件时，每一行表示一个计算结果

#include <stdio.h>

#define MAX __INT32_MAX__

int minimum(int a, int b, int c, int d) {
    int min = MAX;

    min = a < min ? a : min;
    min = b < min ? b : min;
    min = c < min ? c : min;
    min = d < min ? d : min;

    return min;
}

int main(void) {
    FILE *fin = fopen("day004.in", "r");
    FILE *fout = fopen("day004.out", "w");

    int cases, min = MAX;

    fscanf(fin, "%d", &cases);

    for (int i = 0; i < cases; i++) {
        int a, b, c, d;
        fscanf(fin, "%d,%d,%d,%d", &a, &b, &c, &d);

        min = minimum(a, b, c, d);

        fprintf(fout, "%d\n", min);
        
        min = MAX;
    }

    fclose(fin);
    fclose(fout);

    return 0;
}