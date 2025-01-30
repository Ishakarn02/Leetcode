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
        // base case
        if(head == NULL){
            return NULL;
        }

        // check if there is at least k node 
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL && count < k){
            temp = temp -> next;
            count++;
        }

        // if node are less than k in k group
        if(count < k){
            return head;
        }

        //step 1 (reverse 1st group of k nodes)
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int cnt = 0;

        while(curr != NULL && cnt < k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        // step2 recursion
        if(next != NULL){
            head -> next = reverseKGroup(next, k);
        }
        return prev;
    }
};