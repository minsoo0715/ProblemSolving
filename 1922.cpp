#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> edges;
vector<int> costs;
vector<bool> connected;

int main() {
    int N, M;
    int n1, n2;
    int ans = 0;

    cin >> N >> M;

    connected.resize(N+1);
    fill(connected.begin(), connected.end(), false);
    costs.resize(M+1);
    edges.resize(M+1);


    for(int i = 1; i<=M; ++i) {
        cin >> n1 >> n2 >> costs[i];
        edges[i] = {n1, n2};
    }

    connected[1] = true;
    while(true) {
        int min = 10001;
        int k = -1, l = -1;
        for(int i = 0; i<edges.size(); ++i) {
            pair<int, int> e = edges[i];
            if(!connected[e.first] && !connected[e.second]) continue;
            if(connected[e.first] && connected[e.second]) continue;
            if(costs[i] < min) {
                min = costs[i];
                k = e.first;
                l = e.second;
            }
        }

        if(min == 10001) break; // 아무 노드도 선택되지 않은 경우 = 모든 노드가 연결된 경우
        ans += min;
        connected[k] = true;
        connected[l] = true;
    }

    cout << ans;
    return 0;
}