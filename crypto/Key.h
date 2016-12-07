/* Michael LeCaptain
 * mplecapt
 * Header for key management
 */

typedef struct {
	char* data;	// Stores the actual data for this Key
	int size;	// How many bytes of memory this Key can store
	int pos;	// Current character to use next for encoding/decoding
} Key;

bool initKey(Key* key, const char* filename);
	// Initialize and load from the given filename, returns false if loading of key failed

void freeKey(Key* key);
	// Deallocate any memory used by key

char applyKey(Key* key, Stats* stats, char ch, bool debug);
	// Proccess ch using the current position in the key, advance key, update stats, optionally print debug line, returns output character
