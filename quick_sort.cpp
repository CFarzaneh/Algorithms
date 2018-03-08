#include <cstdio> 
#include <cstdlib>
#include <chrono>

void quickSort(int *arr, int low, int high);
int partition(int arr[], int low, int high);
int* initialize_array(int *arr, size_t size);
void swap(int* a, int* b);
void printArray(int arr[], int size);

int main() {
	
	srand(time(0));
	FILE *fp;
	
	int arr1[10];
	int arr2[50];
	int arr3[100];
	int arr4[500];
	int arr5[1000];
	int arr6[5000];
	int arr7[10000];
	int arr8[50000];
	int arr9[100000];
	int arr10[500000];
	int arr11[1000000];

	initialize_array(arr1,10);
	initialize_array(arr2,50);
	initialize_array(arr3,100);
	initialize_array(arr4,500);
	initialize_array(arr5,1000);
	initialize_array(arr6,5000);
	initialize_array(arr7,10000);
	initialize_array(arr8,50000);
	initialize_array(arr9,100000);
	initialize_array(arr10,500000);
	initialize_array(arr11,1000000);

	fp = fopen("output.txt","w");
	
	int n = sizeof(arr1)/sizeof(arr1[0]);
	auto start = std::chrono::high_resolution_clock::now();
	quickSort(arr1, 0, n-1);
	auto end = std::chrono::high_resolution_clock::now();
	double elapsed_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count());
	fprintf(fp,"%f,",elapsed_time/1e9);

	n = sizeof(arr2)/sizeof(arr2[0]);
	start = std::chrono::high_resolution_clock::now();
	quickSort(arr2, 0, n-1);
	end = std::chrono::high_resolution_clock::now();
	elapsed_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count());
	fprintf(fp,"%f,",elapsed_time/1e9);

	n = sizeof(arr3)/sizeof(arr3[0]);
	start = std::chrono::high_resolution_clock::now();
	quickSort(arr3, 0, n-1);
	end = std::chrono::high_resolution_clock::now();
	elapsed_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count());
	fprintf(fp,"%f,",elapsed_time/1e9);

	n = sizeof(arr4)/sizeof(arr4[0]);
	start = std::chrono::high_resolution_clock::now();
	quickSort(arr4, 0, n-1);
	end = std::chrono::high_resolution_clock::now();
	elapsed_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count());
	fprintf(fp,"%f,",elapsed_time/1e9);

	n = sizeof(arr5)/sizeof(arr5[0]);
	start = std::chrono::high_resolution_clock::now();
	quickSort(arr5, 0, n-1);
	end = std::chrono::high_resolution_clock::now();
	elapsed_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count());
	fprintf(fp,"%f,",elapsed_time/1e9);

	n = sizeof(arr6)/sizeof(arr6[0]);
	start = std::chrono::high_resolution_clock::now();
	quickSort(arr6, 0, n-1);
	end = std::chrono::high_resolution_clock::now();
	elapsed_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count());
	fprintf(fp,"%f,",elapsed_time/1e9);

	n = sizeof(arr7)/sizeof(arr7[0]);
	start = std::chrono::high_resolution_clock::now();
	quickSort(arr7, 0, n-1);
	end = std::chrono::high_resolution_clock::now();
	elapsed_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count());
	fprintf(fp,"%f,",elapsed_time/1e9);

	n = sizeof(arr8)/sizeof(arr8[0]);
	start = std::chrono::high_resolution_clock::now();
	quickSort(arr8, 0, n-1);
	end = std::chrono::high_resolution_clock::now();
	elapsed_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count());
	fprintf(fp,"%f,",elapsed_time/1e9);

	n = sizeof(arr9)/sizeof(arr9[0]);
	start = std::chrono::high_resolution_clock::now();
	quickSort(arr9, 0, n-1);
	end = std::chrono::high_resolution_clock::now();
	elapsed_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count());
	fprintf(fp,"%f,",elapsed_time/1e9);

	n = sizeof(arr10)/sizeof(arr10[0]);
	start = std::chrono::high_resolution_clock::now();
	quickSort(arr10, 0, n-1);
	end = std::chrono::high_resolution_clock::now();
	elapsed_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count());
	fprintf(fp,"%f,",elapsed_time/1e9);

	n = sizeof(arr11)/sizeof(arr11[0]);
	start = std::chrono::high_resolution_clock::now();
	quickSort(arr11, 0, n-1);
	end = std::chrono::high_resolution_clock::now();
	elapsed_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count());
	fprintf(fp,"%f",elapsed_time/1e9);

	fclose(fp);

	return 0;
}

int* initialize_array(int *arr, size_t size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % 65536;
	}
	return arr;
}

void quickSort(int *arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

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

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}