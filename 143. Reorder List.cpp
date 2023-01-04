//Find mid + Reversal + Merge 2 lls
//O(n) Time
//O(1) Space 
class Solution {
public:
    ListNode* rev(ListNode* head){
        if(!head || !head->next)return head;

        ListNode* og = rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return og;
    }
    void reorderList(ListNode* head) {
        //Find mid
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        //Slow is mid
        //Reverse second half
        
        ListNode* mid = rev(slow->next);
        slow->next=NULL;

        //Merge two lls
        while(mid){
            ListNode* temp = head->next;
            head->next=mid;
            mid=mid->next;
            head->next->next=temp;
            head=temp;
        }
    }
};