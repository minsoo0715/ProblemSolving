#include <iostream>
#include <vector>
#include <algorithm>

std::vector<bool> vec(10);
int input;
int len;
int min = -1;

void find(int k, int v, int e = 1) {
    if(k == len) {
        if(min < 0) {
            min = v;
            return;
        }

        int before = abs(input - min);
        int after = abs(input - v);

        if(after == before) { // 같은 경우 자리수가
            // 적은 게 더 유리함.
            min = std::min(v, min);
        } else if(after < before){
            min = v;
        }

        return;
    }

    if(vec[0]) {
        find(len, v);
    }

    for(int i = 0; i<10; ++i) {
        if(vec[i]) continue;
        find(k+1, v + i * e * 10, e * 10);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, broken;
    std::cin >> input >> N;


    for(int i = 0; i<N; ++i) {
        std::cin >> broken;
        vec[broken] = true;
    }

    if(input == 100) { // 이미 그 채널인 경우
        std::cout << 0;
        return 0;
    }

    if(N == 10) { // 숫자 버튼이 모두 없는 경우
        std::cout << abs(100-input);
        return 0;
    }

    len = std::to_string(input).length();

    if(N == 0) { // 모든 숫자를 다 쓸 수 있는 경우
        std::cout << std::min(abs(input - 100), len);
        return 0;
    }

    for(int i = 0; i<10; ++i) {
        if(vec[i]) continue;
        find(0, i);
    }

    int ans = std::min((int) std::to_string(min).length() + abs(input-min), abs(input - 100));
    if(!vec[0] && input+1 < ans) ans = input+1;
    std::cout << ans;
    return 0;
}