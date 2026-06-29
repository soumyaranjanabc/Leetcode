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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode * result =nullptr;
        ListNode * tail = nullptr;

        int sum=0;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry){
            sum=carry;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            int sum1=sum%10;
            carry=sum/10;

            ListNode* new_node = new ListNode(sum1);
            if(result==nullptr){
                result = tail=new_node;

            }else{
                tail->next=new_node;
                tail=new_node;
            }
        }
        return reverseList(result);

        
    }
};