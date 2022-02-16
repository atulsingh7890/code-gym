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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode * prev = nullptr;
        ListNode * current = head;
        
        
        while(current && current->next) {
                        
            ListNode * next = current->next->next;
            
            //relink current and current->next
            if(prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }  
            current->next->next = current;
            current->next = next;
            
            
            //update prev
            if(prev)
                prev = prev->next->next;
            else {                
                prev = current;
             }               
               
            //update current
            current = current->next;                    
        }
        
        return head;
    }
};
