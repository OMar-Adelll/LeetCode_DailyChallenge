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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int len = 0;
    TreeNode *ans = nullptr;
    int dfs(TreeNode *node, int cur)
    {
        len = max(len, cur);
        if (!node)
            return cur;
        int l = dfs(node->left, cur + 1);
        int r = dfs(node->right, cur + 1);
        if (l == len && r == len)
            ans = node;
        return max(l, r);
    }
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        dfs(root, 0);
        return ans;
    }
};