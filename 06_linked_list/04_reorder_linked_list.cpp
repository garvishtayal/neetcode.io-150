/*
Problem: Reorder List

Approach:
- Split the linked list into two halves
- Use slow & fast pointers to find the middle of the list
- Reverse the second half of the list
- Merge the two halves alternately:
    - First node from first half
    - First node from second half
- Do the reordering in-place without creating new nodes

Complexity:
- Time: O(n), where n is the number of nodes
- Space: O(1), in-place reordering
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {

        // Step 1: Find middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half of the list
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        slow->next = NULL;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Merge the two halves
        ListNode* l1 = head;
        ListNode* l2 = prev;

        while (l2) {
            ListNode* t1 = l1->next;
            ListNode* t2 = l2->next;

            l1->next = l2;
            l2->next = t1;

            l1 = t1;
            l2 = t2;
        }
    }
};
