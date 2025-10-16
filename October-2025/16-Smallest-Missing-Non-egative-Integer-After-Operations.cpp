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
    int Safe_Mod(int x, int M)
    {
        return ((x % M) + M) % M;
    }
    int findSmallestInteger(vector<int> &nums, int value)
    {
        int n = sz(nums);
        vector<int> freq(value, 0);
        for (int i = 0; i < n; i++)
        {
            int x = Safe_Mod(nums[i], value);
            freq[x]++;
        }

        vector<int> found;
        for (int i = 0; i < value; i++)
        {
            int pos = 0;
            while (freq[i]--)
            {
                int x = i + (pos * value);
                found.push_back(x);
                pos++;
            }
        }
        sort(all(found));
        int maxi = found.back(), i = 0;
        for (; i <= maxi; i++)
            if (i != found[i])
                break;

        return i;
    }
};