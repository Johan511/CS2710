#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class CircularVector
{
private:
    int capacity; //Current max size of the array
    int *arr;
    int start = 0;
    int end = 0;
    int size = 0;//Array of size capacity for storing the vector elements
  	/* You may add additional private fields */
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
    CircularVector(); // Default constructor initializing all the fields
    void Insert(int,int); // Inserts the element at the ith index of the vector and shifts all elements on the right side one place to the right.
    void Set(int, int); // Sets the element in ith slot in the vector
    int Get(int); // Gets the element of ith slot in the vector
    void Erase(int); // Erases the element in the ith slot and shifts all the elements on the right side one place to the left.
    int Size(); // Returns the number of elements in the vector
};

CircularVector::CircularVector()
{
        capacity = 2;

    arr = new int[capacity];
}

/*0 <= i <= Size()*/
void CircularVector::Insert(int i, int elem)
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
        int *new_arr = new int[capacity *2];

        for (int i = 0; i < size; i++)
        {
            new_arr[i] = this->Get(i);
        }
        capacity = capacity *2;
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

/*0 <= i <= Size()-1*/
void CircularVector::Set(int i, int elem)
{
 int posn = start;
    posn = add1(posn, i);
    arr[posn] = elem;
}

/*0 <= i <= Size()-1*/
int CircularVector::Get(int i)
{
  int posn = start;
    posn = add1(posn, i);
    return arr[posn];
}

/*0 <= i <= Size()-1*/
void CircularVector::Erase(int i)
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

int CircularVector::Size()
{
    return size;
}

int main()
{
  int numCommands, command;
  int i,j;
  int elem,size;
  cin >> numCommands;
  CircularVector vec;
  for (i = 0; i < numCommands; i++)
  {
    cin >> command;
      int index = 0;
    switch(command)
    {
      case 1:
        cin >> index >> elem;
        vec.Insert(index, elem);
        break;
      case 2:
        cin >> index >> elem;
        vec.Set(index, elem);
        break;
      case 3:
        cin >> index;
        cout << vec.Get(index) << endl;
        break;
      case 4:
        cin >> index;
        vec.Erase(index);
        break;
      case 5:
        size = vec.Size();
        for(j = 0; j < size; j++)
          cout << vec.Get(j) << " ";
        cout << endl;
        break;
      default:
        cout << "Wrong command!" << endl;
    }
  }

}
