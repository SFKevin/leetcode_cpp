#pragma once
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(nullptr) {}
};

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class ListSolution
{
    public:
    ListNode* frontPoint;
    ListNode* deleteDuplicates(ListNode* head);
    ListNode* reverseList(ListNode* head);
    ListNode* reverseBetween(ListNode* head, int m, int n);
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    ListNode* partition(ListNode* head, int x);
    ListNode* sortList(ListNode* head);
    void reorderList(ListNode* head);
    bool hasCycle(ListNode *head);
    ListNode *detectCycle(ListNode *head);
    bool isPalindrome(ListNode* head);
    bool recursiveCheck(ListNode* curNode);
    Node* copyRandomList(Node* head);
};
