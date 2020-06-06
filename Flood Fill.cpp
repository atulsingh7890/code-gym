//#include <vector>
//#include <queue>
//#include <unordered_map>
//#include <functional>
//
//using namespace std;
//
//class Solution {
//
//public:
//	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {		
//		
//		using Pixel = struct { int row; int col; };
//
//		std::vector<Pixel> neighbours = { {-1,0}, {1,0}, {0,-1}, {0,1} };
//
//		std::queue<Pixel> pixels_to_process;		
//
//		auto PixelHash = [](const Pixel &x) {  return std::hash<int>()(x.row) ^ std::hash<int>()(x.col);  };
//
//		auto PixelEqual = [](const Pixel& lhs, const Pixel& rhs) { return lhs.row == rhs.row && lhs.col == rhs.col;	};
//
//		std::unordered_map<Pixel, bool, decltype(PixelHash), decltype(PixelEqual)> already_processed_pixels_(10, PixelHash, PixelEqual );
//
//		pixels_to_process.push({ sr,sc });
//
//		auto IsWithinBounds = [&](const Pixel & pixel) {
//			return 0 <= pixel.row && pixel.row < image.size()
//				&& 0 <= pixel.col && pixel.col < image[0].size();
//		};
//
//		auto AlreadyNotProcessed = [&](const Pixel & pixel) {
//			return already_processed_pixels_.find(pixel) == already_processed_pixels_.end();
//		};
//
//
//		while (false == pixels_to_process.empty()) {
//
//			Pixel current_center_pixel = pixels_to_process.front();
//			pixels_to_process.pop();
//
//			for (auto & n : neighbours) {
//				Pixel current_neighbour{ current_center_pixel.row + n.row,\
//										current_center_pixel.col + n.col };
//
//				if (IsWithinBounds(current_neighbour)
//					&& AlreadyNotProcessed(current_neighbour)
//					&& (image[current_neighbour.row][current_neighbour.col] == image[current_center_pixel.row][current_center_pixel.col])) {					
//					pixels_to_process.push(current_neighbour);
//				}
//			}
//
//			
//			image[current_center_pixel.row][current_center_pixel.col] = newColor;
//			already_processed_pixels_[current_center_pixel] = true;
//
//		}
//
//		return image;
//
//	}
//};
//
//int main() {
//	{
//		std::vector<std::vector<int>> input_matrix = { {1,1,1}, {1,1,0}, {1,0,1} };
//		int s_c = 1;
//		int s_r = 1;
//		int newColor = 2;
//		Solution s;
//		s.floodFill(input_matrix, s_r, s_c, newColor);
//	}
//}