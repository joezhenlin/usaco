#include <stdio.h>

typedef struct beadBlock {
    int previosWCnt;
    int cnt;
    char color;
} beadBlock;

int main(void) {
    FILE *fin = fopen("beads.in", "r");
    FILE *fout = fopen("beads.out", "w");

    int len, 
        ans = 0, 
        wCount = 0, 
        thisCnt = 0, 
        lenCnt = 0, 
        blockIndex = 0,
        pos = 0;
    beadBlock blocks[351];
    char beads[351], thisChar, currColor;

    fscanf(fin, "%d", &len);
    fscanf(fin, "%s", beads);

    while (beads[pos] == 'w') {
        pos++;
        wCount++;
    }

    if (pos == len) {
        fprintf(fout, "%d\n", len);

        fclose(fin);
        fclose(fout);
        return 0;
    }

    currColor = beads[pos];
    blocks[blockIndex].previosWCnt = wCount;
    for ( ; pos < len; pos++) {
        thisChar = beads[pos];

        if (thisChar == 'w') {
            wCount++;
        } else {
            if (thisChar != currColor) {
                blocks[blockIndex].cnt = thisCnt;
                blocks[blockIndex].color = currColor;
                blockIndex++;

                blocks[blockIndex].previosWCnt = wCount;
                thisCnt = 0;
                currColor = thisChar;
            }

            wCount = 0;
        }

        thisCnt++;
    }

    blocks[blockIndex].cnt = thisCnt;
    blocks[blockIndex].color = currColor;
    blockIndex++;

    if (blockIndex < 3) {
        ans = blocks[0].previosWCnt;
        ans += blocks[0].cnt;
        
        if (blockIndex == 2) {
            ans += blocks[1].cnt;
        }
    } else {
        int lastBlock = blockIndex - 1;

        if (blocks[lastBlock].color == blocks[0].color) {
            int ans2 = 0;

            ans = blocks[0].previosWCnt;
            ans += blocks[0].cnt;
            ans += blocks[lastBlock].previosWCnt;
            ans += blocks[lastBlock].cnt;
            ans += blocks[1].cnt;

            ans2 = blocks[0].previosWCnt;
            ans2 += blocks[0].cnt;
            ans2 += blocks[lastBlock].cnt;
            ans2 += blocks[lastBlock - 1].previosWCnt;
            ans2 += blocks[lastBlock - 1].cnt;

            ans = ans2 > ans ? ans2 : ans;
        } else {
            ans = blocks[0].previosWCnt;
            ans += blocks[0].cnt;
            ans += blocks[lastBlock].previosWCnt;
            ans += blocks[lastBlock].cnt;
        }

        for (int i = 0; i < lastBlock; i++) {
            int tmp = blocks[i].previosWCnt;
            tmp += blocks[i].cnt;
            tmp += blocks[i + 1].cnt;
            ans = tmp > ans ? tmp : ans;
        }
    }

    fprintf(fout, "%d\n", ans);

    fclose(fin);
    fclose(fout);

    return 0;
}