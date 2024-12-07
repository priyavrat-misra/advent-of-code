#include <iostream>

#define LEN 130

using namespace std;

enum Dir { N = 0, E, S, W };
const int dirs[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void step(char (*map)[LEN], int& i, int& j, Dir& dir) {
    for (int k = 0; k < 4; ++k) {
        int d = ((int) dir + k) % 4;
        i += dirs[d][0];
        j += dirs[d][1];
        if (map[i][j] != '#') {
            dir = (Dir) d;
            return;
        } else {
            i -= dirs[d][0];
            j -= dirs[d][1];
        }
    }
}

bool isCyclePresent(char (*map)[LEN], int i, int j) {
    int si = i, sj = j, fi = i, fj = j;
    Dir sdir = N, fdir = N;
    while (fi >= 0 && fi < LEN && fj >= 0 && fj < LEN) {
        step(map, si, sj, sdir);
        step(map, fi, fj, fdir), step(map, fi, fj, fdir);
        if (fi == si && fj == sj && fdir == sdir) { return true; }
    }
    return false;
}

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
    
    const int ti = si, tj = sj;

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
    for (i = 0; i < LEN; ++i) {
        for (j = 0; j < LEN; ++j) {
            if (map[i][j] == 'X' && (i != ti || j != tj)) {
                map[i][j] = '#';
                ans += isCyclePresent(map, ti, tj);
                map[i][j] = '.';
            }
        }
    }

    cout << ans << endl;
}
