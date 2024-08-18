//从文件中读取一个圆半径（r），当r>＝0时，计算并输出圆的面积和周长，否则，输出提示信息
//读取文件中，第一行表示一共多少个半径值，第二行开始，每一行表示具体的半径数值
//输出到文件中，用每一行表示一个计算结果

#include <stdio.h>

#define PI 3.141592653589793

int main(void) {
    FILE *fin = fopen("day003.in", "r");
    FILE *fout = fopen("day003.out", "w");

    int cases, r;

    fscanf(fin, "%d", &cases);

    for (int i = 0; i < cases; i++) {
        fscanf(fin, "%d", &r);
       
        if (r >= 0) {
            fprintf(fout, "%.3f\n", (float)r * (float)r * PI);
        } else {
            fprintf(fout, "THE RADIUS OF A CIRCLE CANNOT BE SMALLER THAN 0 (r ≮ 0)\n");
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}