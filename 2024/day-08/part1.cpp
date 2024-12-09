#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define LEN 50

using namespace std;

inline bool isInsideBounds(int x, int y) {
    return x >= 0 && x < LEN && y >= 0 && y < LEN;
}

int main() {
    int c, i = 0, j = 0;
    unordered_map<char, vector<pair<int, int>>> m;
    while (true) {
        c = getchar();
        if (c == '.')
            ++j;
        else if (isalnum(c))
            m[c].push_back({i, j++});
        else if (c == '\n')
            ++i, j = 0;
        else
            break;
    }

    unordered_set<int> antinodes;
    for (auto& [_, positions] : m) {
        int n = positions.size();
        if (n > 1) {
            for (int i = 0; i < n; ++i) {
                auto [idx, idy] = positions[i];
                for (int j = i + 1; j < n; ++j) {
                    auto [jdx, jdy] = positions[j];
                    int dx = idx - jdx, dy = idy - jdy;
                    if (isInsideBounds(idx + dx, idy + dy)) { antinodes.insert((idx + dx) * LEN + idy + dy); }
                    if (isInsideBounds(jdx - dx, jdy - dy)) { antinodes.insert((jdx - dx) * LEN + jdy - dy); }
                }
            }
        }
    }

    cout << antinodes.size() << endl;
}
