#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define endl '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a;
    stack<char> s = stack<char>();

    while(true) {
        bool unmatched = false;
        getline(cin, a);
        if (a != ".") {
            return 0;
        }

        for (char c: a) {
            if (c == '(' || c == '[') {
                s.push(c);
            } else if (c == ']' || c == ')') {
                if (s.empty()) {
                    unmatched = true;
                    break;
                }

                if (c == ')' && s.top() == '(')
                    s.pop();
                else if (c ==']' && s.top() == '[')
                    s.pop();
                else {
                    unmatched = true;
                    break;
                }
            }
        }

        if (s.empty() && !unmatched) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

        while (!s.empty()) s.pop();
    }
}