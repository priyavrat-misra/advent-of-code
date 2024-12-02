#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    int a[1000], b[1000];
    while (cin >> a[i] >> b[i]) { ++i; }
    
    sort(a, a + 1000);
    sort(b, b + 1000);

    int ans = 0;
    for (i = 0; i < 1000; ++i) { ans += abs(a[i] - b[i]); }
    cout << ans << endl;
}
