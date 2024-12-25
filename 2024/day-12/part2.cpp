#include <iostream>
#include <vector>

#define LEN (3 * 140) // x 3 to detect corners

using namespace std;

vector<vector<pair<char, bool>>> garden(LEN, vector<pair<char, bool>>(LEN)); // {plant, isCorner}
bool visited[LEN][LEN]{false};
const int dirs[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const int allDirs[][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}};

void dfs(int i, int j, int& area, int& corners) {
    visited[i][j] = true;
    ++area;
    corners += garden[i][j].second;
    for (auto [di, dj] : dirs) {
        int ni = i + di, nj = j + dj;
        if (ni >= 0 && ni < LEN && nj >= 0 && nj < LEN && !visited[ni][nj] && garden[ni][nj].first == garden[i][j].first)
            dfs(ni, nj, area, corners);
    }
}

int calcPrice(int i, int j) {
    int area = 0, corners = 0;
    dfs(i, j, area, corners);
    return (area / 9) * corners;
}

int main() {
    int c, i = 0, j = 0;
    while (true) {
        c = getchar();
        if (c == '\n') {
            ++i, j = 0;
        } else if (c == EOF) {
            break;
        } else {
            for (int di = 0; di < 3; ++di)
                for (int dj = 0; dj < 3; ++dj)
                    garden[3 * i + di][3 * j + dj] = make_pair(c, false);
            ++j;
        }
    }

    for (i = 0; i < LEN; ++i) {
        for (j = 0; j < LEN; ++j) {
            for (int d = 0; d < 4; ++d) {
                int hash = 0;
                for (int k = 0, p = 1; k < 3; ++k, p *= 3) {
                    auto [di, dj] = allDirs[d * 2 + k];
                    int ni = i + di, nj = j + dj;
                    hash += (ni >= 0 && ni < LEN && nj >= 0 && nj < LEN && garden[ni][nj].first == garden[i][j].first) * p;
                }
                if (hash == 0 || hash == 3 || hash == 10) {
                    garden[i][j].second = true;
                    break;
                }
            }
        }
    }

    int ans = 0;
    for (i = 0; i < LEN; ++i)
        for (j = 0; j < LEN; ++j)
            if (!visited[i][j])
                ans += calcPrice(i, j);

    cout << ans << endl;
}
