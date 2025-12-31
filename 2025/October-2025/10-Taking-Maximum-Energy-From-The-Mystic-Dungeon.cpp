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
    int maximumEnergy(vector<int> &energy, int k)
    {
        int n = sz(energy);
        vector<int> sums(k, 0);
        int maxi = -1e9;
        for (int i = n - 1; i >= 0; i--)
        {
            sums[i % k] += energy[i];
            updmax(maxi, sums[i % k]);
        }

        return maxi;
    }
};