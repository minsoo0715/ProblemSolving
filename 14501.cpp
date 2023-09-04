#include <iostream>
#include <vector>

std::vector<int> t = std::vector<int>(16);
std::vector<int> p = std::vector<int>(16);
std::vector<int> dp = std::vector<int>(16, -1);

int n;

int solve(int k = 0) {
    if(k + t[k] > n+1) {
        return 0;
    }
    if(dp[k] != -1) {
        return dp[k];
    }

    int &ref = dp[k] = 0;

    for(int i = k + t[k]; i<=n; ++i) {
        ref = std::max(solve(i), ref);
    }

    return ref += p[k];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 1; i<=n; ++i) {
        std::cin >> t[i] >> p[i];
    }
    std::cout << solve();

    return 0;
}