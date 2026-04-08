class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;
        
        // Loop runs as long as there is a node in l1, OR a node in l2, OR a leftover carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            
            // Start the sum with whatever carry we had from the last step
            int sum = carry; 
            
            // Add l1's value if it exists, then move l1 forward
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // Add l2's value if it exists, then move l2 forward
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Math magic to get the carry and the digit
            carry = sum / 10;                     // e.g., 15 / 10 = 1 (new carry)
            cur->next = new ListNode(sum % 10);   // e.g., 15 % 10 = 5 (node value)
            
            cur = cur->next;
        }
        
        // Good C++ practice: clean up the dummy node memory before returning
        ListNode* result = dummy->next;
        delete dummy; 
        return result;
    }
};