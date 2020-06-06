//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <cstdlib>
//#include <set>
//
//using namespace std;
//
//class Solution {
//public:
//
//	using TableMap =  std::map< int, std::map<std::string, int>>;
//
//	void UpdateTableNumberWithFoodItem(int table_number, std::string food_item, TableMap & table_map) {
//		table_map[table_number][food_item]++;
//		/*auto it = table_map.find(table_number);
//		if (it == table_map.end()) {
//			table_map[table_number][food_item]++;
//		}*/
//	}
//
//	vector<vector<string>> displayTable(vector<vector<string>>& orders) {
//
//		std::map< int, std::map<std::string, int>> result_map;
//		std::set<std::string> food_items;
//
//		for (auto order : orders) {
//			int table_number = std::atoi(order[1].c_str());
//			std::string food_item = order[2];
//
//			UpdateTableNumberWithFoodItem(table_number, food_item, result_map);
//
//			food_items.insert(food_item);
//
//			
//		}
//
//		vector<vector<string>>  result_display_order;
//		std::vector<std::string> header_row;
//		header_row.push_back("Table");
//
//		for (auto food_item : food_items) {
//			header_row.push_back(food_item);
//		}
//
//		result_display_order.push_back(header_row);
//
//
//
//		for (auto table : result_map) {
//			int table_number = table.first;
//			auto & food_items_on_this_table = table.second;
//
//			std::vector<std::string> current_row;
//			current_row.push_back(std::to_string(table_number));
//
//			for (auto food_item : food_items) {
//
//				auto it_food_item = food_items_on_this_table.find(food_item);
//				if (it_food_item != food_items_on_this_table.end()) {
//					int number_of_current_food_items = it_food_item->second;
//					current_row.push_back(std::to_string(number_of_current_food_items));
//				}
//				else {
//					current_row.push_back("0");
//				}
//			}
//			result_display_order.push_back(current_row);
//		}
//
//		return result_display_order;
//	}
//};
//
//int main() {
//
//	Solution s;
//	//std::vector<std::vector<std::string>> orders = {{"Laura", "2", "Bean Burrito"}, {"Jhon", "2", "Beef Burrito"}, {"Melissa", "2", "Soda"}};
//
//	std::vector<std::vector<std::string>> orders = {{"David", "3", "Ceviche"}, {"Corina", "10", "Beef Burrito"}, {"David", "3", "Fried Chicken"}, {"Carla", "5", "Water"}, {"Carla", "5", "Ceviche"}, {"Rous", "3", "Ceviche"}};
//
//	s.displayTable(orders);
//}