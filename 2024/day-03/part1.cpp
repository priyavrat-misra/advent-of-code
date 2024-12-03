#include <iostream>
#include <regex>
using namespace std;

int main() {
    // (...): capturing group
    regex pattern("mul\\(([0-9]{1,3}),([0-9]{1,3})\\)");
    sregex_iterator end;

    int ans = 0;
    string s;
    while (getline(cin, s))
        for (auto i = sregex_iterator(s.begin(), s.end(), pattern); i != end; ++i)
            ans += stoi(i -> str(1)) * stoi(i -> str(2));

    cout << ans << endl;
}
