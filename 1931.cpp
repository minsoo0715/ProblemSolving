#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define endl '\n';
vector<pair<int, int>> c = vector<pair<int, int>>(100001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, cnt = 1, end;
    cin >> N;
    for(int i = 0; i<N; ++i) {

        cin >> c[i].first >> c[i].second;
    }

    sort(c.begin(), c.begin()+N, [](auto p1, auto p2) {
        if(p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    });

    end = c[0].second;

    for(int i = 1; i<N; ++i) {
        if(end <= c[i].first) {
            ++cnt;
            end = c[i].second;
        }
    }
    cout << cnt;
    return 0;
}