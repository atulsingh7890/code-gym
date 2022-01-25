class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool peak_found = false;
        bool result = true;
        
        int i = 0;
        while(i+1 < arr.size() && arr[i] < arr[i+1]) {
            i++;
        }            
        
        //i should be at peak now
        if( i == 0 || i == arr.size() - 1) {
            return false;
        }
        
        while(i+1 < arr.size() && arr[i] > arr[i+1]) {
            i++;
        }
        
        
        //check if we reached end
        return i == arr.size() - 1;
    }
};
