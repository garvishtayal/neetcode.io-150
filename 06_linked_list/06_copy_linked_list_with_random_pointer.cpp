/*
Problem: Copy List with Random Pointer

Approach:
- Use a hash map to map original nodes to their copied nodes
- Create the copied list and fill the hash map in a single traversal
- First node (head) is copied and stored in the map
- While traversing the original list:
    - Create the `next` node for the copied list
    - Store mapping of old node -> new node in the hash map
- Second pass:
    - Assign correct `random` pointers using the hash map
- Return the head of the deep-copied list

Complexity:
- Time: O(n), where n is the number of nodes
- Space: O(n), extra space for the hash map
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (!head) return nullptr;

        unordered_map<Node*, Node*> hash;

        Node* newHead = new Node(head->val);
        Node* currOld = head;
        Node* currNew = newHead;

        // Store mapping for head node
        hash[currOld] = currNew;

        // Deep copy + hashmap population in one loop
        while (currOld->next) {
            currNew->next = new Node(currOld->next->val);

            currOld = currOld->next;
            currNew = currNew->next;

            hash[currOld] = currNew;
        }

        // Update random pointers using hashmap
        Node* tempOld = head;
        Node* tempNew = newHead;

        while (tempNew) {
            tempNew->random = tempOld->random
                                ? hash[tempOld->random]
                                : nullptr;

            tempOld = tempOld->next;
            tempNew = tempNew->next;
        }

        return newHead;
    }
};
