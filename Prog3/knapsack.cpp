#include <cstdio>

void knapsack(unsigned int *weights, unsigned int *values, size_t n, unsigned long weight_limit);

void knapsack(unsigned int *weights, unsigned int *values, size_t n, unsigned long weight_limit) {

	unsigned int C[n+1][weight_limit+1];
	unsigned int keep[n+1][weight_limit+1];

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= weight_limit; ++j) {
			if (i == 0 || j == 0) {
				C[i][j] = 0;
				keep[i][j] = 0;
			}
			else if (weights[i-1] <= j) {
				if (values[i-1] + C[i-1][j-weights[i-1]] > C[i-1][j]) {
					C[i][j] = values[i-1] + C[i-1][j-weights[i-1]];
					keep[i][j] = 1;
				}
				else {
					C[i][j] = C[i-1][j];
					keep[i][j] = 0;
				}
			}
			else {
				C[i][j] = C[i-1][j];
				keep[i][j] = 0;
			}
		}
	}
	int E = weight_limit;
	for (int i = n; i >= 1; --i) {
		if (keep[i][E] == 1) {
			E = E - weights[i-1];
		}
		else {
			weights[i-1] = 0;
		}
	}
}