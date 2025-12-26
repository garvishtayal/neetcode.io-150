/*
Problem: Merge k Sorted Lists

Approach:
- Use a helper function `mergeTwoLists` to merge two sorted linked lists
- Handle edge cases:
    - If list array is empty, return NULL
    - If only one list exists, return it directly
- First merge the first two lists
- Then iteratively merge the result with each remaining list
- The merged list is updated step-by-step

Complexity:
- Time: O(n * k), where
    - n = total number of nodes
    - k = number of lists
- Space: O(1), in-place merging (excluding recursion stack)
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
private:
    // Merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];

        ListNode* resHead = nullptr;

        ListNode* one = lists[0];
        ListNode* two = lists[1];

        // Merge first two lists
        resHead = mergeTwoLists(one, two);

        // Merge remaining lists one by one
        for (int i = 2; i < lists.size(); i++) {
            resHead = mergeTwoLists(resHead, lists[i]);
        }

        return resHead;
    }
};
