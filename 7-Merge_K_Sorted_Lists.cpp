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
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;

        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = (l1!=NULL) ? l1 : l2;
        return head->next;
    }
    ListNode* mergeSortKLists(vector<ListNode*>& lists, int start, int end)
    {
        if(start>end)
            return NULL;
        if(start==end)
            return lists[start];
        int mid = start + (end-start)/2;
        ListNode* left = mergeSortKLists(lists, start, mid);
        ListNode* right = mergeSortKLists(lists, mid+1, end);
        return merge(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        return mergeSortKLists(lists, 0, lists.size()-1);
    }
};
