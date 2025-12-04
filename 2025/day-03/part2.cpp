#include <iostream>
using namespace std;

int main() {
    string s;
    long long ans = 0;
    while (cin >> s) {
        long long joltage = 0;
        int n = s.size(), i = 0;
        // take greatest from left
        // while having enough to right
        for (int k = 11; k >= 0; --k) {
            char c = '0';
            int w = n - k;
            for (int j = i; j < w; ++j)
                if (s[j] > c)
                    c = s[j], i = j + 1;
            joltage = joltage * 10 + (c - '0');
        }
        ans += joltage;
    }
    cout << ans << endl;
}
