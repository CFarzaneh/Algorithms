#include <cstdio> 
#include <cstdlib>
#include <chrono>

int* initialize_array(int *arr, size_t size);
int* counting_sort(int *arr, int n);

int main() {

	srand(time(0));
	FILE *fp;
	
	fp = fopen("counting_sort_output.txt","w");

	int j = 0;
	int i = 10;
	while(i <= 1000000) {
		int * arr = new int[i];
		initialize_array(arr,i);

		auto start = std::chrono::high_resolution_clock::now();
		int * sorted = counting_sort(arr,i);
		auto end = std::chrono::high_resolution_clock::now();
		double elapsed_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count());
		if(i != 1000000)
			fprintf(fp,"%f,",elapsed_time/1e9);
		else
			fprintf(fp,"%f\n",elapsed_time/1e9);

		delete [] arr;
		delete [] sorted;

		if(j%2 != 0)
			i*=2;
		else
			i*=5;
		++j;
	}

	fclose(fp);

	return 0;
}

int* counting_sort(int *arr, int n) {
	int * C = new int[65536];
	int * B = new int[n];
	for (int i = 0; i < 65536; ++i)
		C[i] = 0;
	for (int i = 0; i < n; ++i)
		C[arr[i]]++;
	for (int i = 1; i < 65536; ++i)
		C[i] = C[i] + C[i-1];
	for (int i = n-1; i >= 0; --i) {
		B[C[arr[i]]-1] = arr[i];
		C[arr[i]]--;
	}
	delete [] C;
	return B;
}

int* initialize_array(int *arr, size_t size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % 65536;
	}
	return arr;
}