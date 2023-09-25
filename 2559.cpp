#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n';
vector<int> s = vector<int>(100001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    
    for(int i = 1; i<=N; ++i) {
        cin >> s[i];
        s[i] += s[i-1];
    }
    int mx = -10000001;
    for(int i = K; i <= N; ++i) {
        mx = max(mx, s[i]-s[i-K]);
        
    }

    cout << mx;




    return 0;
}