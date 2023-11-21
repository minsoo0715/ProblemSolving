#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n';
vector<vector<int> > dp;
string str1;
string str2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str1 >> str2; 
    int l1 = str1.length(), l2 = str2.length();
    dp = vector< vector<int> >(l1+1, vector<int>(l2+1));

    for(int i = 1; i<=l1; ++i) {
        for(int j = 1; j<=l2; ++j) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[l1][l2];


    return 0;
}