#include <cstdio> 
#include <cstdlib>
#include <chrono>

void maxHeapify(int *arr, int length, int i);
void buildMaxHeap(int *arr, int length);
void heapSort(int *arr, int length);
int* initialize_array(int *arr, size_t size);
void swap(int* a, int* b);
void printArray(int arr[], int size);

int main() {

	srand(time(0));
	FILE *fp;
	
	int arr1[10] = {4,5,2,3,1,7,8,9,6,0};
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

	//initialize_array(arr1,10);
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

	printArray(arr1,10);
	heapSort(arr1,10);
	printArray(arr1,10);

	return 0;
}

int* initialize_array(int *arr, size_t size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % 65536;
	}
	return arr;
}

void heapSort(int *arr, int length) {
	buildMaxHeap(arr, length);
	for (int i = length; i >= 2; --i) {
		swap(&arr[1], &arr[i]);
		length--;
		maxHeapify(arr,length,1);
	}
}

void buildMaxHeap(int *arr, int length) {
	for (int i = length/2-1; i >= 0; --i) {
		maxHeapify(arr,length,i);
	}
}

void maxHeapify(int *arr, int length, int i) {
	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;

	if ((l <= length) && (arr[l] > arr[largest]))
		largest = l;

	if ((r <= length) && (arr[r] > arr[largest]))
		largest = r;

	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		maxHeapify(arr,length,largest);
	}
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
