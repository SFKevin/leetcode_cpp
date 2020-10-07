#include "../solution/list_solution.h"


ListNode* ListSolution::deleteDuplicates(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* tempHead = new ListNode(0);
    tempHead->next = head;
    head = tempHead;
    ListNode* lptr;
    ListNode* rptr;
    while (tempHead->next != nullptr) {
        lptr = tempHead->next;
        rptr = tempHead->next;
        while (rptr->next && rptr->next->val == lptr->val) {
            rptr = rptr->next;
        }
        if (lptr == rptr) {
            tempHead = tempHead->next;
        } else {
            tempHead->next = rptr->next;
            while (lptr != rptr) {
                ListNode* tmp = lptr;
                lptr = lptr->next;
                delete tmp;
            }
            delete lptr;
            delete rptr;
        }
    }
    return head->next;
}

ListNode* ListSolution::reverseList(ListNode* head)
{
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* next = nullptr;
    while (cur != nullptr) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

ListNode* ListSolution::reverseBetween(ListNode* head, int m, int n)
{
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (m > 1) {
        pre = cur;
        cur = cur->next;
        m--;
        n--;
    }

    ListNode* before = pre;
    ListNode* after = cur;
    while (n > 0) {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
        n--;
    }
    if (before) {
        before->next = pre;
    } else {
        head = pre;
    }

    after->next = cur;
    

    return head;
}