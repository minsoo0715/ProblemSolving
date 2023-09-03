#include <iostream>
#include <map>

using ll = long long int;

std::map<ll, ll> dp;
ll p, q;

ll solve(ll n) {
    if(n == 0) {
        return 1;
    }
    if(dp[n] != 0) {
        return dp[n];
    }
    return dp[n] = solve(n/p) + solve(n/q);
}

int main() {
    ll n;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> p >> q;

    std::cout << solve(n);

    return 0;
}
