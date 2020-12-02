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

ListNode* middleNode(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* head)
{
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

void mergeLists(ListNode* l1, ListNode* l2)
{
    ListNode* l1_temp;
    ListNode* l2_temp;
    while (l1 != nullptr && l2 != nullptr) {
        l1_temp = l1->next;
        l2_temp = l2->next;

        l1->next = l2;
        l1 = l1_temp;

        l2->next = l1;
        l2 = l2_temp;
    }

}

void ListSolution::reorderList(ListNode* head)
{
    if (head == nullptr) {
        return;
    }
    ListNode* mid = middleNode(head);
    ListNode* l1 = head;
    ListNode* l2 = mid->next;
    mid->next = nullptr;
    l2 = reverseList(l2);
    mergeLists(l1, l2);
}

bool ListSolution::hasCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

ListNode* ListSolution::detectCycle(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr) {
        slow = slow->next;
        if (fast->next == nullptr) {
            return nullptr;
        }
        fast = fast->next->next;
        if (fast == slow) {
            ListNode* pre = head;
            while (pre != slow) {
                pre = pre->next;
                slow = slow->next;
            }
            return pre;
        }
    }
    return nullptr;
}

bool ListSolution::recursiveCheck(ListNode* curNode)
{
    if (curNode != nullptr) {
        if (!recursiveCheck(curNode->next)) {
            return false;
        }
        if (curNode->val != frontPoint->val)
        {
            return false;
        }
        frontPoint = frontPoint->next;
    }
    return true;
}

bool ListSolution::isPalindrome(ListNode* head)
{
    frontPoint = head;
    recursiveCheck(head);
}

Node* ListSolution::copyRandomList(Node* head)
{
    if (head == nullptr) {
        return head;
    }
    Node* cur = head;
    unordered_map<Node*, Node*> map;
    while (cur != nullptr) {
        Node* copy = new Node(cur->val);
        map[cur] = copy;
        cur = cur->next;
    }
    cur = head;
    while (cur != nullptr) {
        map[cur]->next = map[cur->next];
        map[cur]->random = map[cur->random];
        cur = cur->next;

    }
    return map[head];
}

