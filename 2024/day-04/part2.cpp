#include <iostream>

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

    int ans = 0;
    for (int i = 1; i < N - 1; ++i)
        for (int j = 1; j < N - 1; ++j)
            ans += (puzzle[i][j] == 'A')
                && (puzzle[i - 1][j - 1] == 'M' && puzzle[i + 1][j + 1] == 'S' || puzzle[i - 1][j - 1] == 'S' && puzzle[i + 1][j + 1] == 'M')
                && (puzzle[i - 1][j + 1] == 'M' && puzzle[i + 1][j - 1] == 'S' || puzzle[i - 1][j + 1] == 'S' && puzzle[i + 1][j - 1] == 'M');

    cout << ans << endl;
}
