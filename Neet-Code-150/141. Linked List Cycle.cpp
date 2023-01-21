//Floyd cycle finding
//O(n) Time
//O(1) Space
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return true;
        }
        return false;
    }
};