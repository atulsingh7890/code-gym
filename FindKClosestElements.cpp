//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3800/
class Solution {
    int findClosesIndex(std::vector<int> & arr, int x) {
        int l = 0, h = arr.size() - 1;
        int mid = l + ((h - l)>>1);
        
        //Boundary Conditions
        if(arr[0] > x)
            return 0;
        else if(arr[arr.size()-1] < x)
            return arr.size() - 1;
        
        // because we need two elements at any time
        while( l < h) {                 
            mid = l + ((h - l)>>1);
            // A - B : x lies in between
            if(arr[mid] <= x && arr[mid+1] >= x ) {
                /// pick the closest of A and B, default is A
                mid = (x - arr[mid]) <= (arr[mid+1] - x) ? mid : mid + 1;
                break;
            }
                        
            if(arr[mid] < x){
                l = mid;
            } else if(arr[mid] > x) {                
                h = mid;
            } else {
                break;
            }                
        }
        return mid;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::vector<int> result;
        
        int closest_index =  findClosesIndex(arr,x);
        int left = closest_index , right = closest_index ;
        int elements_chosen = 1;

        
        while(left > 0 && right < arr.size() - 1 && elements_chosen < k) {
            if(std::abs(arr[left-1] - x) <= std::abs(arr[right+1] - x)) {            
                left--;   
            } else {                
                right++;                                
            }
            elements_chosen++;
        }
        
        
        while(left > 0 && elements_chosen < k) {
            left--;
            elements_chosen++;            
        }
        
        while(right < arr.size() && elements_chosen < k) {
            right++;
            elements_chosen++;       
        }      
        
        for(int i = left; i  <= right; ++i) {
            result.push_back(arr[i]);
        }
        
        return result;
    }
};
