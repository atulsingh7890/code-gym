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
    Solution(ListNode* head) {
        std::srand(std::time(nullptr)); // use current time as seed for random generator
        head_ = head;
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        gen_ = std::mt19937(rd()); // Standard mersenne_twister_engine seeded with rd()
        dis_ = std::uniform_real_distribution<>(0.0, 1.0);
    }
    
    int getRandom() {        
        int chosenValue = head_->val;
        ListNode * current = head_;
        int elements_processed = 1;
        while(current != nullptr) {             
            float random_variable = dis_(gen_);
            if(random_variable <= 1.0/elements_processed) {
                chosenValue = current->val;
            }
            current = current->next;
            elements_processed++;
        }
        return chosenValue;
    }
private:
    ListNode *head_;
    std::mt19937 gen_;
    std::uniform_real_distribution<> dis_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
