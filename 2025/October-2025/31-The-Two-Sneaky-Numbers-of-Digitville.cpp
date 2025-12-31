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

class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        int n = sz(nums);
        vector<bool> vis(n, 0);
        vector<int> rt(2);
        int idx = 0;
        for (auto &c : nums)
            if (!vis[c])
                vis[c] = 1;
            else
                rt[idx] = c, idx++;

        return rt;
    }
};