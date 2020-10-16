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
  for (int ti = 0; ti < t; ++ti) {
    if (ti) {
      cout << "\n";
    }
    int w;
    cin >> w;
    int diff = INT_MIN;
    bool ok = true;
    while (w--) {
      int t, b;
      cin >> t >> b;
      if (diff != INT_MIN && t - b != diff) {
        ok = false;
      }
      diff = t - b;
    }

    if (ok) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
}
