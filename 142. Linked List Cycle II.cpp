/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ListNode *result = nullptr;
        
        ListNode * slow = head, *fast = head, *cycle_ending_at = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                // we encountered a cycle
                //now move slow pointer within the cycle till its equal to cycle end
                while(slow != cycle_ending_at) {
                    slow = slow->next;
                    cycle_ending_at = cycle_ending_at->next;
                }
                result = cycle_ending_at;
                break;
            }
        }
        
        return result;
    }
};
