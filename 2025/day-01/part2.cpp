#include <iostream>
using namespace std;

int main() {
    char dir;
    int val, ans = 0, dial = 50;
    while (cin >> dir >> val) {
        if (dir == 'L') {
            ans -= dial == 0;
            dial -= val;
            ans += (dial <= 0) + abs(dial / 100);
            dial = (dial % 100 + 100) % 100;
        } else {
            dial += val;
            ans += dial / 100;
            dial %= 100;
        }
    }

    cout << ans << endl;
}
