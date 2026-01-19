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
    vector<vector<int>> prefix;
    void build_prefix(const vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        prefix.assign(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefix[i][j] = matrix[i][j];

                if (i > 0)
                    prefix[i][j] += prefix[i - 1][j];
                if (j > 0)
                    prefix[i][j] += prefix[i][j - 1];
                if (i > 0 && j > 0)
                    prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
    }
    int Two_D_prefix(int x1, int y1, int x2, int y2)
    {
        int res = prefix[x2][y2];

        if (x1 > 0)
            res -= prefix[x1 - 1][y2];
        if (y1 > 0)
            res -= prefix[x2][y1 - 1];
        if (x1 > 0 && y1 > 0)
            res += prefix[x1 - 1][y1 - 1];

        return res;
    }

    bool valid(int mid, int Max)
    {
        int n = prefix.size(), m = prefix[0].size();
        for (int i = mid - 1; i < n; i++)
        {
            for (int j = mid - 1; j < m; j++)
            {
                int x1 = i - mid + 1;
                int y1 = j - mid + 1;

                int sum = Two_D_prefix(x1, y1, i, j);

                if (sum <= Max)
                    return true;
            }
        }

        return false;
    }

    int maxSideLength(vector<vector<int>> &mat, int Max)
    {
        int n = mat.size(), m = mat[0].size();
        build_prefix(mat);
        int l = 1, r = min(n, m), ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (valid(mid, Max))
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }

        return ans;
    }
};