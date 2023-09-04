#include <iostream>
#include <vector>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long> dp;
    int n;
    cin >> n;   
    dp.resize(n+1);
    dp[1] = 1;
    dp[2] = 1;

    for(int i = 3; i<=n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
}