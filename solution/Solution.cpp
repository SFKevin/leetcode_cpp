#include<iostream>
#include<vector>
#include<stack>
#include "../solution/Solution.h"
using namespace std;

void backtrack(vector<int>& nums, int pos, vector<int>& temp, vector<vector<int>>& ret) 
{
    ret.push_back(vector<int>(temp));

    for (int i = pos; i < nums.size(); i++) {
        temp.push_back(nums[i]);
        backtrack(nums, i + 1, temp, ret);
        temp.pop_back();
    }
}

int Solution::strStr(string haystack, string needle)
{
    int len1 = haystack.length();
    int len2 = needle.length();

    if (len1 < len2) {
        return -1;
    }

    if (needle.size() == 0) {
        return 0;
    }
    int i;
    int j;
    for (i = 0; i < len1 - len2 + 1; i++) {
        for (j = 0; j < len2; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == len2) {
            return i;
        }
    }
    return -1;
}

vector<vector<int>> Solution::subsets(vector<int>& nums) 
{
    vector<vector<int>> ret;
    vector<int> tempRet;
    backtrack(nums, 0, tempRet, ret);
    return ret;
}



vector<int> Solution::preOrder(TreeNode* root, vector<int>& ret)
{
    if (root == NULL) {
        return ret;
    } else {
        ret.push_back(root->val);
        preOrder(root->left, ret);
        preOrder(root->right, ret);
    }
    return ret;
}

vector<int> Solution::inOrder(TreeNode* root, vector<int>& ret) 
{
    if (root == NULL) {
        return ret;
    } else {
        inOrder(root->left, ret);
        ret.push_back(root->val);
        inOrder(root->right, ret);
    }
    return ret;
}

vector<int> Solution::postOrder(TreeNode* root, vector<int>& ret) 
{
    if (root == NULL) {
        return ret;
    } else {
        postOrder(root->left, ret);
        postOrder(root->right, ret);
        ret.push_back(root->val);
    }
    return ret;
}

vector<int> Solution::preOrder1(TreeNode* root, vector<int>& ret) 
{
    stack<TreeNode *> st;
    if (root == nullptr) {
        return ret;
    }

    while (root != nullptr || !st.empty()) {
        while (root != nullptr) {
            ret.push_back(root->val);
            st.push(root);
            root = root->left;
        }
        if (!st.empty()) {
            root = st.top();
            st.pop();
            root = root->right;
        }
    }
    return ret;
}

vector<int> Solution::inOrder1(TreeNode* root, vector<int>& ret) 
{
    stack<TreeNode *> st;
    if (root == nullptr) {
        return ret;
    }

    while (root != nullptr || !st.empty()) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }

        if (!st.empty()) {
            root = st.top();
            st.pop();
            ret.push_back(root->val);
            root = root->right;
        }
    }
    return ret;
}

vector<int> Solution::postOrder1(TreeNode* root, vector<int>& ret)
{
    stack<TreeNode *> st1;
    stack<int> st2;

    while (root != nullptr || !st1.empty()) {
        while (root != nullptr) {
            st1.push(root);
            st2.push(0);
            root = root->left;
        }

        while (!st1.empty() && st2.top() == 1) {
            TreeNode* temp = st1.top();
            st1.pop();
            st2.pop();
            ret.push_back(temp->val);
        }

        if (!st1.empty()) {
            st2.pop();
            st2.push(1);
            root = st1.top();
            root = root->right;
        }
    }

    return ret;
}


