#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int mod = 1e9 + 7;
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (int &i : c) cin >> i;
  // ways(i) = number of ways to sum up to i
  vector<int> ways(x + 1);
  ways[0] = 1;
  for (int i = 1; i <= x; ++i) {
    for (int j = 0; j < n; ++j) {
      if (c[j] <= i) {
        ways[i] = (ways[i] + ways[i - c[j]]) % mod;
      }
    }
  }
  cout << ways[x];
}
