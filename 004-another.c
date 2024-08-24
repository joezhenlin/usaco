#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//我看到这个用法，就被吸引了
char* rotate90(char *arr);
char* reflect(char *arr);
char* getSquare(FILE *f);
int checkRotate(char *orig, char *new);

#define rotate180(a) (rotate90(rotate90(a)))
#define rotate270(a) (rotate90(rotate180(a)))

int len;

char* rotate90(char *arr){
	char *ret = malloc(sizeof(char) * len * len);
	if (ret == NULL) {
		// Handle memory allocation failure
		return NULL;
	}
	int i;
	for (i = 0; i < len*len; i++)
		ret[i] = arr[(len - i%len - 1) * len + i/len];
	return ret;
}

char* reflect(char *arr) {
	char *ret = malloc(sizeof(char) * len * len);
	if (ret == NULL) {
		// Handle memory allocation failure
		return NULL;
	}
	int i;
	for (i = 0; i < len*len; i++)
		ret[i] = arr[i/len*len + len - i%len - 1];
	return ret;
}

char* getSquare(FILE *f){
	char *square = malloc(sizeof(char) * len * len), i;
	for (i = 0; i < len*len; i++){
		fscanf(f, "%c", &square[i]);
		if (i % len == len-1) fgetc(f);
	}
	return square;
}

int checkRotate(char *orig, char *new) {
	if (!memcmp(rotate90(orig), new, len*len)) return 1;
	if (!memcmp(rotate180(orig), new, len*len)) return 2;
	if (!memcmp(rotate270(orig), new, len*len)) return 3;
	return -1;
}

int main(void){
	FILE *fin = fopen("transform.in", "r");
	FILE *fout = fopen("transform.out", "w");

	if (fin == NULL || fout == NULL) {
		// Handle file open failure
		return 1;
	}

	fscanf(fin, "%d\n", &len);
	
	char *orig = getSquare(fin);
	char *new = getSquare(fin);
	
	int tr = checkRotate(orig, new);
	if (tr < 0) {
		if (!memcmp(reflect(orig), new, len*len)) 		tr = 4;
		else if (checkRotate(reflect(orig), new) > 0) 	tr = 5;
		else if (!memcmp(orig, new, len*len)) 			tr = 6;
		else 											tr = 7;
	}	
		
	fprintf(fout, "%d\n", tr);

	// Free memory before exiting
	free(orig);
	free(new);

	fclose(fin);
	fclose(fout);
	return 0;
}