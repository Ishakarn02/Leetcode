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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Count the total number of nodes
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr) {
            temp = temp->next;
            count++;
        }

        // Step 2: Find the node just before the one we need to delete
        int cnt = count - n;
        // Edge case: if we need to delete the head node
        if (cnt == 0) {
            ListNode* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return head;
        }

        ListNode* curr = head;
        for (int i = 1; i < cnt; ++i) {
            curr = curr->next;
        }

        // Step 3: Delete the nth node from the end
        ListNode* nodeToDelete = curr->next;
        curr->next = curr->next->next;
        delete nodeToDelete;

        return head;
    }
};