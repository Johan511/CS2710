/**************************************************************************
 *
 *  File: merge_sort.cpp
 *
 *  Purpose: Performs MergeSort.
 *
 *  Author:
 *
 *  Date:
 *
 *  Bugs:
 *
 *  Change Log:
 *
 **************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <chrono>

using namespace std;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;
using std::chrono::milliseconds;

void merge_sort(int[], int, int);
void merge(int[], int, int, int);

/* DO NOT MODIFY THIS CODE */
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
    merge_sort(arr, 0, N - 1);
    auto t2 = high_resolution_clock::now();

    for (int i = 0; i < N; i++)
        output_file << arr[i] << " ";

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<microseconds>(t2 - t1);

    cout << ms_int.count();
}

void __merge(int *array1, int len1, int *array2, int len2)
{
    int *temp_array;
    temp_array = new int[len1 + len2];
    int pointer1 = 0;
    int pointer2 = 0;
    while (pointer1 < len1 && pointer2 < len2)
    {
        if (array1[pointer1] < array2[pointer2])
        {
            temp_array[pointer1 + pointer2] = array1[pointer1];
            pointer1++;
        }
        else
        {
            temp_array[pointer2 + pointer1] = array2[pointer2];
            pointer2++;
        }
    }
    if (pointer1 < len1)
    {
        while (pointer1 < len1)
        {
            temp_array[pointer1 + pointer2] = array1[pointer1];
            pointer1++;
        }
    }
    if (pointer2 < len2)
    {
        while (pointer2 < len2)
        {
            temp_array[pointer2 + pointer1] = array2[pointer2];
            pointer2++;
        }
    }

    for (int i = 0; i < len1; i++)
    {
        array1[i] = temp_array[i];
    }
    for (int i = 0; i < len2; i++)
    {
        array2[i] = temp_array[i + len1];
    }
    free(temp_array);
}
/* ADD YOUR IMPLEMENTATION HERE */
void merge_sort(int arr[], int from_index, int to_index)
{
    if (to_index - from_index + 1 > 1)
    {
        int middle = (from_index + to_index) / 2;
        merge_sort(arr, from_index, middle);
        merge_sort(arr, middle + 1, to_index);
        __merge(arr + from_index, middle - from_index + 1, arr + middle + 1, to_index - middle);
    }

    return;
}
