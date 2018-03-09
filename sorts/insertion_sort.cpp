#include <cstdio> 
#include <cstdlib>
#include <chrono>

int* insertion_sort(int *arr, size_t len);
int* initialize_array(int *arr, size_t size);

int main() {
	
	srand(time(0));
	FILE *fp;

	fp = fopen("insertion_sort_output.txt","w");

	int j = 0;
	int i = 10;
	while(i <= 1000000) {
		int * arr = new int[i];
		initialize_array(arr,i);

		auto start = std::chrono::high_resolution_clock::now();
		insertion_sort(arr,i);
		auto end = std::chrono::high_resolution_clock::now();
		double elapsed_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count());
		if(i != 1000000)
			fprintf(fp,"%f,",elapsed_time/1e9);
		else
			fprintf(fp,"%f\n",elapsed_time/1e9);

		delete [] arr;

		if(j%2 != 0)
			i*=2;
		else
			i*=5;
		++j;
	}
	
	fclose(fp);

	return 0;
}

int* initialize_array(int *arr, size_t size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % 65536;
	}
	return arr;
}

int* insertion_sort(int *arr, size_t len) {
	int i, key, j;
	for (int i = 1; i < len; ++i) {
		key = arr[i];
		j = i-1;
		while(j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j-=1;
		}
		arr[j+1] = key;
	}
	return arr;
}