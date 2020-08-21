
#include<iostream>
#include<vector>
#include "./solution/Solution.h"
using namespace std;

int main(void)
{

    Solution* solution = new Solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = NULL;
    root->right->left = NULL;

    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);

    vector<int> ret;

    solution->preOrder1(root, ret);

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout<<endl;

    ret.clear();

    solution->inOrder1(root, ret);

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout<<endl;

    ret.clear();
    solution->postOrder1(root, ret);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout<<endl;

    delete solution;
    return 0;
}