class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        std::string sequence = "123456789";
        std::vector<int> result;
        for(int sequence_length = 2; sequence_length <= 9; ++sequence_length) {
            for(int sequence_start = 0; sequence_start + sequence_length <= 9; ++sequence_start) {
                //for the current number with sequence
                int sequence_end = sequence_start + sequence_length - 1;
                int current_number_in_sequence = 0;
                for(int s = sequence_start; s <= sequence_end; ++s) {
                    current_number_in_sequence *= 10;
                    current_number_in_sequence += (sequence[s] - '0');
                }
                //std::cout << current_number_in_sequence << std::endl;
                if(current_number_in_sequence >= low && current_number_in_sequence <= high)
                    result.push_back(current_number_in_sequence);
            }
        }
        
        std::sort(result.begin(), result.end());
        return result;
    }
};
