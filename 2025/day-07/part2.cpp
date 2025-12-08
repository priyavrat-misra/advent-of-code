#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int i = 0;
    unordered_map<int, long long> s;
    while (true) {
        switch (getchar()) {
            case '.':
                ++i;
                break;
            case '^':
                if (s.count(++i)) {
                    s[i - 1] += s[i];
                    s[i + 1] += s[i];
                    s.erase(i);
                }
                break;
            case '\n':
                i = 0;
                break;
            case 'S':
                ++s[++i];
                break;
            case EOF:
                long long ans = 0;
                for (const auto& [_, v] : s)
                    ans += v;
                cout << ans << endl;
                return EXIT_SUCCESS;
        }
    }
}
