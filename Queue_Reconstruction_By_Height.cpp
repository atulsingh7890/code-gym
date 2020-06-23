//// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3352/
//
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//#include <list>
//
//class Solution {
//	using IntArray = std::vector<int>;
//	using Matrix = std::vector<IntArray>;	
//public:
//	Matrix reconstructQueue(Matrix & people) {
//		//sort in decreasing order of height and increasing order of K
//		std::sort(people.begin(), people.end(), [](const IntArray & a, const IntArray & b) {
//			if (a[0] == b[0])
//				return a[1] < b[1];
//			else
//				return a[0] > b[0];
//		});
//
//		
//		Matrix result;
//		for (int i = 0; i < people.size(); i++)
//		{
//			result.insert(result.begin() + people[i][1], people[i]);
//		}
//
//		return result;
//	}
//};
//
//int main() {
//	Solution s;
//	std::vector<std::vector<int>> matrix{ {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2} };
//	s.reconstructQueue(matrix);
//}