#include <iostream>
#include <vector>
#define endl '\n';

using namespace std;

vector<int> v = vector<int>(100000);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    int M;
    cin >> N >> M;
    
    for(int i = 1; i<=N; ++i) {
        cin >> v[i];
        if(i > 1) {
            v[i] += v[i-1];
        }
    }

    for(int i = 1; i<=M; ++i) {
        int m, n;
        cin >> m >> n;
        cout << v[n] - v[m-1] << endl;
    }
    return 0;
}