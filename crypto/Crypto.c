/* Michael LeCaptain
 * mplecapt
 * The main file for encryption
 */

#include <stdio.h>
#include <stdlib.h>
//#include "Crypto.h"

int main(int argc, char** argv) {
	//prints instructions if invalid input
	if(argc <= 3) {
		printf("Crypto <input file> <output file> <key file> [debug]\n");
		return 1;
	}

	//initialize variables
	Stats stats;
	initStats(stats);

	//load files
	FILE* input = fopen(argv[1], "r");
	FILE* output = fopen(argv[2], "w");
	FILE* key = fopen(argv[3], "r");

	//error checking
	if(input == NULL) { printf("Failed to open input file: %s\n", argv[1]); return 1; }
	if(output == NULL) { printf("Failed to open output file: %s\n", argv[2]); return 1; }
	if(key == NULL) { printf("Failed to load key file: %s\n", argv[3]); return 1; }

	//read input
	while(!feof(input)) {
		char t1 = fgetc(input);
		char t2 = fgetc(key);
		char tf = t1 ^ t2;

		//convert illegible characters
		char pt1 = (t1 < 32 || t1 > 126) ? '~' : t1;
		char pt2 = (t2 < 32 || t2 > 126) ? '~' : t2;
		char ptf = (tf < 32 || tf > 126) ? '~' : tf;

		//debug
		if(argc == 5 && atoi(argv[4]) != 0) {
			printf("%3d '%c' ^ %3d '%c' -> %3d '%c'\n", t1, pt1, t2, pt2, tf, ptf);
		}

		//write output
		fprintf(output, "%c", tf);

		//increment counts
		updateStats(stats, tf);
	}


	//print statistics information
	printStats(stats);


/* Remember to close files when done
 *	fclose(input);
 *	fclose(output);
 *	fclose(key);
 *	input = NULL;
 *	output = NULL;
 *	key = NULL;
 */
	return 0;
}
