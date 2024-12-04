#include <iostream>
#include <vector>

#define N 140

using namespace std;

int main() {
    char puzzle[N][N];
    int c, i = 0, j = 0;
    while (true) {
        c = getchar();
        if (c == EOF)
            break;
        else if (c == '\n')
            ++i, j = 0;
        else
            puzzle[i][j++] = c;
    }

    const vector<pair<int, int>> dirs = {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
        {1, 0}, {1, -1}, {0, -1}, {-1, -1}
    };

    const char* const pattern = "XMAS";

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (puzzle[i][j] == pattern[0]) {
                for (auto [di, dj] : dirs) {
                    bool xmas = true;
                    for (int k = 1; k < 4; ++k) {
                        const int y = i + di * k, x = j + dj * k;
                        if (y < 0 || y == N || x < 0 || x == N || puzzle[y][x] != pattern[k]) {
                            xmas = false;
                            break;
                        }
                    }
                    ans += xmas;
                }
            }
        }
    }

    cout << ans << endl;
}
