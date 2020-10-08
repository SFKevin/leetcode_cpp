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

ListNode* ListSolution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode* temp = new ListNode(0);
    ListNode* head = temp;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            head->next = l1;
            l1 = l1->next;
        } else {
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }

    while (l1 != nullptr) {
        head->next = l1;
        head = head->next;
        l1 = l1->next;
    }

    while (l2 != nullptr) {
        head->next = l2;
        head = head->next;
        l2 = l2->next;
    }

    return temp->next;
}

ListNode* ListSolution::partition(ListNode* head, int x)
{
    ListNode* headDummy = new ListNode(0);
    ListNode* tailDummy = new ListNode(0);
    ListNode* tail = tailDummy;
    headDummy->next = head;
    head = headDummy;

    while (head->next != nullptr) {
        if (head->next->val < x) {
            head = head->next;
        } else {
            tail->next = head->next;
            head->next = head->next->next;
            tail = tail->next;
        }
    }
    tail->next = nullptr;
    head->next = tailDummy->next;

    return headDummy->next;
}

ListNode* findMiddle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* mergeList(ListNode* l1, ListNode* l2) 
{
    ListNode* headDummy = new ListNode(-1);
    ListNode* head = headDummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            head->next = l1;
            l1 = l1->next;
        } else {
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }

    while (l1 != nullptr) {
        head->next = l1;
        l1 = l1->next;
        head = head->next;
    }

    while (l2 != nullptr) {
        head->next = l2;
        l2 = l2->next;
        head = head->next;
    }

    return headDummy->next;
}

ListNode* mergeSort(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* middle = findMiddle(head);
    ListNode* tail = middle->next;
    middle->next = nullptr;
    ListNode* left = mergeSort(head);
    ListNode* right = mergeSort(tail);
    ListNode* result = mergeList(left, right);
    return result;
}

ListNode* ListSolution::sortList(ListNode* head)
{
    return mergeSort(head);
}