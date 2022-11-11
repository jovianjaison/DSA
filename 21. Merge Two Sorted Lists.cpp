//Linear Traversal
//O(m+n) Time
//O(1) Space
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode psuedo_head(0);
        ListNode* curr=&psuedo_head;

        while(list1 && list2){
            if(list1->val<=list2->val){
                curr->next=list1;
                list1=list1->next;
            }else{
                curr->next=list2;
                list2=list2->next;
            }
            curr=curr->next;
        }

        curr->next=list1?list1:list2;
        return psuedo_head.next;
    }
};