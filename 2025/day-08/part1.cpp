#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

#define N 1000

using namespace std;

class DSU {
 private:
  vector<int> parent, size;

 public:
  DSU(int n): parent(n), size(n, 1) {
      iota(parent.begin(), parent.end(), 0);
  }

  int find(int u) {
      if (u == parent[u])
          return u;
      return parent[u] = find(parent[u]);
  }

  void unite(int u, int v) {
      int pu = find(u);
      int pv = find(v);
      if (pu == pv)
          return;
      if (size[pu] > size[pv]) {
          size[pu] += size[pv];
          parent[pv] = pu;
      } else {
          size[pv] += size[pu];
          parent[pu] = pv;
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
    for (int i = 0; i < N; ++i)
        dsu.unite(get<1>(dist[i]), get<2>(dist[i]));

    vector<int> sizes(n, 0);
    for (int i = 0; i < n; ++i)
        ++sizes[dsu.find(i)];

    nth_element(sizes.begin(), sizes.begin() + 2, sizes.end(), greater<int>{});
    cout << sizes[0] * sizes[1] * sizes[2] << endl;
}
