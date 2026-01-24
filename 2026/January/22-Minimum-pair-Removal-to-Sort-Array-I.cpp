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
    int minimumPairRemoval(vector<int> &nums)
    {
        vector<int> vals(nums.begin(), nums.end());
        sort(vals.begin(), vals.end());
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != vals[i])
                cnt++;
        return cnt;
    }
};