//读取文件中的数据，求出最大公约数和最小公倍数
//读取的文件中，第一行表示有多少组需要计算的数据，第二行开始，每一行表示需要计算计算的具体的数
//输出到文件中时，每一行表示一个计算结果，其中第一个数时最大公约数，第二个数是最小公倍数，两个数之间用逗号分隔

#include <stdio.h>

int gcf(int a, int b) {
    int tmpFactor = 1, ans = -1;

    while (tmpFactor <= a && tmpFactor <= b) {
        if (a % tmpFactor == 0 && b % tmpFactor == 0) {
            ans = tmpFactor;
        }
        
        tmpFactor++;
    }

    return ans;
}

//这个方法怎么样？
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b; //参见数论中的欧几里得辗转相除法
        a = temp;
    }

    return a;
}

int lcm(int a, int b) {
    int gcFactor = gcf(a, b);

    return a * b / gcFactor;
}

int main(void) {
    FILE *fin = fopen("day005.in", "r");
    FILE *fout = fopen("day005.out", "w");

    int cases;

    fscanf(fin, "%d", &cases);

    for (int i = 0; i < cases; i++) {
        int a, b;
        
        fscanf(fin, "%d,%d", &a, &b);

        fprintf(fout, "%d,%d\n", gcd(a, b), lcm(a, b));
    }

    fclose(fin);
    fclose(fout);

    return 0;
}