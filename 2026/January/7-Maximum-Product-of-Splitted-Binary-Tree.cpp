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

#define ll long long
#define Mod 1000000007

class Solution
{
public:
    ll total, sub, ans;

    void totalSum(TreeNode *node)
    {
        if (!node)
            return;
        total += node->val;
        if (node->left)
            totalSum(node->left);
        if (node->right)
            totalSum(node->right);
    }

    void split(TreeNode *node)
    {
        if (!node)
            return;
        sub += node->val;
        if (node->left)
            split(node->left);
        if (node->right)
            split(node->right);
    }

    void dfs(TreeNode *node)
    {
        if (!node)
            return;

        if (node->left)
        {
            sub = 0;
            split(node->left);
            ll rsum = total - sub;
            ans = max(ans, rsum * sub);
        }

        if (node->right)
        {
            sub = 0;
            split(node->right);
            ll lsum = total - sub;
            ans = max(ans, lsum * sub);
        }

        if (node->left)
            dfs(node->left);
        if (node->right)
            dfs(node->right);
    }

    int maxProduct(TreeNode *root)
    {
        total = 0;
        sub = 0;
        ans = 0;

        totalSum(root);
        dfs(root);

        return ans % Mod;
    }
};
