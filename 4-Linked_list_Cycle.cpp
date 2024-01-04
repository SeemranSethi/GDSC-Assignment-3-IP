/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return NULL;
        unordered_map<ListNode*,bool> vis;
        ListNode* curr = head;
        while(curr->next!=NULL && vis[curr->next]==false)
        {
            vis[curr] = true;
            curr = curr->next;
        }
        if(curr->next == NULL)
            return NULL;
        return curr->next;
    }
};
