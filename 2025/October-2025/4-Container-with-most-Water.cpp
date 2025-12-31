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
    int maxArea(vector<int> &H)
    {
        int n = sz(H);
        int l = 0, r = n - 1;
        int maxi = -1;
        while (l < r)
        {
            int height = min(H[l], H[r]);
            int width = r - l;
            updmax(maxi, height * width);
            if (H[l] < H[r])
                l++;
            else
                r--;
        }
        return maxi;
    }
};