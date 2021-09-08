//https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3965/
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxPressedTime = 0;
        int previousReleaseTime = 0;
        char slowestkey = 'a';
        for(int i = 0; i < releaseTimes.size(); ++i) {
            if(releaseTimes[i] - previousReleaseTime > maxPressedTime) {
                slowestkey = keysPressed[i];
                maxPressedTime = releaseTimes[i] - previousReleaseTime;
                
            } else if(releaseTimes[i] - previousReleaseTime == maxPressedTime) {
                slowestkey =  slowestkey > keysPressed[i] ? slowestkey : keysPressed[i];
            }            
            previousReleaseTime = releaseTimes[i];
        }
        
        return slowestkey;
    }
};
