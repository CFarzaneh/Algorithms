#include <cstdio> 
#include <cstdlib>
#include <chrono>

int* quickSort(int *arr, int low, int high);
int partition(int arr[], int low, int high);
int* initialize_array(int *arr, size_t size);
void swap(int* a, int* b);

int main() {
	
	srand(time(0));
	FILE *fp;
	
	fp = fopen("output.txt","w");

	int j = 0;
	int i = 10;
	while(i <= 1000000) {
		int * arr = new int[i];
		initialize_array(arr,i);

		auto start = std::chrono::high_resolution_clock::now();
		quickSort(arr, 0, i-1);
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

int* quickSort(int *arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
	return arr;
}

//Lomuto
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high-1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}