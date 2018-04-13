#include <cstdio>
#include <random>
#include <iostream>
#include "cam.cpp"

void print(int *hash_table);

int main() {

	int * arr = new int[HASHTABLESIZE];
	init(arr);

	//******************************************************************************//
	FILE *fp;	
	fp = fopen("cam_probe_output.txt","w");
	
	int avg[50];
	int count = 0;
	int loadFactorRange = 0.5;
	for (int i = 0; i < HASHTABLESIZE; ++i) {
		std::random_device rd; 
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(-2147483647, 2147483646);
		int myNumber = dis(gen);

		insert(arr,myNumber);
		if (numOfElements >= 524288) {
			if (numOfElements == 524288)
				fprintf(fp,"x,y\n");
			double loadFactor = numOfElements/(double)HASHTABLESIZE;
			fprintf(fp,"%f,%i\n",loadFactor,numOfProbes);
		}
	}

	if (numOfElements == HASHTABLESIZE)
		printf("We good\n");
	else
		printf("We not good!\n");

	fclose(fp);
	//******************************************************************************//

	// for (int i = 0; i < HASHTABLESIZE; ++i) {
	// 	std::random_device rd; 
	// 	std::mt19937 gen(rd());
	// 	std::uniform_int_distribution<int> dis(-2147483647, 2147483646);
	// 	int myNumber = dis(gen);

	// 	insert(arr,myNumber);
	// }

	// printf("numOfElements: %i\n", numOfElements);
	// printf("numOfProbes: %i\n", numOfProbes);

	//print(arr);

	// int s;
	// printf("What should I remove?\n> ");
	// std::cin >> s;
	// remove(arr,s);
	// print(arr);
	// printf("What should I insert?\n> ");
	// std::cin >> s;
	// insert(arr,s);
	// print(arr);
	// printf("Now, what should I search for?\n> ");
	// std::cin >> s;
	// char c = search(arr,s);
	// if (c == 0)
	// 	printf("Sorry, not found.\n");
	// else
	// 	printf("Found!\n");

	// printf("Goodbye!\n");

	delete [] arr;
	return 0;
}

void print(int *hash_table) {
	for (int i = 0; i < HASHTABLESIZE; ++i) {
		if (hash_table[i] == null)
			printf("null");
		else
			printf("%i", hash_table[i]);
		if (i != HASHTABLESIZE-1)
			printf(", ");
		else
			printf("\n");
	}
	printf("numOfElements: %i\n", numOfElements);
	printf("numOfProbes: %i\n", numOfProbes);
}