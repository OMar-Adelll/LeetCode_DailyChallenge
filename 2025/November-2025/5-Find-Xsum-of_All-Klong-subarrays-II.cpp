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

struct Data
{
    int frequency;
    int val;
    bool operator<(const Data &x) const
    {
        if (frequency != x.frequency)
            return frequency < x.frequency;
        return val < x.val;
    }
    bool operator>(const Data &x) const
    {
        if (frequency != x.frequency)
            return frequency > x.frequency;
        return val > x.val;
    }
};

class Solution
{
public:
    unordered_map<int, ll> freq;
    set<Data, greater<Data>> mx, mn;
    ll cursum = 0;

    void in(int v, int x)
    {
        int fr = freq[v];
        if (fr > 0)
        {
            Data d = {fr, v};
            auto it = mx.find(d);
            if (it != mx.end())
                mx.erase(it), cursum -= (ll)(fr) * (v);
            else
                mn.erase(d);
        }

        freq[v]++;

        Data d = {fr + 1, v};
        mx.insert(d);
        cursum += (ll)(fr + 1) * (v);

        if (sz(mx) > x)
        {
            auto it = prev(mx.end());
            cursum -= (ll)(it->frequency) * (it->val);
            mn.insert(*it), mx.erase(*it);
        }
    }

    void out(int v, int x)
    {
        int fr = freq[v];
        if (!fr)
            return;

        Data d = {fr, v};
        auto it = mx.find(d);
        if (it != mx.end())
            mx.erase(it), cursum -= (ll)(fr) * (v);
        else
            mn.erase(d);

        freq[v]--;
        if (!freq[v])
            freq.erase(v);
        else
            mn.insert({fr - 1, v});

        if (sz(mx) < x && !mn.empty())
        {
            auto it = mn.begin();
            mx.insert(*it);
            cursum += (ll)(it->frequency) * (it->val);
            mn.erase(it);
        }
    }

    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        int n = sz(nums), len = n - k + 1;
        if (n == 0 || k == 0)
            return {};

        vector<ll> ans(len);
        for (int i = 0; i < k; i++)
            in(nums[i], x);

        ans[0] = cursum;

        for (int l = 1, r = k; r < n; r++, l++)
            out(nums[l - 1], x), in(nums[r], x), ans[l] = cursum;

        return ans;
    }
};