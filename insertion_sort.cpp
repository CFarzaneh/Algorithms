#include <cstdio> 
#include <cstdlib>
#include <ctime>

int* insertion_sort(int *arr, size_t len);
int* initialize_array(int *arr, size_t size);

int main() {
	
	srand(time(0));
	clock_t t;
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
	
	t = clock();
	insertion_sort(arr1,10);
	t = clock() - t;
	fprintf(fp,"%f,",((float)t)/CLOCKS_PER_SEC*1000);

	t = clock();
	insertion_sort(arr2,50);
	t = clock() - t;
	fprintf(fp,"%f,",((float)t)/CLOCKS_PER_SEC*1000);

	t = clock();
	insertion_sort(arr3,100);
	t = clock() - t;
	fprintf(fp,"%f,",((float)t)/CLOCKS_PER_SEC*1000);

	t = clock();
	insertion_sort(arr4,500);
	t = clock() - t;
	fprintf(fp,"%f,",((float)t)/CLOCKS_PER_SEC*1000);

	t = clock();
	insertion_sort(arr5,1000);
	t = clock() - t;
	fprintf(fp,"%f,",((float)t)/CLOCKS_PER_SEC*1000);

	t = clock();
	insertion_sort(arr6,5000);
	t = clock() - t;
	fprintf(fp,"%f,",((float)t)/CLOCKS_PER_SEC*1000);

	t = clock();
	insertion_sort(arr7,10000);
	t = clock() - t;
	fprintf(fp,"%f,",((float)t)/CLOCKS_PER_SEC*1000);

	t = clock();
	insertion_sort(arr8,50000);
	t = clock() - t;
	fprintf(fp,"%f,",((float)t)/CLOCKS_PER_SEC*1000);

	t = clock();
	insertion_sort(arr9,100000);
	t = clock() - t;
	fprintf(fp,"%f,",((float)t)/CLOCKS_PER_SEC*1000);

	t = clock();
	insertion_sort(arr10,500000);
	t = clock() - t;
	fprintf(fp,"%f",((float)t)/CLOCKS_PER_SEC*1000);

	// t = clock();
	// insertion_sort(arr11,1000000);
	// t = clock() - t;
	// fprintf(fp,"%f",((float)t)/CLOCKS_PER_SEC*1000);

	fclose(fp);

	//System call to plot
	system("python plot.py");

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