#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define endl '\n';

vector<long> price = vector<long>(100000);
vector<long> d = vector<long>(100000);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    long sum = 0, min = 1000000001L;
    cin >> N;

    for(int i = 0; i<N-1; ++i)
        cin >> d[i];

    for(int i = 0; i<N-1; ++i) {
        cin >> price[i];
        min = std::min(min, price[i]);
        sum += d[i] * std::min(min, price[i]);
    }

    cin >> price[N-1];

    cout << sum;
    return 0;
}