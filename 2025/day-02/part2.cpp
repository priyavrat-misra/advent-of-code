#include <iostream>
#include <regex>
using namespace std;

int main() {
    char _;
    long long i, j, ans = 0;
    regex pattern("(\\d+)\\1+");
    while (cin >> i >> _ >> j) {
        while (i <= j) {
            if (regex_match(to_string(i), pattern))
                ans += i;
            ++i;
        }
        cin >> _;
    }
    cout << ans << endl;
}
