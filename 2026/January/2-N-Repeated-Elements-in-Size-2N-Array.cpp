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
    int repeatedNTimes(vector<int> &nums)
    {
        int f = nums.size() / 2;
        vector<int> v(1e5, 0);
        for (auto &c : nums)
            v[c]++;

        for (auto &c : nums)
            if (v[c] == f)
                return c;
        return 0;
    }
};