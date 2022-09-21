#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;
using std::chrono::milliseconds;

/* WRITE YOUR IMPLEMENTATION OF DETERMINISTIC QUICK SORT HERE.
NOTE THAT IN DETERMINISTIC QUICK SORT, THE PIVOT IS CHOSEN FROM A FIXED LOCATION IN THE ARRAY
(TYPICALLY THE LAST ELEMENT).
*/

void swap(int &e1, int &e2)
{
	int temp = e1;
	e1 = e2;
	e2 = temp;
}

int checkSorted(int arr[], int low, int high)
{
	for (int i = low + 1; i < high; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			return i;
		}
	}
	return -1;
}

int __pivot_deterministic(int arr[], int low, int high)
{
	return (high - 1);
}

int __partition_0(int *array, int start, int end)
{
	int l_marker = start;
	int g_marker = start;
	int pivot_index = __pivot_deterministic(array, start, end);
	swap(array[pivot_index], array[start]);
	for (int i = start + 1; i <= end; i++)
	{
		if ((array[start] < array[i]))
		{
			g_marker++;
		}
		else
		{
			swap(array[l_marker + 1], array[i]);
			l_marker++;
			g_marker++;
		}
	}
	swap(array[start], array[l_marker]);
	// cout << "start : " << start << "  ";
	// cout << "end : " << end << "  ";
	// cout << "pivot : " << l_marker << "  ";
	// cout << endl;
	return l_marker;
}

void quickSort(int arr[], int low, int high)
{
	if (high - low > 0)
	{
		int pivot_position = __partition_0(arr, low, high);

		quickSort(arr, low, pivot_position - 1);
		quickSort(arr, pivot_position + 1, high);
	}
	return;
}

/* DO NOT CHANGE THIS CODE */
int main()
{
	ifstream input_file("input.txt");
	ofstream output_file("output.txt");

	int N;

	if (!input_file.is_open())
		return 1;

	input_file >> N;

	int arr[N];
	int i = 0;

	while (input_file.good())
		input_file >> arr[i++];

	input_file.close();

	auto t1 = high_resolution_clock::now();
	quickSort(arr, 0, N);
	auto t2 = high_resolution_clock::now();

	if (checkSorted(arr, 0, N) != -1)
	{
		cout << checkSorted(arr, 0, N) << endl;
	}

	for (int i = 0; i < N; i++)
		output_file << arr[i] << " ";

	/* Getting number of milliseconds as an integer. */
	auto ms_int = duration_cast<microseconds>(t2 - t1);

	cout << ms_int.count();

	return 0;
}
