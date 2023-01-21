//Recursion
//O(n) Time
//O(n) Space
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;

        ListNode* fin=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return fin;
    }
};

//Iterative
//O(n) Time
//O(1) Space
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};
