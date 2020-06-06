//// CodeGym.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//#include <vector>
//
//int main()
//{
//	int testcases = 0;
//	std::cin >> testcases;
//	while (testcases--) {
//		int numbers_of_slots = 0;
//		std::cin >> numbers_of_slots;
//		int result = 1;
//		int distance = 0;
//		bool first_one_encountered = false;
//		for (int i = 0; i < numbers_of_slots; ++i) {
//			int current_slot = 0;
//			std::cin >> current_slot;					
//			if (result) {
//				switch (current_slot)
//				{
//				case 0:
//					distance++;
//					break;
//				case 1:
//					if (first_one_encountered && distance < 5) {
//						result = 0;
//					}
//					distance = 0;
//					first_one_encountered = true;
//					break;
//				}
//			}
//		}
//		if (result) {
//			std::cout << "YES" << std::endl;
//		}
//		else {
//			std::cout << "NO" << std::endl;
//		}
//	}
//}
//
