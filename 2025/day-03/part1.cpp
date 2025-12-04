#include <iostream>
using namespace std;

int main() {
    string s;
    int ans = 0;
    while (cin >> s) {
        int joltage = 0;
        int n = s.size();
        char mx = s[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            joltage = max(joltage, (s[i] - '0') * 10 + (mx - '0'));
            mx = max(mx, s[i]);
        }
        ans += joltage;
    }
    cout << ans << endl;
}
