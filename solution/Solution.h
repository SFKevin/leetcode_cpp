#pragma once
#include<string>
#include<vector>
using namespace std;

struct TreeNode
{
    int val = 0;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int strStr(string haystack, string needle);
    vector<vector<int>> subsets(vector<int>& nums);
    vector<int> preOrder(TreeNode* root, vector<int>& ret);
    vector<int> inOrder(TreeNode* root, vector<int>& ret);
    vector<int> postOrder(TreeNode* root, vector<int>& ret);

    vector<int> preOrder1(TreeNode* root, vector<int>& ret);
    vector<int> inOrder1(TreeNode* root, vector<int>& ret);
    vector<int> postOrder1(TreeNode* root, vector<int>& ret);

};