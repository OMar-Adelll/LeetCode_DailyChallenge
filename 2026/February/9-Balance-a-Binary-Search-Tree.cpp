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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    void trav(TreeNode *node, vector<int> &nodes)
    {
        if (!node)
            return;

        trav(node->left, nodes);
        nodes.push_back(node->val);
        trav(node->right, nodes);
    }

    TreeNode *go(const vector<int> &nums, int l, int r)
    {
        if (l > r)
            return nullptr;

        int mid = (l + r) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = go(nums, l, mid - 1);
        node->right = go(nums, mid + 1, r);

        return node;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> nums;
        trav(root, nums);
        return go(nums, 0, nums.size() - 1);
    }
};