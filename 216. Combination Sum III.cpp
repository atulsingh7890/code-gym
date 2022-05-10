class Solution {
    
    void find_combinations(int digits_required, int sum_remaining,int pos,std::vector<int> & c_vec) {
        if(sum_remaining < 0 || digits_required < 0)
            return;
        
        if(digits_required == 0 && sum_remaining == 0) {           
                result.push_back(c_vec);            
        } else {
            for(int i = pos; i <= 9; ++i  ) {
                c_vec.emplace_back(i);
                find_combinations(digits_required-1, sum_remaining - i, i+1, c_vec);
                c_vec.pop_back();                
            }
        }
    }
    void print_set(const std::set<int> & set ) {
        for(auto n : set) {
            std::cout << n << " " ;
        }
        std::cout << endl;
    }
    void print_combs(const std::set<std::set<int>> & sets) {
        std::cout << "\t";
        for(auto & set : sets) {
            std::cout << "\t\t";
            print_set(set);
        }
        std::cout << endl;
    }


    std::set<std::set<int>> combinations;
    std::vector<std::vector<int>> result;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        std::set<int> current_combination;
        std::vector<int> c_vec;
        
        find_combinations(k, n, 1, c_vec);
        return result;
    }
};
