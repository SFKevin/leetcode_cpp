
#include<iostream>
#include<vector>
#include "./solution/Solution.h"
using namespace std;

// int main(void)
// {

//     Solution* solution = new Solution;
//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->right = NULL;
//     root->right->left = NULL;

//     root->left->left = new TreeNode(4);
//     root->right->left = new TreeNode(5);

//     vector<int> ret = solution->preOrderTraversal(root);

//     for (int i = 0; i < ret.size(); i++) {
//         cout << ret[i] << " ";
//     }
//     cout<<endl;

//     delete solution;
//     return 0;
// }
int main(void) 
{
    vector<int> array = {5, 8, 3, 2, 9};
    Solution* solution = new Solution;

    solution->quickSort(array, 0, array.size() - 1);
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }

    delete solution;
    return 0;
}