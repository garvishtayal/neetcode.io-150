/*
Problem: Reverse Linked List

Approach:
- Use an iterative pointer-based approach
- Maintain three pointers:
    - `prev` to track the previous node
    - `curr` to traverse the list
    - `next` to temporarily store the next node
- For each node:
    - Reverse the `next` pointer
    - Move `prev` and `curr` one step forward
- At the end, `prev` will point to the new head of the reversed list

Complexity:
- Time: O(n), where n is the number of nodes
- Space: O(1), in-place reversal
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
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
