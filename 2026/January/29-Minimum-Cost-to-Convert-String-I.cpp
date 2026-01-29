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

#define OO 1e18
class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {

        vector<vector<long long>> dist(26, vector<long long>(26, OO));

        for (int i = 0; i < 26; i++)
            dist[i][i] = 0;

        for (int i = 0; i < changed.size(); i++)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int i = 0; i < 26; i++)
        {
            for (int u = 0; u < 26; u++)
            {
                for (int v = 0; v < 26; v++)
                {
                    if (dist[u][i] < OO && dist[i][v] < OO)
                        dist[u][v] = min(dist[u][v], dist[u][i] + dist[i][v]);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < target.size(); i++)
        {
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (dist[s][t] == OO)
                return -1;
            ans += dist[s][t];
        }

        return ans;
    }
};