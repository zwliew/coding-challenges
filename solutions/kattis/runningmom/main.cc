#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "mootube"
#endif

unordered_map<string, int> vis;
unordered_map<string, vector<string>> adj;

bool dfs(string u) {
  vis[u] = 1;
  for (auto& v : adj[u]) {
    if (!vis[v] && dfs(v)) {
      return true;
    } else if (vis[v] == 1) {
      return true;
    }
  }
  vis[u] = 2;
  return false;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  string s;
  while (cin >> s) {
    vis.clear();
    cout << s << " ";
    if (dfs(s)) {
      cout << "safe";
    } else {
      cout << "trapped";
    }
    cout << '\n';
  }
}
