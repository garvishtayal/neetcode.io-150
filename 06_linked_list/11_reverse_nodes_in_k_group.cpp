/*
Problem: Reverse Nodes in k-Group

Approach:
- Reverse the linked list in groups of size k
- Use two pointers (`l` and `r`) to identify each k-sized group
- For each group:
    - Reverse the nodes using a helper `reverse(head, tail)` function
    - Connect the previous group to the reversed group
    - Reconnect the reversed group to the next part of the list
- If remaining nodes are fewer than k, leave them as is

Helper Function:
- reverse(head, tail):
    - Reverses nodes from `head` to `tail` (inclusive)
    - Returns the new head of the reversed segment

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
private:
    // Reverse linked list from head to tail (inclusive)
    ListNode* reverse(ListNode* head, ListNode* tail) {

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* stop = tail->next;

        while (curr != stop) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // New head of the reversed segment
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k <= 1) return head;

        ListNode* prevGroup = head;
        ListNode* resHead = head;
        ListNode* nextHead;

        ListNode* l = head;
        ListNode* r = head;
        int count = 1;
        int round = 0;

        while (r) {
            count++;
            r = r->next;

            if (count == k) {
                if (!r) break;

                nextHead = r->next;

                // Reverse current k-group
                (round == 0) ? resHead = reverse(l, r) : reverse(l, r);

                // Connect previous group to current reversed group
                if (round > 0) {
                    prevGroup->next = r;
                }

                prevGroup = l;
                round++;

                // Connect current group to next part
                l->next = nextHead;
                r = l->next;
                l = l->next;
                count = 1;
            }
        }

        return resHead;
    }
};