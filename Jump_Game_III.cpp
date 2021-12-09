//https://leetcode.com/problems/jump-game-iii/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        std::vector<int> cache(arr.size(), -1);
        std::vector<bool> visited(arr.size(),false);
        return canReachHelper(arr, start, cache, visited);
    }
private:
    bool canReachHelper(std::vector<int> & arr, int currentIndex, std::vector<int> & cache, std::vector<bool> & visited) {
        
    
        if(currentIndex < 0 || currentIndex >= arr.size() || visited[currentIndex])
            return false;
        
        if(arr[currentIndex] == 0)
            return true;
        
        if(cache[currentIndex] != -1)
            return cache[currentIndex];
        
        visited[currentIndex] = true;
        
        bool goingAhead = canReachHelper(arr, currentIndex + arr[currentIndex], cache, visited);
        
        bool goingBack = canReachHelper(arr, currentIndex - arr[currentIndex], cache, visited);
        
        visited[currentIndex] = false;
        
        cache[currentIndex] = goingAhead || goingBack;
        
        return cache[currentIndex];
        
        
        
    }
};
