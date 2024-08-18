//读取2个整数(中间用逗号分隔)，求两数的平方和并输出到文件

#include <stdio.h>

int main(void) {
    FILE *fin = fopen("day002.in", "r");
    FILE *fout = fopen("day002.out", "w");

    int a, b;
    
    fscanf(fin, "%d,%d", &a, &b);

    fprintf(fout, "%d", (a * a) + (b * b));

    fclose(fin);
    fclose(fout);

    return 0;
}