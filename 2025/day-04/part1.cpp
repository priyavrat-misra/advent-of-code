#include <iostream>

#define N 135

using namespace std;

int main() {
    bool rolls[N][N]{};
    int c, i = 0, j = 0;
    while (true) {
        c = getchar();
        if (c == EOF)
            break;
        else if (c == '\n')
            ++i, j = 0;
        else
            rolls[i][j++] = c == '@';
    }

    const int dirs[][2] = {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
        {1, 0}, {1, -1}, {0, -1}, {-1, -1}
    };

    int ans = 0;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (!rolls[i][j])
                continue;
            c = 0;
            for (auto [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < N && nj >= 0 && nj < N)
                    c += rolls[ni][nj];
            }
            ans += c < 4;
        }
    }
    cout << ans << endl;
}
