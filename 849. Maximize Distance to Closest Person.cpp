class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int lastOneAt = -1;
        int result = 0;
        int maxDiff = std::numeric_limits<int>::min();
        for(int i = 0; i < seats.size(); ++i) {
            if(seats[i] == 1) {
                if(lastOneAt != -1) {                    
                    int current_seat = (i + lastOneAt)/2;
                    if(i - current_seat > maxDiff) {
                        result = current_seat;
                        maxDiff = std::min(i - current_seat, current_seat - lastOneAt);
                    }
                } else {
                    maxDiff = i;
                }
                lastOneAt = i;
            }
        }
        
        
        //process the last one
        int current_seat_diff = seats.size() - 1 - lastOneAt;
        if(current_seat_diff > maxDiff) {
            result = seats.size() - 1;
            maxDiff = current_seat_diff;
        }
        return maxDiff;
    }
};
