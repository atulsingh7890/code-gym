// https://leetcode.com/problems/insertion-sort-list/
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
    ListNode* insertionSortList(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode * sorted_head = nullptr;        
        
        ListNode * current = head;
        ListNode * next = current->next;
        while(current) {
            
            // First cut-off current 
            next = current->next;            
            current->next = nullptr;
            
            //now insert current at appropriate position in the sorted list                    
            if(sorted_head == nullptr) {
                // this is the first node in sorted list
                sorted_head = current;
            } else {
                ListNode * sorted_list_current = sorted_head;
                // list is something not dead, add current somewhere
                ListNode * prev_sorted_list_current = nullptr;
                while(sorted_list_current != nullptr && sorted_list_current->val < current->val) {
                    prev_sorted_list_current = sorted_list_current;
                    sorted_list_current = sorted_list_current->next;
                }
                
                if(prev_sorted_list_current == nullptr) {
                    // inserting at the start
                    current->next = sorted_head;
                    sorted_head = current;
                } else if(sorted_list_current == nullptr) {
                    // insert at the end
                    prev_sorted_list_current->next = current;
                } else {
                    // insert somewhere between
                    current->next = sorted_list_current;
                    prev_sorted_list_current->next = current;
                }
            }  
                        
            //now uopdat the current
            current = next;            
        }
     
        return sorted_head;
    }
};
