/* Michael LeCaptain
 * mplecapt
 * Implementation of stats datatype
 */

typedef struct {
	int total;
	int letters;
	int spaces;
	int numbers;
	int other;
} Stats;

void initStats(Stats* stats) {
	stats->letters = 0;
	stats->spaces = 0;
	stats->numbers = 0;
	stats->other = 0;
}

void updateStats(Stats* stats, char ch) {
	stats->total += 1;
	if(ch == 32)
		stats->spaces += 1;
	else if( (ch > 64 && ch < 91) || (ch > 96 && ch < 123) )
		stats->letters += 1;
	else if(ch > 47 && ch < 58)
		stats->numbers += 1;
	else
		stats->other += 1;
}

void printStats(Stats* stats) {
	double lp = stats->letters / stats->total * 100;
	double sp = stats->spaces / stats->total * 100;
	double np = stats->numbers / stats->total * 100;
	double op = stats->other / stats->total * 100;
	
	printf("Output %.0f characters: %.2f%% letters, %.2f%% spaces, %.2f%% numbers, %.2f%% other\n", stats->total, lp, sp, np, op);
}