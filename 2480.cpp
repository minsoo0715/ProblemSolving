#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;

    if(a == b && b == c) {
        cout << 10000 + a * 1000;
    }else if(a == b || b == c || a == c) {
        cout << 1000 + (a == b ? a : b == c ? b : a == c ? c : 0) * 100;
    }else {
        cout << max(max(a,b), c) * 100;
    }
    return 0;
}