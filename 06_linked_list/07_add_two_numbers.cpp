/*
Problem: Add Two Numbers

Approach:
- Use a dummy node to build the result linked list
- Traverse both linked lists simultaneously
- At each step:
    - Extract current digit values from both lists
    - Add them along with carry
    - Handle carry explicitly when sum exceeds 9
    - Create a new node with the computed digit
- After traversal, if carry exists, append a final node

Complexity:
- Time: O(n), where n is the length of the longer list
- Space: O(n), for the resulting linked list
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode dummy;
        ListNode* dummyHead = &dummy;

        ListNode* l1Temp = l1;
        ListNode* l2Temp = l2;
        ListNode* dummyTemp = dummyHead;

        int carry = 0;
        int l1Val = 0;
        int l2Val = 0;
        int sum;

        while (l1Temp || l2Temp) {
            l1Val = l1Temp ? l1Temp->val : 0;
            l2Val = l2Temp ? l2Temp->val : 0;

            if (l1Val + l2Val + carry > 9) {
                sum = l1Val + l2Val + carry - 10;
                carry = 1;
            } else {
                sum = l1Val + l2Val + carry;
                carry = 0;
            }

            dummyTemp->next = new ListNode(sum);

            l1Temp = l1Temp ? l1Temp->next : nullptr;
            l2Temp = l2Temp ? l2Temp->next : nullptr;

            dummyTemp = dummyTemp->next;
        }

        // Append remaining carry if present
        dummyTemp->next = carry ? new ListNode(1) : nullptr;

        return dummyHead->next;
    }
};
