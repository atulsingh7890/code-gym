//#include <iostream>
//#include <vector>
//
//#include <stdlib.h>
//#include <time.h>
//
//namespace random {
//	int GetRandomNumber(int min_value, int max_value) {
//		srand(time(nullptr));
//		return min_value + rand() % (max_value - min_value + 1);
//	}
//}
//
//std::vector<int> BuildNumbers(const int n) {
//	std::vector<int> result(n);
//	for (int i = 0; i < n; ++i) {
//		result[i] = i + 1;
//	}
//	return std::move(result);
//}
//
//struct RightShift {
//	int index_1_;
//	int index_2_;
//	int index_3_;
//};
//
//void PrintVector(const std::vector<int> & input) {
//	for (int i = 0; i < input.size(); ++i) {
//		std::cout << input[i] << "\t";
//	}
//	std::cout << "\n";
//}
//
//std::vector<RightShift> PerformJumplingUp(
//	std::vector<int> & input_array,
//	int steps_to_jumble) {
//	
//	std::vector<RightShift> result;
//
//	auto PerformRightCyclicShift = [&](RightShift rightShift) {
//		int temp = input_array[rightShift.index_3_];
//		input_array[rightShift.index_3_] = input_array[rightShift.index_2_];
//		input_array[rightShift.index_2_] = input_array[rightShift.index_1_];
//		input_array[rightShift.index_1_] = temp;		
//	};
//	
//	const int size_of_array = input_array.size() - 1;
//
//	while (steps_to_jumble--) {
//		
//		int index_1 = random::GetRandomNumber(0, size_of_array - 1);
//		
//		int index_2 = random::GetRandomNumber(0, size_of_array - 1);
//		while(index_2 == index_1)
//			index_2 = random::GetRandomNumber(0, size_of_array - 1);
//
//		int index_3 = random::GetRandomNumber(0, size_of_array - 1);
//		while (index_3 == index_1 || index_3 == index_2)
//			index_3 = random::GetRandomNumber(0, size_of_array - 1);
//
//
//		RightShift right_shift{ index_1, index_2, index_3 };
//		PerformRightCyclicShift(right_shift);
//		result.push_back(right_shift);
//	}
//
//	return std::move(result);
//}
//
//int TripletSort(std::vector<int> & input_array) {
//	// Positions which are not at the correct position
//	
//}
//
//
//int main() {
//	int number_of_triple_swaps = 4;
//	int size_of_array = 10;
//	std::vector<int> input_array = BuildNumbers(size_of_array);
//	PrintVector(input_array);	
//	std::vector<RightShift> triple_shifts = PerformJumplingUp(input_array, number_of_triple_swaps);
//	PrintVector(input_array);
//}