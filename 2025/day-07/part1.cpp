#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int i = 0, ans = 0;
    unordered_set<int> s;
    while (true) {
        switch (getchar()) {
            case '.':
                ++i;
                break;
            case '^':
                ++i;
                if (s.count(i)) {
                    ++ans;
                    s.erase(i);
                    s.insert(i - 1);
                    s.insert(i + 1);
                }
                break;
            case '\n':
                i = 0;
                break;
            case 'S':
                s.insert(++i);
                break;
            case EOF:
                cout << ans << endl;
                return EXIT_SUCCESS;
        }
    }
}
