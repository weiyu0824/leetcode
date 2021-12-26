#include <iostream>


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();;
        ListNode* cur = head;

        int sum;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr){
            if (l1 == nullptr){
                sum = (l2 -> val) + carry;
            }else if (l2 == nullptr){
                sum = (l1 -> val) + carry;
            }else {
                sum = (l1 -> val) + (l2 -> val) + carry;
            }
            
            cur -> val = sum % 10;
            carry = sum / 10;

            if (l1 != nullptr)
                l1 = l1 -> next;
            if (l2 != nullptr)
                l2 = l2 -> next; 

            if (carry > 0 || l1 != nullptr || l2 != nullptr){
                cur -> next = new ListNode(carry);
                cur = cur -> next;
            }
        }
        return head;
    }
};
