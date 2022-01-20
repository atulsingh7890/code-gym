class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int start_speed = 1, end_speed = *std::max_element(piles.begin(), piles.end());
        // pattern would be
        // 1  1 1 1 1 1 1 0 0 0 0 0 0 0 0
        //lets binary search on the working speed
        while(start_speed < end_speed) {
            int middle = (start_speed + end_speed)/2;
            
            bool isMiddlePossible = isPossible(piles, h, middle);
            
            //[1,0] , in this scenario , middle will be at 0
            if(isMiddlePossible) {
                end_speed = middle;                
            } else {
                start_speed = middle + 1;
            }            
        }
        return start_speed;        
    }
private:
    bool isPossible(std::vector<int> & piles, int h , int speed) {
        int hours_consumed = 0;
        bool result = true;
        for(auto p : piles) {
            hours_consumed += std::ceil((1.0*p)/speed);
            if(hours_consumed > h) {
                result = false;
                break;
            }
        }
        return result;        
    }
};
