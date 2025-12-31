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
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int n = sz(nums);
        int maxi = 0, CurrLen = 1, PrvLen = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                CurrLen++;
            }
            else
            {
                maxi = max({maxi, CurrLen / 2, min(PrvLen, CurrLen)});
                PrvLen = CurrLen;
                CurrLen = 1;
            }
        }

        maxi = max({maxi, CurrLen / 2, min(PrvLen, CurrLen)});
        return maxi;
    }
};

/*
    we have three conditions:
    [1] if all increasing then anwer will be maxlen / 2
    [2] if increasing but in point decreasing then increasing again then anawer will be min(inc1 , inc2)
    [3] all decreasing then answer will be 1

*/