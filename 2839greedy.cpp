#include <iostream>
#define endl '\n';
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    for(int i = N/5; i>=0; --i) {
        if((N - i*5) % 3 == 0) {
            cout << (N - i * 5) / 3 + i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}