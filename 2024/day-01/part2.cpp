#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int i = 0;
    int a[1000], b;
    unordered_map<int, int> f;
    while (cin >> a[i++] >> b) { ++f[b]; }

    int ans = 0;
    for (int e : a)
        if (f.count(e))
            ans += e * f[e];

    cout << ans << endl;
}
