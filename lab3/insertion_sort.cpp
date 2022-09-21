/**************************************************************************
 *
 *  File: insertion_sort.cpp
 *
 *  Purpose: Performs Insertion Sort.
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
#include <chrono>

using namespace std;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;
using std::chrono::milliseconds;

void insertion_sort(int[], int);

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
    insertion_sort(arr, N);
    auto t2 = high_resolution_clock::now();

    for (int i = 0; i < N; i++)
        output_file << arr[i] << " ";

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<microseconds>(t2 - t1);

    cout << ms_int.count();
}

/* ADD YOUR IMPLEMENTATION HERE */
void insertion_sort(int arr[], int N)
{
    int i = 1;
    int j = 0;
    int temp = 0;
    for (i = 1; i < N; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }

    return;
}
