#include <iostream>
#define endl '\n';
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio;
    string s;
    getline(cin, s);
    int cnt = 0, len = s.length();
    for(int i = 0; i<len; ++i) {
        if(s[i] == ' ') ++cnt;
    }

    if(s[0] == ' ' && s[len-1] == ' ') {
        cnt += -1;
    }else if(s[0] != ' ' && s[len-1] != ' ') {
        cnt += 1;
    }
    cout << cnt;
    return 0;
}