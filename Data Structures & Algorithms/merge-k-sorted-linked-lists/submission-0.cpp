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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyhead=new ListNode(0);
        ListNode* curr=dummyhead;
        while(list1&&list2){
            if(list1->val>list2->val){curr->next=list2;list2=list2->next;}
            else {curr->next=list1;list1=list1->next;}
            curr=curr->next;
        }
        curr->next=list1?list1:list2;
        return dummyhead->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size=lists.size();
        if(!size)return nullptr;
        for(int i=1;i<size;i++){
            lists[i]=mergeTwoLists(lists[i-1],lists[i]);
        }return lists[size-1];
    }
};
