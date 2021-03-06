#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
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

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    int n;
    cin >> n;
    int lastWin = -1;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
      char c;
      cin >> c;
      if (c == 'W') {
        lastWin = i;
      }
      if (ans == -1 && i - lastWin == 3) {
        ans = i + 1;
      }
    }
    cout << "Case " << ti << ": ";
    if (ans != -1) {
      cout << ans << "\n";
    } else {
      cout << "Yay! Mighty Rafa persists!\n";
    }
  }
}
