#include <iostream>
#include <vector>
using namespace std;
#define endl '\n';

vector<vector<int> > box = vector<vector<int> >(128, vector<int>(128));
vector<int> cnt = vector<int>(2);

int cut(int N, int x = 0, int y = 0) {
    int sum = 0;
    bool chk = true;

    if(N == 1) {
        ++cnt[box[x][y]];
        return box[x][y];
    }
    for(int _x = x; _x <= N/2+x; _x += N/2) {
        for(int _y = y; _y <= N/2+y; _y += N/2) {
            int tmp = cut(N/2, _x, _y);
            if(tmp >= 0) sum += tmp;
            else chk = false;
        }
    }

    if(chk && (sum == 0 || sum == 4)) {
        cnt[sum / 4] -= 3;
        return sum / 4;
    }else {
        return -1;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    for(int i = 0; i<N; ++i) {
        for(int j = 0; j<N; ++j) {
            cin >> box[i][j];
        }
    }
    cut(N);
    cout << cnt[0] << '\n' << cnt[1];
    return 0;
}

