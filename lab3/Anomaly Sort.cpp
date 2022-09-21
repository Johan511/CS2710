
#include <bits/stdc++.h>
using namespace std;

void solve();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}
#define int long long
void solve()
{
    int length;
    cin >> length;
    vector<int> numbers;
    int x;
    for (int i = 0; i < length; i++)
    {
        cin >> x;
        numbers.push_back(x);
    }
    for (int i = 1; i < length; i++)
    {
        if (numbers[i] >= numbers[i - 1])
        {
        }
        else
        {
            int temp = numbers[i];
            numbers[i] = numbers[i - 1];
            numbers[i - 1] = temp;
            i++;
        }
    }
    bool sorted = true;
    for (int i = 1; i < length; i++)
    {
        if (numbers[i] < numbers[i - 1])
        {
            sorted = false;
        }
    }
    if (sorted == false)
    {
        cout << "NO" << endl;
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            cout << numbers[i] << " ";
        }
    }
    cout << endl;
}

