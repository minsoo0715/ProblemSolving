#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n';
vector<vector<int>> s = vector<vector<int>>(26, vector<int>(200000));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    char alphabet;
    int N;
    int m, n;

    cin >> str >> N;

    for(int i = 0; i<str.length(); ++i) {
        s[str[i] - 'a'][i] += 1;
        if(i > 0) {
            for(int j = 'a'; j<='z'; ++j) {
                s[j - 'a'][i] += s[j - 'a'][i-1];
            }
        }
    }


    for(int i = 0; i<N; ++i) {
        cin >> alphabet >> m >> n;
        if(m == 0) {
            cout << s[alphabet-'a'][n] << endl;
            continue;
        }
        cout << s[alphabet-'a'][n] - s[alphabet-'a'][m-1] << endl;
    }
    return 0;
}