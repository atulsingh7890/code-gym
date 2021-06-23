//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3789/

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
    ListNode * reverseList(ListNode* head) {
        if(nullptr == head || nullptr == head->next)
            return head;

        ListNode * prev = nullptr, *current = head, *next = head->next;
        while(next) {
            current->next = prev;
            prev = current;
            current = next;
            next = next->next;
        }

        current->next = prev;    
        return current;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(nullptr == head)
            return head;
        
        ListNode *prev_left_node = nullptr, *left_node = head;
        
        
        //first find left node and its previous node
        int pos = 1;
        while(left_node && pos != left) {
            prev_left_node = left_node;
            left_node = left_node->next;
            pos++;
        }
        
        // left_node should not be null at this point of time
        ListNode *prev_right_node = prev_left_node, * right_node = left_node;
        while(right_node && pos != right) {
            prev_right_node = right_node;
            right_node = right_node->next;
            pos++;
        }
        
        
        // now detach our [left,right]
        if(prev_left_node)
            prev_left_node->next = nullptr;
        ListNode *next_right_node = right_node->next;
        right_node->next = nullptr;
        
        right_node = reverseList(left_node);
        
        if(prev_left_node) {
            prev_left_node->next = right_node;
        }
        
        left_node->next = next_right_node;
        
        return prev_left_node != nullptr ? head : right_node; 
    }
};
