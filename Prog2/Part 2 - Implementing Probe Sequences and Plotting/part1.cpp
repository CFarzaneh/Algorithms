#define HASHTABLESIZE 1048576
#define null 2147483647
#define deleted -2147483648
#define c1 2
#define c2 3

void init(int *hash_table);
void insert(int *hash_table, int val);
char search(int *hash_table, int val);
void remove(int *hash_table, int val);
int hashFunc(const int val);

int numOfElements = 0;
int numOfProbes = 0;

/*
* hash_table will be an integer array of size 1,000,000
* You need to initialize this table.
*/
void init(int *hash_table) {
	for (int i = 0; i < HASHTABLESIZE; ++i)
		hash_table[i] = null;
}
/*
* You need to insert val into hash_table in place.
*/
void insert(int *hash_table, int val) {
	if (numOfElements != HASHTABLESIZE) {
		numOfProbes = 0;
		unsigned int i = 0;
		while (numOfProbes < HASHTABLESIZE) {
			int h = ((hashFunc(val) + c1*(i*i*i) + c2*i) % HASHTABLESIZE);
			if (hash_table[h] == null || hash_table[h] == deleted) {
				hash_table[h] = val;
				numOfProbes++;
				numOfElements++;
				break;
			}
			else {
				numOfProbes++;
				i++;
			}
		}
	}
}
/*
* Return 1 if val is in hash_table, 0 otherwise.
*/
char search(int *hash_table, int val) {
	unsigned int i = 0;
	int h = ((hashFunc(val) + c1*(i*i*i) + c2*i) % HASHTABLESIZE);
	while(hash_table[h] != null && i < HASHTABLESIZE) {
		if (hash_table[h] == val)
			return 1;
		else
			i++;
		h = ((hashFunc(val) + c1*(i*i*i) + c2*i) % HASHTABLESIZE);
		if (val == null && hash_table[h] == val)
			return 1;
	}
	return 0;
}
/*
* Delete the first encountered val from hash_table in place.
*/
void remove(int *hash_table, int val) {
	unsigned int i = 0;
	int h = ((hashFunc(val) + c1*(i*i*i) + c2*i) % HASHTABLESIZE);
	while(hash_table[h] != null && i < HASHTABLESIZE) {
		if (hash_table[h] == val) {
			hash_table[h] = deleted;
			numOfElements--;
			break;
		}
		else
			i++;
		h = ((hashFunc(val) + c1*(i*i*i) + c2*i) % HASHTABLESIZE);
	}
}

int hashFunc(const int val) {
	return val % HASHTABLESIZE;
}