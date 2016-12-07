/* Michael LeCaptain
 * mplecapt
 * Header for statistical data
 */

typedef struct {
	int letters;
	int spaces;
	int numbers;
	int other;
} Stats;

void initStats(Stats* stats);

void updateStats(Stats* stats, char ch);

void printStats(Stats* stats);