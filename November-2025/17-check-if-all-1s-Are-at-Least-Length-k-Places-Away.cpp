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
    bool kLengthApart(vector<int> &nums, int k)
    {
        int n = nums.size(), prv = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] && prv == -1)
            {
                prv = i;
            }
            else if (nums[i])
            {
                if (i - prv - 1 < k)
                    return false;
                prv = i;
            }
        }

        return true;
    }
};