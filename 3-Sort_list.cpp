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
    ListNode* mergeList(ListNode* l1, ListNode* l2)
    {
        if(l1==NULL && l2==NULL)
            return NULL;
        else if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        else
        {
            ListNode* res;
            if(l1->val <= l2->val)
            {
                res = l1;
                res->next = mergeList(l1->next, l2);
            }
            else
            {
                res = l2;
                res->next = mergeList(l1, l2->next);
            }
            return res;
        }
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        else if(head->next == NULL)
        {
            return head;
        }
        else
        {
            ListNode* temp;
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast!=NULL && fast->next!=NULL)
            {
                temp = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            temp->next = NULL;
            ListNode* l1 = sortList(head);
            ListNode* l2 = sortList(slow);

            return mergeList(l1,l2);
        }
    }
};
