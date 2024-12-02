#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool greater_equal_3(int l, int r) { return l >= r || r - l > 3; }

bool less_equal_3(int l, int r) { return l <= r || l - r > 3; }

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

        // +1 if strictly increasing/decreasing with max diff 3
        safe += adjacent_find(lvls.begin(), lvls.end(), greater_equal_3) == lvls.end();
        safe += adjacent_find(lvls.begin(), lvls.end(), less_equal_3) == lvls.end();
    }

    cout << safe << endl;
}
