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

string strip(string &word){
    int k = word.size();
while(k--){
    if(word[k] == (char) ('a' - 1)){
        word.resize(k);
    }
}
return word;
}
#define int long long
void solve()
{
    int n, k;
    cin >> n;
    cin >> k;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    
    for (int i = 0; i < words.size(); i++)
    {
        while (words[i].size() < k)
        {
            words[i].insert(words[i].size() , 1, (char) ('a' - 1));
        }
    }
    vector<pair<int, int> > abc;
    vector<vector<string> > buckets(27);
    vector<string> sorted;
    int j = 0;
    for (j = 0; j < k; j++)
    {int i = 0;
        for (i = 0; i < words.size(); i++)
        {
            buckets[words[i][k - j- 1] - 'a' + 1].push_back(words[i]);
        }
        words.clear();
        int jj = 0;
        for (jj = 0; jj < 27; jj++)
        {
            int ii = 0;
            for (ii = 0; ii < buckets[jj].size(); ii++)
            {
                words.push_back(buckets[jj][ii]);
            }
        }
        for (int i = 0; i < 27; i++)
        {
            buckets[i].clear();
        }
        
    }
    for (int i = 0; i < words.size(); i++)
    {
        words[i] = strip(words[i]);
    }
    
    int i = 0;
    for (i = 0; i < words.size(); i++)
    {
        cout << words[i] << " ";
    }
    cout << endl;
}

