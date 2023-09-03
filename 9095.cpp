#include <iostream>
#include <vector>

std::vector<int> dp = std::vector<int>(11);

int solve(int k) {
    return dp[k] == 0 ? dp[k] = solve(k-1) + solve(k-2) + solve(k-3) : dp[k];
}

int main()
{
    int t, n;
    std::cin >> t;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int j = 0; j < t; ++j) {
        std::cin >> n;
        std::cout << solve(n) << '\n';
    }

    return 0;
}