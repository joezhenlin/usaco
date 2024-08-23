// Practice 1-20
// I am a bit confused for now.

#include <stdio.h>
#include <string.h>

#define MAXLEN 2000
#define TABSIZE 8

int main(void) {
    FILE *fin = fopen("day006.in", "r");
    FILE *fout = fopen("day006.out", "w");
    if (fin == NULL || fout == NULL) {return -1;}

    char c;
    int pos = 0;

    /*
    To Dad:
    
    I've looked at the answer before I wrote this, just as
    a little disclaimer. I understand how he takes input by
    getchar - in fact, I use it often. However, in files, I
    did not see a way to take only one character. I tried
    fscanf(fin, "%c", c) and it didn't work. I looked it up
    and didn't find any good ways. So, in the input, I may
    need to know the number of lines in the file so I could
    use fgets, which terminates on newlines AND end-of-files.

    我写程序之前看过解答，我是完全理解后自己照记忆写的。我懂了他用的
    getchar()，我也经常用，但是在文件里我没找到fgetchar()之类的
    函数。我试了fscanf(fin, "%c", c)，不管用。我倒是找到了一
    个叫fgets()的东西，但是它既在EOF停也在\n停，所以我就需要输入
    时得到一共有几行，就好用fgets()。如果有更好的方法的话教一下呗～
    */
   /*尝试一下fgetc()这个玩意儿呗*/

    while (1) {
        c = fgetc(fin);

        if (feof(fin)) {
            break;
        }

        if (c == '\t') {
            int spaces = pos % TABSIZE;

            for ( ; spaces > 0; spaces++) {
                fprintf(fout, " ");
            }
        } else {
            fprintf(fout, "%c", c);
        }

        pos++;
    }

    fclose(fin);
    fclose(fout);

    return 0;
}