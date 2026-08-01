/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check if there are at least k nodes left in the list
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head; // Fewer than k nodes, leave unchanged
            temp = temp->next;
        }

        // Reverse the current group of k nodes
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nex = nullptr;
        int count = 0;

        while (curr && count < k) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            count++;
        }

        // Recursively process the remainder and link it
        if (nex) {
            head->next = reverseKGroup(nex, k);
        }

        // Return the new head of the reversed group
        return prev;
    }
};
