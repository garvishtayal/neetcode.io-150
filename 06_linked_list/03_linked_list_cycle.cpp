/*
Problem: Linked List Cycle

Approach:
- Use Floyd’s Cycle Detection Algorithm (Tortoise and Hare)
- Maintain two pointers:
    - `slow` moves one step at a time
    - `fast` moves two steps at a time
- Traverse the list:
    - If there is a cycle, `fast` and `slow` will eventually meet
    - If `fast` or `fast->next` becomes NULL, no cycle exists

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
    bool hasCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = (fast->next)->next;

            if (fast == slow) return true;
        }

        return false;
    }
};
