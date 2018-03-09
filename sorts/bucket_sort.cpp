#include <cstdio> 
#include <cstdlib>
#include <chrono>
#include <list>

int* initialize_array(int *arr, size_t size);
int* bucket_sort(int* arr, int n);

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
		bucket_sort(arr,i);
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

int* bucket_sort(int* arr, int n) {
	std::list<int> buckets[7];

	for (int i = 0; i < n; ++i) {
		if (arr[i] < 10000)
			buckets[0].push_front(arr[i]);
		else if (arr[i] < 20000)
			buckets[1].push_front(arr[i]);
		else if (arr[i] < 30000)
			buckets[2].push_front(arr[i]);
		else if (arr[i] < 40000)
			buckets[3].push_front(arr[i]);
		else if (arr[i] < 50000)
			buckets[4].push_front(arr[i]);
		else if (arr[i] < 60000)
			buckets[5].push_front(arr[i]);
		else if (arr[i] < 70000)
			buckets[6].push_front(arr[i]);
	}

	for (int i = 0; i < 7; ++i)
		buckets[i].sort();

	int j = 0;
	for (int i = 0; i < 7; ++i) {
		while(!buckets[i].empty()) {
			arr[j] = buckets[i].front();
			buckets[i].pop_front();
			j++;
		}
	}
	
	return arr;

}

int* initialize_array(int *arr, size_t size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % 65536;
	}
	return arr;
}