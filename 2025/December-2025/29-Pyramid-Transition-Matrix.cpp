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

#define sz(x) x.size()
class Solution
{
    unordered_map<string, bitset<10>> M;

public:
    string sample;
    vector<string> options;
    bool go(int idx, string curr = "", string nxt = "")
    {
        if (sz(curr) == 1)
            return true;
        if (idx == sz(curr) - 1)
            return go(0, nxt);
        string ans = {curr[idx], curr[idx + 1]};
        if (M[ans].none())
            return false;

        for (int i = 0; i < 6; i++)
        {
            if (!M[ans][i])
                continue;

            if (go(idx + 1, curr, nxt + static_cast<char>(i + 'A')))
                return true;
        }

        return false;
    }

    void clear()
    {
        for (auto &[s, v] : M)
            v.reset();
    }

    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        clear();
        for (int i = 0; i < sz(allowed); i++)
        {
            string MAP = {allowed[i][0], allowed[i][1]};
            M[MAP][allowed[i][2] - 'A'] = true;
        }
        return go(0, bottom, "");
    }
};