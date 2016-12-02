/* Michael LeCaptain
 * mplecapt
 * The main file for encryption
 */

#include <stdio.h>
#include <stdlib.h>
#include "Crypto.h"

int main(int argc, char** argv) {
	//prints instructions if invalid input
	if(argc <= 3) {
		printf("Crypto <input file> <output file> <key file> [debug]\n");
		return 1;
	}

	double charCount = 0;
	double alphaCount = 0;
	double spaceCount = 0;
	double numberCount = 0;
	
	
	//print if debug
	char t1 = argv[1][0];
	char t2 = argv[2][0];
	char tf = t1 ^ t2;
	if(argc == 5 && atoi(argv[4]) != 0) {
		printf("%d '%c' ^ %d '%c' -> %d '%c'\n", t1, t1, t2, t2, tf, tf);
	}


	
	//print statistics information
	double otherCount = charCount - alphaCount - spaceCount - numberCount;
	printf("Output %.0f characters: %.2f%% letters, %.2f%% spaces, %.2f%% numbers, %.2f%% other\n", 
		charCount, (alphaCount / charCount * 100), (spaceCount / charCount * 100), (numberCount / charCount * 100), (otherCount / charCount * 100));

	return 0;
}
