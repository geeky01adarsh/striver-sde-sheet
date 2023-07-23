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
    ListNode* recursiveList(ListNode* head, ListNode* prev){
        if(!head) return NULL;
        ListNode* next = head->next;
        head->next = prev;
        if(!next) return head;
        return recursiveList(next, head);
    }
    ListNode* reverseList(ListNode* head) {
        return recursiveList(head, NULL);
    }
};