/**************************************************************************
 *
 *  File: fast_vector.cpp
 *
 *  Purpose: Implements vector utlizing doubling strategy for reallocation.
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
#include <vector>

using namespace std;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;
using std::chrono::milliseconds;

// Implement the methods for the class. Insert should implement the doubling strategy
// for the new allocation size.
class FastVector
{
private:
    int capacity;         // Current max size of the array
    int size = 0;         // Current number of elements in the array
    int expansion_factor; // Factor by which the capacity should be increased in case of an overflow. You can set this to 2 in the constructor method.
    int *arr;
    int start = 0;
    int end = 0;

public:
    int add1(int a, int num)
    {
        return (a + num) % capacity;
    }
    int sub1(int a, int num)
    {
        if (a - num >= 0)
        {
            return (a - num) % capacity;
        }
        else
        {
            while (a - num <= 0)
            {
                a = a + capacity;
            }
            return (a - num) % capacity;
        }
    }
    FastVector();          // Default constructor initializing all the fields; Please initialize capacity to 2.
    void Insert(int, int); // Inserts the element at the ith index and shifts all elements on the right side one place to the right.
    void Set(int, int);    // Sets the element in ith slot in the vector
    int Get(int);          // Gets the element of ith slot in the vector
    void Erase(int);       // Erases the element in the ith slot and shifts all the elements on the right side one place to the left.
    int Size();            // Returns the number of elements in the vector
};

FastVector::FastVector()
{
    capacity = 2;

    arr = new int[capacity];
}

/* 0 <= i <= Size() */
void FastVector::Insert(int i, int elem)
{
    if (size < capacity)
    {
        if (i == 0)
        {
            start = sub1(start, 1);
            arr[start] = elem;
        }
        else if (i == size)
        {
            arr[end] = elem;

            end = add1(end, 1);
        }
        else
        {
            int posn = end;
            for (int i = 0; i < size - i; i++)
            {
                arr[add1(posn, 1)] = arr[posn];
                sub1(posn, 1);
            }
            arr[add1(posn, 1)] = elem;
            end = add1(end, 1);
        }
        size++;
    }
    else
    {
        int *new_arr = new int[capacity * 2];

        for (int i = 0; i < size; i++)
        {
            new_arr[i] = this->Get(i);
        }
        capacity = capacity * 2;
        delete arr;
        this->arr = new_arr;
        start = 0;
        end = size;
        if (size < capacity)
        {
            if (i == 0)
            {
                start = sub1(start, 1);
                arr[start] = elem;
            }
            else if (i == size)
            {
                arr[end] = elem;

                end = add1(end, 1);
            }
            else
            {
                int posn = end;
                for (int i = 0; i < size - i; i++)
                {
                    arr[add1(posn, 1)] = arr[posn];
                    sub1(posn, 1);
                }
                arr[add1(posn, 1)] = elem;
                end = add1(end, 1);
            }
        }
        size++;
    }
}

/* 0 <= i <= Size()-1 */
void FastVector::Set(int i, int elem)
{

    int posn = start;
    posn = add1(posn, i);
    arr[posn] = elem;
}

/* 0 <= i <= Size()-1 */
int FastVector::Get(int i)
{
    int posn = start;
    posn = add1(posn, i);
    return arr[posn];
}

/* 0 <= i <= Size()-1 */
void FastVector::Erase(int i)
{
    if (i == 0)
    {
        start = add1(start, 1);
    }
    else if (i == size - 1)
    {
        end = sub1(end, 1);
    }
    else
    {
        int posn = sub1(end, 1);
        for (int i = 0; i < size - i - 1; i++)
        {
            arr[sub1(posn, 1)] = arr[posn];
            sub1(posn, 1);
        }
        end = sub1(end, 1);
    }
    size--;
}

int FastVector::Size()
{
    return size;
}

// DO NOT MODIFY THE CODE BELOW
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
    FastVector v;
    for (auto i : arr)
        v.Insert(v.Size(), i);
    auto t2 = high_resolution_clock::now();

    /* Getting number of microseconds as an integer. */
    auto ms_int = duration_cast<microseconds>(t2 - t1);

    cout << ms_int.count();
}
