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

#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", _debug(__VA_ARGS__)
#else
#define debug(...) 0
#endif

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

#define eb emplace_back

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vc = vector<char>;
using vb = vector<bool>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

  // Dynamic range sum query. Use a binary indexed tree with r + m elements.
  // First r elements empty, last m elements populated from 1 through m. Every
  // time an element is retrieved, move it to the front of all the other
  // elements in the tree.
  int t;
  cin >> t;
  while (t--) {
    int m, r;
    cin >> m >> r;

    vi pos(m + 1);
    iota(pos.begin(), pos.end(), r - 1);

    vi bit(r + m + 1);
    auto update = [&](int idx, int val) {
      for (++idx; idx <= r + m; idx += idx & -idx) {
        bit[idx] += val;
      }
    };
    auto query = [&](int idx) {
      int ans = 0;
      for (++idx; idx; idx -= idx & -idx) {
        ans += bit[idx];
      }
      return ans;
    };
    for (int i = r; i <= r + m; ++i) update(i, 1);

    int next = r - 1;
    for (int i = 0; i < r; ++i) {
      int x;
      cin >> x;
      cout << query(pos[x] - 1) << ' ';
      update(pos[x], -1);
      update(next, 1);
      pos[x] = next;
      next--;
    }
    cout << '\n';
  }
}
