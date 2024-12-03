#include <iostream>
#include <regex>
using namespace std;

int main() {
    // (?:...): non-capturing group
    regex pattern("do(?:n't)?\\(\\)|mul\\(([0-9]{1,3}),([0-9]{1,3})\\)");
    sregex_iterator end;

    bool f = true;
    int ans = 0;
    string s;
    while (getline(cin, s)) {
        for (auto i = sregex_iterator(s.begin(), s.end(), pattern); i != end; ++i) {
            if (i -> str().size() == 4)  // "do()"
                f = true;
            else if (i -> str().size() == 7)  // "don't()"
                f = false;
            else if (f)
                ans += stoi(i -> str(1)) * stoi(i -> str(2));
        }
    }

    cout << ans << endl;
}
