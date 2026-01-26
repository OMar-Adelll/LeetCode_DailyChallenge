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
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> ans;
        int n = arr.size(), mn = INT_MAX;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++)
            mn = min(mn, arr[i] - arr[i - 1]);

        for (int i = 1; i < n; i++)
            if (arr[i] - arr[i - 1] == mn)
                ans.push_back({arr[i - 1], arr[i]});

        return ans;
    }
};