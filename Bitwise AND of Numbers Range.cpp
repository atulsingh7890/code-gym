//#include <iostream>
//#include <vector>
//#include <cassert>
//
//class Solution {
//public:
//	int formNumberFromBinaryRepresentation(std::vector<int> binary_represenation) {
//		int n = 0;
//		for (int i = 31; i >= 0; --i) {
//			if (binary_represenation[i]) {
//				n += (1 << (31 - i));
//			}
//		}
//
//		return n;
//	}
//
//	std::vector<int> findBinaryRepresentation(int m) {
//		std::vector<int> binary_representation(32, 0);
//		int index_put = 31;
//		while (m) {
//			m & 0x01 ? binary_representation[index_put] = 1 : binary_representation[index_put] = 0;
//			m >>= 1;
//			index_put--;
//		}
//		return binary_representation;
//	}
//
//	int rangeBitwiseAndBruteForce(int m, int n) {		
//		// Find the lowest power of 2 
//		int m_floor = floorPowerOfTwo(m);
//		int n_floor = floorPowerOfTwo(n);
//
//		if (m_floor != n_floor) {
//			return 0;
//		}
//
//		int result = 0;
//		while (m_floor == n_floor && m_floor != 0) {
//
//			result |= m_floor;
//
//			// Now Both Powers are same lets find if they are on the next power of two range
//			m ^= (m_floor);
//			n ^= (n_floor);
//
//			m_floor = floorPowerOfTwo(m);
//			n_floor = floorPowerOfTwo(n);			
//		}
//
//		if ( (m_floor == n_floor) &&(m_floor == 0) && (m == n ) && (n == 1)) {
//			result |= 1;
//		}
//
//
//		return result;
//	}
//
//
//	int floorPowerOfTwo(int n) {
//		int answer = 0;
//		while (n && ++answer && (n >> 1));
//		return answer > 1 ? 1 << (answer - 1) : 0;
//	}
//
//	int rangeBitwiseAnd(int m, int n) {
//
//		// int result = floorPowerOfTwo(m);        
//		// return result;
//
//		if (m == 0 || n == 0)
//			return 0;
//
//
//
//		rangeBitwiseAnd(m >> 1, n >> 1);
//
//	}
//};
//
//int main() {
//	{
//		//int m = 10;
//		Solution s;
//		//std::vector<int> binary_representation = s.findBinaryRepresentation(m);
//		//for (int i = 0; i < binary_representation.size(); ++i) {
//		//	std::cout << binary_representation[i];
//		//}
//		//std::cout << std::endl;
//		//std::cout << s.formNumberFromBinaryRepresentation(binary_representation) << std::endl;
//		int m = 5, n = 7;
//		int answer = s.rangeBitwiseAndBruteForce(m, n);
//		assert(answer == 4);
//		std::cout << answer << std::endl;
//
//	}
//
//	{
//		int m = 6, n = 7;
//		Solution s;
//		int answer = s.rangeBitwiseAndBruteForce(m, n);
//		assert(answer == 6);
//		std::cout << answer << std::endl;
//	}
//
//	{
//		int m = 2, n = 2;
//		Solution s;
//		int answer = s.rangeBitwiseAndBruteForce(m, n);
//		assert(answer == 2);
//		std::cout << answer << std::endl;
//	}
//
//	{
//		int m = 7, n = 11;
//		Solution s;
//		int answer = s.rangeBitwiseAndBruteForce(m, n);
//		assert(answer == 0);
//		std::cout << answer << std::endl;
//	}
//
//	{
//		int m = 7, n = 7;
//		Solution s;
//		int answer = s.rangeBitwiseAndBruteForce(m, n);
//		assert(answer == 7);
//		std::cout << answer << std::endl;
//	}
//
//}