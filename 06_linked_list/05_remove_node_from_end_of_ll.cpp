/*
Problem: Remove Nth Node From End of List

Approach:
- Use the two-pointer technique with a dummy node
- Initialize both `left` and `right` pointers at the dummy node
- Move `right` pointer `n` steps ahead
- Move both pointers together until `right->next` reaches NULL
- `left` will be positioned just before the node to delete
- Adjust pointers to remove the target node safely

Complexity:
- Time: O(n), where n is the number of nodes
- Space: O(1), constant extra space
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* left = &dummy;
        ListNode* right = &dummy;

        // Move right pointer n steps ahead
        for (int i = 0; i < n; i++) {
            right = right->next;
        }

        // Move both pointers until right reaches the end
        while (right->next) {
            left = left->next;
            right = right->next;
        }

        // Remove the target node
        ListNode* toDelete = left->next;
        left->next = toDelete->next;
        delete toDelete;

        return dummy.next;
    }
};
