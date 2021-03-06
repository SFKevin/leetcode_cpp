#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<limits>
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

void dfs(TreeNode* root, vector<int>& ret)
{
    if (root == nullptr) {
        return;
    }
    ret.push_back(root->val);
    dfs(root->left, ret);
    dfs(root->right, ret);
}

vector<int> Solution::dfsOrder(TreeNode* root)
{
    vector<int> ret;
    dfs(root, ret);
    return ret;
}

vector<int> Solution::bfsOrder(TreeNode* root)
{
    vector<int> ret;
    queue<TreeNode *> qu;
    qu.push(root);
    while(!qu.empty()) {
        int len = qu.size();
        for (int i = 0; i < len; i++) {
            TreeNode* temp = qu.front();
            ret.push_back(temp->val);
            qu.pop();
            if (temp->left != nullptr) {
                qu.push(temp->left);
            }
            if (temp->right != nullptr) {
                qu.push(temp->right);
            }
        }
    }
    return ret;
}

vector<int> divideAndConquer(TreeNode* root) 
{
    vector<int> ret;
    if (root == nullptr) {
        return ret;
    }

    vector<int> left = divideAndConquer(root->left);
    vector<int> right = divideAndConquer(root->right);

    ret.push_back(root->val);
    ret.insert(ret.end(), left.begin(), left.end());
    ret.insert(ret.end(), right.begin(), right.end());

    return ret;
}

vector<int> Solution::preOrderTraversal(TreeNode* root)
{
    vector<int> result = divideAndConquer(root);
    return result;
}

void merge(vector<int>& a, int p, int q, int r) 
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int i, j, k;
    vector<int> left;
    vector<int> right;

    for (i = 0, k = p; i < n1; i++, k++) {
        left.push_back(a[k]);
    }

    for (j = 0, k = q + 1; j < n2; j++, k++) {
        right.push_back(a[k]);
    }

    for (i = 0, j = 0, k = p; i < n1 && j < n2; k++) {
        if (left[i] > right[j]) {
            a[k] = right[j];
            j++;
        } else {
            a[k] = left[i];
            i++;
        }
    }

    while (i < n1) {
        a[k] = left[i];
        k++;
        i++;
    }
    while (j < n2) {
        a[k] = right[j];
        k++;
        j++;
    }
}

void Solution::mergeSort(vector<int>& a, int p, int r) 
{
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

void Solution::quickSort(vector<int>& a, int low, int high)
{
    if (low > high) {
        return;
    }

    int i = low; 
    int j = high;
    int index = a[i];
    while (i < j) {
        while (i < j && a[j] > index) {
            j--;
        }
        if (i < j) {
            a[i++] = a[j];
        }

        while (i < j && a[i] < index) {
            i++;
        }
        if (i < j) {
            a[j--] = a[i];
        }
    }
    a[i] = index;
    quickSort(a, low, i - 1);
    quickSort(a, i + 1, high);
}

int Solution::maxDepth(TreeNode* root)
{
    if (root == nullptr) {
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    if (left == -1 || right == -1 || left - right > 1 || right - left > 1) {
        return -1;
    }

    return std::max(left, right) + 1;
}

bool Solution::isBalanced(TreeNode* root)
{
    if (maxDepth(root) == -1) {
        return false;
    }
    return true;
}

// int maxSum = std::numeric_limits<int>::min();
// int Solution::maxPathSum(TreeNode* root)
// {
//    maxGain(root);
//    return maxSum;
// }

// int maxGain(TreeNode* root)
// {
//     if (root == nullptr) {
//         return 0;
//     }

//     int left = maxGain(root->left);
//     int right = maxGain(root->right);

//     int left1 = std::max(left, 0);
//     int right1 = std::max(right, 0);
    
//     int tempSum = root->val + left1 + right1;

//     maxSum = std::max(tempSum, maxSum);

//     return root->val + std::max(left1, right1);
// }

// TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
// {
//     if (root == nullptr) {
//         return root;
//     }

//     if (root == p || root == q) {
//         return root;
//     }

//     TreeNode* left = lowestCommonAncestor(root->left, p, q);
//     TreeNode* right = lowestCommonAncestor(root->right, p, q);

//     if (left != nullptr && right != nullptr) {
//         return root;
//     }
//     if (left != nullptr){
//         return left;
//     }

//     if (right != nullptr) {
//         return right;
//     }

//     return nullptr;
// }

// using namespace std;
// vector<vector<int>> levelOrder(TreeNode* root) 
// {
//     vector<vector<int>> result;
//     if (root == nullptr) {
//         return result;
//     }

//     queue<TreeNode*> qu;
//     qu.push(root);
//     while (!qu.empty()) {
//         int len = qu.size();
//         vector<int> tempVec;
//         tempVec.resize(len);
//         for (int i = 0; i < len; i++) {
//             TreeNode* temp = qu.front();
//             qu.pop();
//             tempVec[i] = temp->val;
//             if (temp->left != nullptr) {
//                 qu.push(temp->left);
//             }
//             if (temp->right != nullptr) {
//                 qu.push(temp->right);
//             }
//         }
//         result.push_back(tempVec);
//     }
//     return result;
// }

// vector<vector<int>> levelOrderBottom(TreeNode* root) 
// {
//     vector<vector<int>> result;
//     stack<vector<int>> temResult;
//     if(root == nullptr) {
//         return result;
//     }
//     queue<TreeNode*> qu;
//     qu.push(root);
//     while (!qu.empty()) {
//         int len = qu.size();
//         vector<int> tempVec;
//         for (int i = 0; i < len; i++) {
//             TreeNode* tempNode = qu.front();
//             qu.pop();
//             tempVec.push_back(tempNode->val);
//             if (tempNode->left != nullptr) {
//                 qu.push(tempNode->left);
//             }
//             if (tempNode->right != nullptr) {
//                 qu.push(tempNode->right);
//             }
//         }
//         temResult.push(tempVec);
//     }
//     while (!temResult.empty()) {
//         result.push_back(temResult.top());
//         temResult.pop();
//     }
//     return result;
// }

// vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
// {
//     vector<vector<int>> result;
//     queue<TreeNode*> qu;
//     int level = 0;
//     if (root == nullptr) {
//         return result;
//     }
//     qu.push(root);
//     while(!qu.empty()) {
//         int len = qu.size();
//         vector<int> tempVec;
//         for (int i = 0; i < len; i++) {
//             TreeNode* tempNode = qu.front();
//             qu.pop();
//             if (level % 2 == 0) {
//                 tempVec.push_back(tempNode->val);
//             } else {
//                  tempVec.insert(tempVec.begin(), tempNode->val);
//             }

//             TreeNode* left = tempNode->left;
//             if (left != nullptr) {
//                 qu.push(left);
//             }
//             TreeNode* right = tempNode->right;
//             if (right != nullptr) {
//                 qu.push(right);
//             }
//         }
//         result.push_back(tempVec);
//         level++;
//     }
//     return result;
// }

// bool Solution::isValidBST(TreeNode* root) 
// {
//     if (root == nullptr) {
//         return true;
//     }
//     stack<TreeNode*> st;
//     long flag = std::numeric_limits<long>::min();
//     while (root != nullptr || !st.empty()) {
//         while(root!= nullptr) {
//             st.push(root);
//             root = root->left;
//         }
//         TreeNode* temp = st.top();
//         st.pop();
//         if (temp->val <= flag) {
//             return false;
//         }
//         flag = temp->val;
//         root = temp->right;
//     }
//     return true;
// }

// bool helpBST(TreeNode* root, long lower, long upper) {
//     if (root == nullptr) {
//         return true;
//     }
//     if (root->val <= lower || root->val >= upper) {
//         return false;
//     }
//     return helpBST(root->left, lower, root->val) && helpBST(root->right, root->val, upper);
// }

// TreeNode* insertIntoBST(TreeNode* root, int val) 
// {
//     if (root == nullptr) {
//         return new TreeNode(val);
//     }
//     TreeNode* head = root;
//     while (root) {
//         if (val < root->val) {
//             if (root->left == nullptr) {
//                 root->left = new TreeNode(val);
//                 return head;
//             }else {
//                 root = root->left;
//             }
//         } else {
//             if (root->right == nullptr) {
//                 root->right = new TreeNode(val);
//                 return head;
//             } else {
//                 root = root->right;
//             }
//         }
//     }
//     return head;
// }