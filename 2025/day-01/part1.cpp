#include <iostream>
using namespace std;

int main() {
    char dir;
    int val, ans = 0, dial = 50;
    while (cin >> dir >> val) {
        val *= (dir == 'L' ? -1 : 1);
        dial = ((dial + val) % 100 + 100) % 100;
        ans += dial == 0;
    }

    cout << ans << endl;
}
