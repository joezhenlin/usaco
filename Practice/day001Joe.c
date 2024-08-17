#include <stdio.h>
#include <string.h>

void swap_string(char *str) {
    int length = strlen(str);
    
    for (int i = 0; i < length / 2; i++) {
        // Swap characters at indices i and length - i - 1
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    FILE *fin  = fopen ("day001.in", "r");
    FILE *fout = fopen ("day001.out", "w");

    char inputC[100];
    
    printf("Get a string containing 'a's and 'b's: ");
    fscanf(fin, "%s", inputC);
    
    // Remove the newline character at the end of the input string
    inputC[strcspn(inputC, "\n")] = 0;
    
    swap_string(inputC);
    
    fprintf(fout, "%s\n", inputC );

    fclose(fin);
    fclose(fout);
    
    return 0;
}
