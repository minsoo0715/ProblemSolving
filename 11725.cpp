#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<bool> visited;
vector<int> ans;

void solve(int num = 1) {
    visited[num] = true;

    for(int i : v[num]) {
        if(!visited[i]) {
            ans[i] = num;
            solve(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, a, b;
    cin >> N;

    v.resize(N+1);
    ans.resize(N+1);
    visited.resize(N+1);
    for(int i = 0; i<N-1; ++i) {
        cin >> a;
        cin >> b;
        v[a].push_back(b); v[b].push_back(a);
    }

    solve();

    for(int i = 2; i<=N; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}