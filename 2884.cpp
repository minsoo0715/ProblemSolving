#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, m;
    cin >> h >> m;

    m = h*60 + m - 45;
    if(m < 0) {
        m += 24*60;
    }

    cout << m / 60 << ' ' << m % 60;
    return 0;
}