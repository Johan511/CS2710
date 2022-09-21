// https : //www.hackerrank.com/pdslab-2022-1

#include <bits/stdc++.h>
using namespace std;

struct word_index
{
    string word;
    vector<long long int> indices;
    word_index(string word, long long int index)
    {
        this->word = word;
        indices.push_back(index);
    }
};

typedef struct word_index swi;
bool compare(swi w1, swi w2);
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
    int num_of_words;
    cin >> num_of_words;
    vector<word_index> words;
    string word;
    for (int i = 0; i < num_of_words; i++)
    {
        cin >> word;
        bool a = true;
        for (int j = 0; j < words.size(); j++)
        {
            if (words[j].word == word)
            {
                words[j].indices.push_back(i);
                a = false;
                break;
            }
        }
        if (a)
        {
            words.push_back(word_index(word, i));
        }
    }
    sort(words.begin(), words.end(), compare);

    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i].word << " ";
        for (int j = 0; j < words[i].indices.size(); j++)
        {
            cout << words[i].indices[j] << " ";

            /* code */
        }
        cout << endl;
    }
}

bool compare(swi w1, swi w2)
{
    if (w1.word < w2.word)
        return true;
    else if (w1.word == w2.word)
        return (w1.indices[0] < w2.indices[0]);
    else
        return false;
}

