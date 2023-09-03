#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
using namespace std;
#define endl '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    int chk = 0, sum = 0;
    bool ck = false;
    cin >> str;

    for(int i = 0; i<str.length(); ++i) {
        if(str[i] == '-' || str[i] == '+') {
            int num = stoi(str.substr(chk, i));

            if(num < 0) {
                ck = true;
            }else if(ck) {
                num = -num;
            }
            sum += num;
            chk = i;
        }
    }
    int last_num = stoi(str.substr(chk, str.length()));
    sum += (ck && last_num > 0) ? -last_num : last_num;
    cout << sum;
    
    return 0;
}