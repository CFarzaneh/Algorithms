#include <cstdio> 
#include <cstdlib>
#include <chrono>

int* mergeSort(int *arr, int p, int r);
int* merge(int *arr, int p, int q, int r);
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
		mergeSort(arr, 0, i-1);
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

int* mergeSort(int *arr, int p, int r) {
    if (p < r) {
        int q = p+(r-p)/2;
 
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
 
        merge(arr, p, q, r);
    }

    return arr;
}

int* merge(int *arr, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], R[n2];

	for (int i = 0; i < n1; ++i)
		L[i] = arr[p + i];
	for (int i = 0; i < n2; ++i)
		R[i] = arr[q + 1 + i];

    int i = 0;
    int j = 0;
    int k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return arr;
}

int* initialize_array(int *arr, size_t size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % 65536;
	}
	return arr;
}


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}