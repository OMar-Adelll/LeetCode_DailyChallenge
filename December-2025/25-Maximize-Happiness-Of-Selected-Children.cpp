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
    long long maximumHappinessSum(vector<int> &hap, int k)
    {
        sort(hap.rbegin(), hap.rend());
        long long sum = 0;
        for (int i = 0; i < k; i++)
            sum += max(0LL, (long long)hap[i] - i);

        return (long long)sum;
    }
};