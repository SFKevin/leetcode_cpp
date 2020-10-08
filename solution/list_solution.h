#pragma once
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(nullptr) {}
};

class ListSolution
{
    public:
    ListNode* deleteDuplicates(ListNode* head);
    ListNode* reverseList(ListNode* head);
    ListNode* reverseBetween(ListNode* head, int m, int n);
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    ListNode* partition(ListNode* head, int x);
    ListNode* sortList(ListNode* head);
};
