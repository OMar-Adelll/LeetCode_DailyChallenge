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
    int maxDistinctElements(vector<int> &nums, int k)
    {
        int n = sz(nums);
        sort(all(nums));
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = nums[i] - k;

        for (int i = 1; i < n; i++)
        {

            a[i] = max(a[i], a[i - 1] + 1);
            if (a[i] > nums[i] + k)
                a[i] = nums[i] + k;
        }

        set<int> st(all(a));
        return sz(st);
    }
};
