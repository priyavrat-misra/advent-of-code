#include <iostream>
#include <vector>
using namespace std;

int main() {
    string disk;
    getline(cin, disk);

    int len = disk.size();
    vector<uint64_t> idx(len + 1);
    idx[0] = 0;
    for (int i = 1; i <= len; ++i)
        idx[i] = idx[i - 1] + disk[i - 1] - '0';

    int no_space = 0;
    uint64_t ans = 0;
    for (int j = len - 1; j >= 0; j -= 2) {
        int m = disk[j] - '0';
        if (no_space & (1 << (9 - m))) {
            ans += (m * idx[j] + (m * (m - 1)) / 2) * (j / 2); 
        } else {
            bool space = false;
            for (int i = 1; i < j; i += 2) {
                int n = disk[i] - '0';
                if (n < m) {
                    continue;
                } else {
                    space = true;
                    ans += (m * idx[i] + (m * (m - 1)) / 2) * (j / 2); 
                    idx[i] += m;
                    disk[i] -= m;
                    break;
                }
            }

            if (!space) {
                ans += (m * idx[j] + (m * (m - 1)) / 2) * (j / 2); 
                no_space |= (1 << (10 - m)) - 1;
            }
        }
    }

    cout << ans << endl;
}
