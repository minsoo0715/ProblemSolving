#include <iostream>
#include <vector>
#define endl '\n';
using namespace std;
vector<int> coin;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K, cnt = 0;
    cin >> N >> K;
    coin.resize(N);
    for(int i = 0; i<N; ++i) {
        cin >> coin[i];
    }


    for(int i = N-1; i>=0; --i) {
        if(K < coin[i]) continue;
        if(K == 0) break;
        cnt += K / coin[i];
        K %= coin[i];
    }

    cout << cnt;


    
    return 0;
}