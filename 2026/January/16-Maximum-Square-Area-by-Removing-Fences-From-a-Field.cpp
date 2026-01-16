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
    int maximizeSquareArea(int m, int n, vector<int> &h, vector<int> &v)
    {
        h.push_back(1), h.push_back(m), v.push_back(1), v.push_back(n);
        sort(h.begin(), h.end()), sort(v.begin(), v.end());
        set<int> lens;
        for (int i = 0; i < h.size(); i++)
            for (int j = i + 1; j < h.size(); j++)
                lens.insert(h[j] - h[i]);

        int mx = 0;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                int x = v[j] - v[i];
                if (lens.count(x))
                    mx = max(mx, x);
            }
        }

        if (mx == 0)
            return -1;

        long long Mod = 1e9 + 7;
        long long ans = (mx % Mod * mx % Mod) % Mod;
        return ans;
    }
};