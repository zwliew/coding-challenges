/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  long long n;
  cin >> n;
  if (n <= 2) {
    cout << -1;
  } else if (n % 2) {
    cout << (n * n - 1) / 2 << ' ' << (n * n + 1) / 2;
  } else {
    cout << n * n / 4 - 1 << ' ' << n * n / 4 + 1;
  }
}
