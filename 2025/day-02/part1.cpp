#include <iostream>
#include <cmath>
using namespace std;

int main() {
    char _; // '-', ','
    long long i, j, ans = 0;
    while (cin >> i >> _ >> j) {
        int digits = log10(i) + 1;
        if (digits % 2)
            i = pow(10, digits), ++digits;
        long long k = pow(10, digits);
        long long h = pow(10, digits / 2);
        while (true) {
            while (i <= j && i < k) {
                if (i / h == i % h)
                    ans += i, i += h; // 123123 -> 124123 (next match 124124)
                ++i;
            }
            if (i >= j)
                break;
            else
                h = i *= 10, k = i * 10;
        }
        cin >> _; // ','
    }
    cout << ans << endl;
}
