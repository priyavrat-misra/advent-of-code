#include <functional>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    unordered_map<int, unordered_set<int>> m;
    string rule;
    while (getline(cin, rule) && rule[0]) {
        const int pipe = rule.find('|');
        m[stoi(rule.substr(0, pipe))].insert(stoi(rule.substr(pipe + 1)));
    }
    
    int ans = 0;
    string s;
    stringstream ss;
    while(getline(cin, s)) {
        ss.clear();
        ss.str(s);

        vector<int> update;
        int page;
        while (ss >> page) {
            update.push_back(page);
            ss.ignore(1);
        }

        int n = update.size();
        bool correct = true;
        for (int i = n - 1; i && correct; --i) {
            if (m.count(update[i])) {
                for (int j = 0; j < i; ++j) {
                    if (m[update[i]].count(update[j])) {
                        correct = false;
                        break;
                    }
                }
            }
        }

        if (!correct) {
            unordered_set<int> unvisited(update.begin(), update.end());
            vector<int> sorted(n);
            int last = n - 1;

            function<void(int)> dfs = [&](int node) {
                unvisited.erase(node);
                if (m.count(node))
                    for (int neighbor : m[node])
                        if (unvisited.count(neighbor))
                            dfs(neighbor);

                sorted[last--] = node;
            };

            for (int page : update)
                if (unvisited.count(page))
                    dfs(page);

            ans += sorted[n / 2];
        }
    }

    cout << ans << endl;
}
