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
    int minOperations(vector<int> &nums)
    {
        vector<int> ans;
        int cnt = 0;
        for (int a : nums)
        {
            while (!ans.empty() && ans.back() > a)
                ans.pop_back();

            if (a != 0 && (ans.empty() || ans.back() < a))
                cnt++, ans.push_back(a);
        }

        return cnt;
    }
};