#include <iostream>
#include <vector>
#define endl '\n';
using namespace std;

vector<int> dp = vector<int>(5001, -1);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, s5, s3;
    cin >> N;
    dp[3] = dp[5] = 1;
    for(int i = 6; i<=N; ++i) {
        s5 = dp[i-5]; s3 = dp[i-3];
        if(s5 > 0 && s3 > 0) {
            dp[i] = min(s3, s5) + 1;
        }else if(s5 < 0 && s3 < 0) {
            dp[i] = -1;
        } else {
            dp[i] = (s3 > 0 ? s3 : s5) + 1;
        }
    }
    cout << dp[N];
    return 0;
}