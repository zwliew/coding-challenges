#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
string to_string(char c) { return string(1, c); }
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
  return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " +
         to_string(get<2>(t)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) {
  return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " +
         to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += '}';
  return res;
}

void _debug() { cerr << '\n'; }
template <typename Head, typename... Tail>
void _debug(Head H, Tail... T) {
  cerr << ' ' << to_string(H);
  _debug(T...);
}
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", _debug(__VA_ARGS__)
#else
#define debug(...) 0
#endif

#define eb emplace_back

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vc = vector<char>;
using vb = vector<bool>;
using vll = vector<ll>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  int n, x;
  cin >> n >> x;
  --x;
  vector<vi> adj(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int w;
      cin >> w;
      if (w) {
        adj[i].eb(j);
      }
    }
  }

  vi dist(n, INT_MAX);
  dist[x] = 0;
  queue<int> q;
  q.emplace(x);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (dist[v] == INT_MAX) {
        dist[v] = dist[u] + 1;
        q.emplace(v);
      }
    }
  }

  for (int d : dist) {
    if (d == INT_MAX)
      cout << -1;
    else
      cout << d;
    cout << ' ';
  }
}
