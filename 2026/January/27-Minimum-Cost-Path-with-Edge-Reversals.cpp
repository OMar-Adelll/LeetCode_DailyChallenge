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

#define OO INT_MAX
class Solution
{

    vector<int> Dijkstra(vector<vector<pair<int, int>>> &adj)
    {
        int n = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        pq.push({0, 0});
        dist[0] = 0;
        while (!pq.empty())
        {
            auto [cst, u] = pq.top();
            pq.pop();

            if (cst > dist[u])
                continue;

            for (auto &[node, cst] : adj[u])
            {
                if (dist[u] != INT_MAX && dist[u] + cst < dist[node])
                {
                    dist[node] = dist[u] + cst;
                    pq.push({dist[node], node});
                }
            }
        }

        return dist;
    }

public:
    int minCost(int n, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int c = edges[i][2];

            adj[u].push_back({v, c});
            adj[v].push_back({u, 2 * c});
        }

        vector<int> ans = Dijkstra(adj);
        return (ans[n - 1] == INT_MAX ? -1 : ans[n - 1]);
    }
};