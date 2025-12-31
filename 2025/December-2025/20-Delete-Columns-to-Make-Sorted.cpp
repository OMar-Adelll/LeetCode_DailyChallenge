// بسم الله الرحمن الرحيم
//  وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
//  Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(vec) (vec).begin(), (vec).end()
#define sz(x) (int)(x).size()
#define i(x) (x - 'a')
#define updmax(a, x) (a = max((a), (x)))
#define updmin(a, x) (a = min((a), (x)))
#define nl '\n'

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), cnt = 0;
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < n; j++) {
                if (strs[j][i] < strs[j - 1][i]) {
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
};