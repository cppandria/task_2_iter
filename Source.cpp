
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>

using namespace std;

void print_arr(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << setw(3) << arr[i] << " ";
	}
	cout << endl;
}

//elem %2 ==0 => OK
// idx %8 !=0 -> OK
bool match_criteria(int elem, int idx) {

	if (elem % 2 == 0)
		return true;
	
	if (idx % 8 == 0) {
		return false;
	}
	else {
		return true;
	}
	
	return false;
}

int get_count(int *arr, int size) {
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if ((match_criteria(arr[i], i)))
		{
			count++;
		}
	}
	return count;
}

int get_sum(int *arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if ((match_criteria(arr[i], i)))
		{
			sum+= arr[i];
		}
	}
	return sum;
}
void change_matched_elem(int *arr, int size) {
	for (int i = 0; i < size; i++)
	{
		if ((match_criteria(arr[i], i)))
		{
			arr[i] = 0;
		}
	}
 }


void fill_array_with_randoms(int *arr, int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = 5 + rand() % (86);
	}
}

void print_results(int sum, int count) {
	cout << "Amount of elements =" << count << ", sum =" << sum << endl;
}

int main() {

	//srand(time(NULL));
	//as global variable is NOT acceptable in this task -> lets create array with predefined size


	int random_array[25];
	int size_of_array = sizeof(random_array) / sizeof(random_array[0]);
	fill_array_with_randoms(random_array, size_of_array);
	print_arr(random_array, size_of_array);

	int count = get_count(random_array, size_of_array);
	int sum = get_sum(random_array, size_of_array);
	change_matched_elem(random_array, size_of_array);
	print_results(sum, count);
	print_arr(random_array, size_of_array);
	return 0;
}
//46 68 61 17 82 77 45 37 49 45 34 28 66 62 76 66 76 79 16 23 60 75 37 72 39