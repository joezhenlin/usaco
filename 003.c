/*
We read the list of times, sort it by start time, and then walk over the list once, merging overlapping times. 
Then we walk the list watching for long milking periods and long non-milking periods.

An alternate approach would be to just keep an array of size a million and mark off times. On a nice fast processor, 
that’s probably fast enough, but our above algorithm will work even on slow processors, and it’s not much harder to write.
https://jvonk.github.io/usaco/2018/09/28/milk2.html#analysis
*/
/*
qsort是C标准库中的一个排序函数，它可以对任意类型的数组进行排序。qsort需要三个参数：要排序的数组、数组元素的个数和一个指向回调函数的指针。
回调函数必须满足两个条件：能够比较数组中的元素，返回一个整数表示它们之间的大小关系；并且它应该能够被qsort函数调用。
回调函数是一种在编程中广泛使用的技术，它允许一个函数作为参数传递给另一个函数，并在需要时被调用。这种机制使得代码更加灵活和可重用。
qsort函数说明：https://www.runoob.com/cprogramming/c-function-qsort.html
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXMILKING 5000

typedef struct Milking {
    int begin;
    int end;
}Milking;

/* or can:
typedef struct Milking	Milking;
struct Milking {
    int begin;
    int end;
};
*/

Milking milking[MAXMILKING];
int nmilking;

int milkcmp(const void *va, const void *vb)
{
    Milking *a, *b;

    a = (Milking*)va;
    b = (Milking*)vb;

    if(a->begin > b->begin)
	return 1;
    if(a->begin < b->begin)
	return -1;
    return 0;
}

void main(void)
{
    FILE *fin, *fout;
    int i, j, t, tmilk, tnomilk;
    Milking cur;

    fin = fopen("milk2.in", "r");
    fout = fopen("milk2.out", "w");
    assert(fin != NULL && fout != NULL);

    /* read input, sort */
    fscanf(fin, "%d", &nmilking);
    for(i=0; i<nmilking; i++)
	fscanf(fin, "%d %d", &milking[i].begin, &milking[i].end);

    qsort(milking, nmilking, sizeof(Milking), milkcmp);

    /* walk over list, looking for long periods of time */
    /* tmilk = longest milking time */
    /* tnomilk = longest non-milking time */
    /* cur = current span of milking time being considered */

    tmilk = 0;
    tnomilk = 0;
    cur = milking[0];
    for(i=1; i<nmilking; i++) {
	if(milking[i].begin > cur.end) {	/* a down time */
	    t = milking[i].begin - cur.end;
	    if(t > tnomilk)
		tnomilk = t;

	    t = cur.end - cur.begin;
	    if(t > tmilk)
		tmilk = t;

	    cur = milking[i];
	} else {	
	    if(milking[i].end > cur.end)
		cur.end = milking[i].end;
	}
    }

    /* check final milking period */
    t = cur.end - cur.begin;
    if(t > tmilk)
	tmilk = t;

    fprintf(fout, "%d %d\n", tmilk, tnomilk);
    exit(0);
}
