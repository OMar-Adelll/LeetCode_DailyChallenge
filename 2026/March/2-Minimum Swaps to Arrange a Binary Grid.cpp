// بسم الله الرحمن الرحيم
//  وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
//  Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define i(x) (x - 'a')
#define nl '\n'
#define sz(x) (int)(x).size()
#define updmax(a, x) (a = max((a), (x)))
#define updmin(a, x) (a = min((a), (x)))
#define all(vec) (vec).begin(), (vec).end()

class Solution {
public:
  int minSwaps(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<int> Max(n);
    for (int i = 0; i < n; i++) {
      int mx = -1;
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1)
          mx = j;
      }

      Max[i] = n - mx - 1;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int cur = n - i - 1;
      int idx = i;

      while (idx < n && Max[idx] < cur)
        idx++;
      if (idx == n)
        return -1;
      while (idx > i) {
        swap(Max[idx], Max[idx - 1]);
        idx--;
        cnt++;
      }
    }

    return cnt;
  }
};