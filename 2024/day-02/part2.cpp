#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool gte_3(int l, int r) { return l >= r || r - l > 3; }

bool lte_3(int l, int r) { return l <= r || l - r > 3; }

int main() {
    int safe = 0;
    string s;
    stringstream ss;
    while (getline(cin, s)) {
        ss.clear();
        ss.str(s);
        
        int lvl;
        vector<int> lvls;
        while (ss >> lvl) { lvls.push_back(lvl); }

        vector<int>::iterator l, b = lvls.begin(), e = lvls.end();

        // check if safe by removing the current or the next level
        if ((l = adjacent_find(b, e, gte_3)) >= e - 2)
            ++safe;
        else if (adjacent_find(l + 2, e, gte_3) == e)
            safe += !gte_3(*l, *(l + 2)) || (l == b || !gte_3(*(l - 1), *(l + 1))) && !gte_3(*(l + 1), *(l + 2));

        if ((l = adjacent_find(b, e, lte_3)) >= e - 2)
            ++safe;
        else if (adjacent_find(l + 2, e, lte_3) == e)
            safe += !lte_3(*l, *(l + 2)) || (l == b || !lte_3(*(l - 1), *(l + 1))) && !lte_3(*(l + 1), *(l + 2));
    }

    cout << safe << endl;
}
