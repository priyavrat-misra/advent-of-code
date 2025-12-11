#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

using namespace std;

class DSU {
 private:
  const int n;
  vector<int> parent, size;

 public:
  DSU(int n): n(n), parent(n), size(n, 1) {
      iota(parent.begin(), parent.end(), 0);
  }

  int find(int u) {
      if (u == parent[u])
          return u;
      return parent[u] = find(parent[u]);
  }

  bool unite(int u, int v) {
      int pu = find(u);
      int pv = find(v);
      if (pu == pv)
          return false;
      if (size[pu] > size[pv]) {
          parent[pv] = pu;
          return (size[pu] += size[pv]) == n;
      } else {
          parent[pu] = pv;
          return (size[pv] += size[pu]) == n;
      }
  }
};

inline long long edist(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    auto& [xa, ya, za] = a;
    auto& [xb, yb, zb] = b;
    return 1ll * (xa - xb) * (xa - xb) + 1ll * (ya - yb) * (ya - yb) + 1ll * (za - zb) * (za - zb);
}

int main() {
    char _;
    int x, y, z;
    vector<tuple<int, int, int>> coords;
    while (cin >> x >> _ >> y >> _ >> z)
        coords.emplace_back(x, y, z);

    int n = coords.size();
    vector<tuple<long long, int, int>> dist;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            dist.emplace_back(edist(coords[i], coords[j]), i, j);

    sort(dist.begin(), dist.end());

    DSU dsu(n);
    int i = 0;
    while (!dsu.unite(get<1>(dist[i]), get<2>(dist[i])))
        ++i;

    cout << get<0>(coords[get<1>(dist[i])]) * get<0>(coords[get<2>(dist[i])]) << endl;
}
