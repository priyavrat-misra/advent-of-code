#include <iostream>

#define LEN 130

using namespace std;

int main() {
    char map[LEN][LEN];
    int place, i = 0, j = 0, si, sj;
    while (true) {
        place = getchar();
        if (place == '.' || place == '#')
            map[i][j++] = place;
        else if (place == '\n')
            ++i, j = 0;
        else if (place == '^')
            si = i, sj = j++;
        else
            break;
    }

    enum Dir { N, E, S, W };

    Dir dir = N;
    while (si >= 0 && si < LEN && sj >= 0 && sj < LEN) {
        switch (dir) {
            case N:
                while (si >= 0 && map[si][sj] != '#') { map[si--][sj] = 'X'; }
                if (si >= 0) { ++si, ++sj, dir = E; }
                break;
            case E:
                while (sj < LEN && map[si][sj] != '#') { map[si][sj++] = 'X'; }
                if (sj < LEN) { --sj, ++si, dir = S; }
                break;
            case S:
                while (si < LEN && map[si][sj] != '#') { map[si++][sj] = 'X'; }
                if (si < LEN) { --si, --sj, dir = W; }
                break;
            case W:
                while (sj >= 0 && map[si][sj] != '#') { map[si][sj--] = 'X'; }
                if (sj >= 0) { ++sj, --si, dir = N; }
                break;
        }
    }

    int ans = 0;
    for (i = 0; i < LEN; ++i)
        for (j = 0; j < LEN; ++j)
            ans += map[i][j] == 'X';

    cout << ans << endl;
}
