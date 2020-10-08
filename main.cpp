
#include<iostream>
#include<vector>
#include "./solution/list_solution.h"
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
    ListSolution* solution = new ListSolution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    solution->partition(head, 3);
    while (head != nullptr) {
        cout << head->val << "\t";
        head = head->next;
    }

    delete solution;
    return 0;
}