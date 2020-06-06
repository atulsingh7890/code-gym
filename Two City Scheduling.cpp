//#include <vector>
//#include <list>
//#include <queue>
//#include <algorithm>
//
//
////class Solution {
////
////	struct CostOfFlying {
////		int cost_to_city_a;
////		int cost_to_city_b;	
////		bool already_placed;
////	};
////
////	template<typename T, typename C>
////	class custom_priority_queue : public std::priority_queue<T, std::list<T>, C>
////	{
////		using base_class = std::priority_queue<T, std::list<T>, C>;
////		using list_iterator = typename std::list<T>::iterator;		
////	public:
////		custom_priority_queue(C c, std::list<T> & underlying_container)
////		: base_class(c, underlying_container) {
////
////		}
////		void remove(list_iterator & it_to_remove) {
////			this->c.erase(it_to_remove);
////			std::make_heap(this->c.begin(), this->c.end(), this->comp);
////		}
////
////		std::list<T> & get_container() { return this->c; }
////	};
////
////	int computeCost(std::list<CostOfFlying>& list_a, std::list<CostOfFlying>& list_b) {
////
////	}
////
////public:
////	int twoCitySchedCost(const std::vector<std::vector<int>>& costs) {
////	
////		auto Prioritize_To_City_A = [](const CostOfFlying& a, const CostOfFlying& b) {
////			return a.cost_to_city_a < b.cost_to_city_a;
////		};
////
////		auto Prioritize_To_City_B = [](const CostOfFlying& a, const CostOfFlying& b) {
////			return a.cost_to_city_b < b.cost_to_city_b;
////		};
////
////
////				 
////		std::list<CostOfFlying> list_a,list_b;
////
////		for (auto& cost : costs) {			
////			//list_a.push_front({ cost[0], cost[1], list_b.begin() });
////			//list_b.push_front({ cost[0], cost[1], list_a.begin() });
////			//list_a.begin()->iterator_in_other_list = list_b.begin();
////			list_a.push_front({ cost[0], cost[1], false });
////			list_b.push_front({ cost[0], cost[1], false });
////		}
////
////
////		//custom_priority_queue<CostOfFlying, decltype(Prioritize_To_City_A)> min_heap_a(Prioritize_To_City_A, list_a);
////		//custom_priority_queue<CostOfFlying, decltype(Prioritize_To_City_B)> min_heap_b(Prioritize_To_City_B, list_b);
////
////		//std::sort(list_a.begin(), list_a.end(), Prioritize_To_City_A);
////		//std::sort(list_b.begin(), list_b.end(), Prioritize_To_City_B);
////		list_a.sort(Prioritize_To_City_A);
////		list_b.sort(Prioritize_To_City_B);
////
////		int persons_flied = 0;
////		int min_cost = 0;
////		int person_in_city_a = 0, persons_city_b = 0;
////		while (persons_flied++ < costs.size() ) {
////
////			CostOfFlying & current_min_a = *(list_a.begin());
////			CostOfFlying & current_min_b = *(list_b.begin());
////
////			//if (current_min_a.cost_to_city_a < current_min_b.cost_to_city_b && person_in_city_a < costs.size()/2) {
////			//	min_cost += current_min_a.cost_to_city_a;
////			//	list_b.erase(current_min_a.iterator_in_other_list);
////			//	list_a.erase(list_a.begin());
////			//	person_in_city_a++;
////			//}
////			//else {
////			//
////			//	if (persons_city_b < costs.size() / 2) {
////			//		min_cost += current_min_b.cost_to_city_b;
////			//		list_a.erase(current_min_b.iterator_in_other_list);
////			//		list_b.erase(list_b.begin());
////			//		persons_city_b++ ;
////			//	}
////			//	else {
////			//		min_cost += current_min_a.cost_to_city_a;
////			//		list_b.erase(current_min_a.iterator_in_other_list);
////			//		list_a.erase(list_a.begin());
////			//		person_in_city_a++;
////			//	}
////			//}
////			//
////			//
////			// Peek the elements from both the lists
////			//const CostOfFlying & current_min_a = min_heap_a.top();
////			//const CostOfFlying & current_min_b = min_heap_a.top();
////			//
////			//// See which one we nee to delete
////			//if (current_min_a.cost_to_city_a < current_min_b.cost_to_city_b) {
////			//	// This Person will go to City A
////			//	min_cost += current_min_a.cost_to_city_a;
////			//	// but first remove it from other list
////			//	min_heap_b.remove(current_min_a.iterator_in_other_list);				
////			//	min_heap_a.pop();
////			//}
////			//else {
////			//	min_cost += current_min_b.cost_to_city_b;
////			//	min_heap_a.remove(current_min_b.iterator_in_other_list);
////			//	min_heap_b.pop();
////			//}
////
////
////		}
////
////		return min_cost;	
////
////	}
////};
//
///*
//class Solution {
//
//
//public:
//	int twoCitySchedCost(const std::vector<std::vector<int>>& costs) {
//
//		int total_persons = costs.size();
//		std::vector<std::vector<int>> dp(total_persons, std::vector<int>(total_persons, 0));
//
//		//int cost_to_flying_to_a = 0;
//		//int cost_to_flying_to_b= 0;
//		//// Initializing the Fist Column and Diagonal
//		//for (int i = 0; i < total_persons; ++i) {
//		//	cost_to_flying_to_a += costs[i][0];
//		//	// we have total of i + 1 Persons , and i + 1 are going to City A
//		//	dp[i + 1][i + 1] = cost_to_flying_to_a;
//
//		//	// we have total of i + 1 Persons , and 0 are going to City A
//		//	cost_to_flying_to_b += costs[i][1];
//		//	dp[i + 1][0] = cost_to_flying_to_b;
//		//}
//
//		int cost_of_moving_all_to_city_b = 0;
//		for (int i = 0; i < costs.size(); ++i) {			
//
//			for (int j = 0; j <= i; ++j) {
//								
//				
//				if (i == j) {
//					// i People all going to City A
//					dp[i][j] = costs[i][0] + (i > 0 ? dp[i-1][j-1] : 0);
//				}
//				else {
//										
//					int cost_of__including_current_person_to_city_a_group = 0;
//
//					if (j == 0) {
//						cost_of_moving_all_to_city_b += costs[i][1];
//						cost_of__including_current_person_to_city_a_group = cost_of_moving_all_to_city_b + costs[i][0];
//					}
//					else {
//						cost_of__including_current_person_to_city_a_group = dp[i - 1][j - 1] + costs[i][0];
//					}
//
//
//					int cost_of__including_current_person_to_city_b_group = dp[i-1][j] + costs[i][1];
//
//
//					// Cost of having j people in City A , when total Persons are i
//					dp[i][j] = std::min(
//						cost_of__including_current_person_to_city_a_group,
//						cost_of__including_current_person_to_city_b_group
//					);
//					
//				}
//			}
//		}
//
//		return dp[total_persons-1][total_persons / 2 - 1];
//
//	}
//};
//*/
//
//class Solution {
//	using Int2DMatrix = std::vector<std::vector<int>>;
//	unsigned int dpHelper(const Int2DMatrix & costs, Int2DMatrix &dp_matrix ,int count_city_a, int count_city_b, int current_person) {
//		if (count_city_a == 0 && count_city_b == 0) {
//			return dp_matrix[count_city_a][count_city_b];
//		}
//
//		if (count_city_a < 0 || count_city_b < 0) {
//			return std::numeric_limits<unsigned int>::max();
//		}
//
//		if (dp_matrix[count_city_a][count_city_b]) {
//			return dp_matrix[count_city_a][count_city_b];
//		}
//
//		unsigned int min_cost_including_in_city_a = dpHelper(costs, dp_matrix, count_city_a - 1, count_city_b, current_person - 1);
//		if (min_cost_including_in_city_a != std::numeric_limits<unsigned int>::max()) {
//			min_cost_including_in_city_a += costs[current_person][0];
//		}
//
//		unsigned int min_cost_including_in_city_b = dpHelper(costs, dp_matrix, count_city_a, count_city_b - 1, current_person - 1);
//		if (min_cost_including_in_city_b != std::numeric_limits<unsigned int>::max()) {
//			min_cost_including_in_city_b += costs[current_person][1];
//		}
//
//		dp_matrix[count_city_a][count_city_b] = std::min(min_cost_including_in_city_a, min_cost_including_in_city_b);
//		return dp_matrix[count_city_a][count_city_b];
//	}
//public:
//	int twoCitySchedCost(const std::vector<std::vector<int>>& costs) {
//		Int2DMatrix dp_matrix( costs.size()/2 + 1,  std::vector<int>(costs.size()/2 + 1, 0));
//		return dpHelper(costs, dp_matrix, costs.size() / 2, costs.size() / 2, costs.size()-1);
//	}
//};
//
//
//int main() {
//	Solution s;
//	s.twoCitySchedCost({ {10, 20}, {30,200}, {400,50}, {30,20} });
//	s.twoCitySchedCost({ {259, 770}, {448,54}, {926,667}, {184,139}, {840,118}, {577, 469} });
//}