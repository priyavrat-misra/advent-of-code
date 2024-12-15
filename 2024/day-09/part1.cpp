#include <iostream>
using namespace std;

int main() {
    string disk;
    getline(cin, disk);

    long long ans = 0, acc = 0;
    const int len = disk.size();
    int fid = 0, lid = len / 2;
    int i = 0, j = len - 1;
    while (i <= j) {
        int n = disk[i] - '0';
        if (i % 2 == 0) {
            ans += (n * acc + (n * (n - 1)) / 2) * fid;
            acc += n;
            ++fid, ++i;
        } else {
            int m = disk[j] - '0';
            if (m > n) {
                ans += (n * acc + (n * (n - 1)) / 2) * lid;
                disk[j] -= n;
                acc += n;
                ++i;
            } else {
                ans += (m * acc + (m * (m - 1)) / 2) * lid;
                disk[i] -= m;
                acc += m;
                i += m == n;
                --lid, j -= 2;
            }
        }
    }

    cout << ans << endl;
}
