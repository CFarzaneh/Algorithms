#include <cstdio> 
#include <cstdlib>
#include <chrono>

int* maxHeapify(int *arr, int length, int i);
int* buildMaxHeap(int *arr, int length);
int* heapSort(int *arr, int length);
int* initialize_array(int *arr, size_t size);
void swap(int* a, int* b);

int main() {

	srand(time(0));
	FILE *fp;
	
	fp = fopen("heap_sort_output.txt","w");

	int j = 0;
	int i = 10;
	while(i <= 1000000) {
		int * arr = new int[i];
		initialize_array(arr,i);

		auto start = std::chrono::high_resolution_clock::now();
		heapSort(arr,i);
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

int* heapSort(int *arr, int length) {
	buildMaxHeap(arr, length);
	for (int i = length-1; i >= 0; --i) {
		swap(&arr[0], &arr[i]);
		maxHeapify(arr,i,0);
	}
	return arr;
}

int* buildMaxHeap(int *arr, int length) {
	for (int i = length / 2 - 1; i >= 0; --i)
		maxHeapify(arr,length,i);
	return arr;
}

int* maxHeapify(int *arr, int length, int i) {
	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;

	if (l < length && arr[l] > arr[largest])
		largest = l;

	if (r < length && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		maxHeapify(arr,length,largest);
	}
	return arr;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}