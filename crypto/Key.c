/* Michael LeCaptain
 * mplecapt
 * Implementation of Key
 */

#include <stdbool.h>
#include "Key.h"

typedef struct {
	char* data;
	int size;
	int pos;
} Key;

bool initKey(Key* key, const char* filename) {
	FILE* f = fopen(filename, rb);
	if(f == NULL) {
		printf("Failed to load key file: %s\n", filename);
		return false;
	}
	
	while(!feos(f)) {
		//fgetc(f);
	}
	
	fclose(f);
	f = NULL;
}

void freeKey(Key* key) {
	
}

char applyKey(Key* key, Stats* stats, char ch, bool debug) {
	
}
