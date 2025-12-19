/*
Problem: Merge Two Sorted Lists

Approach:
- Use an iterative pointer-based approach
- Create a dummy node to simplify edge cases
- Maintain a `tail` pointer to build the merged list
- Compare nodes from both lists:
    - Attach the smaller node to `tail->next`
    - Move the corresponding list pointer forward
    - Move `tail` forward
- After one list ends, attach the remaining nodes from the other list

Complexity:
- Time: O(n + m), where n and m are the lengths of the two lists
- Space: O(1), in-place merge (no extra nodes created)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy.next;
    }
};
