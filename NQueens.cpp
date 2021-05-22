
class Solution {
	void print(std::vector<std::string>& matrix) {
		for (auto& str : matrix) {
			std::cout << str << "\n";
		}
	}

	bool IsQueenPresentInRow(std::vector<std::string>& matrix, int row) {
		bool queen_present_in_same_row = false;
		for (int c = 0; c < matrix.size(); ++c) {
			if (matrix[row][c] == 'Q') {
				queen_present_in_same_row = true;
				break;
			}
		}
		return queen_present_in_same_row;
	}

	bool IsQueenPresentInCol(std::vector<std::string>& matrix, int col) {
		bool queen_present_in_same_col = false;
		for (int r = 0; r < matrix.size(); ++r) {
			if (matrix[r][col] == 'Q') {
				queen_present_in_same_col = true;
				break;
			}
		}
		return queen_present_in_same_col;
	}

	bool IsQueenPresentInPrimaryDiagonal(std::vector<std::string>& matrix, int row, int col) {
		bool queen_present = false;

		//check upwards first
		int i = row, j = col;
		while (i >= 0 && j >= 0) {
			if (matrix[i][j] == 'Q') {
				queen_present = true;
				break;
			}
			i--, j--;
		}

		if (false == queen_present) {
			// now check downwards
			int i = row, j = col;
			while (i < matrix.size() && j < matrix.size()) {
				if (matrix[i][j] == 'Q') {
					queen_present = true;
					break;
				}
				i++, j++;
			}
		}

		return queen_present;
	}

	bool IsQueenPresentInSecondaryDiagonal(std::vector<std::string>& matrix, int row, int col) {
		bool queen_present = false;

		//check upwards first
		int i = row, j = col;
		while (i >= 0 && j < matrix.size()) {
			if (matrix[i][j] == 'Q') {
				queen_present = true;
				break;
			}
			i--, j++;
		}

		if (false == queen_present) {
			// now check downwards
			int i = row, j = col;
			while (i < matrix.size() && j >= 0) {
				if (matrix[i][j] == 'Q') {
					queen_present = true;
					break;
				}
				i++, j--;
			}
		}

		return queen_present;
	}

	bool IsSafeToPutQueen(std::vector<std::string>& matrix, int row, int col) {
		return  false == IsQueenPresentInRow(matrix, row) &&
			false == IsQueenPresentInCol(matrix, col) &&
			false == IsQueenPresentInPrimaryDiagonal(matrix, row, col) &&
			false == IsQueenPresentInSecondaryDiagonal(matrix, row, col);
	}


	void solveNQueenHelper(std::vector<std::string>& matrix, int rowstart, int colstart,int queens_to_put) {
		if (queens_to_put == 0) {
			results.push_back(matrix);
			return;
		}

		//find the first position which is safe to put queen 
		for (int i = rowstart; i < matrix.size(); ++i) {
			for (int j = colstart; j < matrix[i].size(); ++j) {
				if (matrix[i][j] != 'Q' && IsSafeToPutQueen(matrix, i, j)) {
					//its safe to put queen here put the queen here and see
					matrix[i][j] = 'Q';									
					solveNQueenHelper(matrix, i, 0, queens_to_put - 1);
					matrix[i][j] = '.';
				}
			}
		}		
	}

	std::vector<std::vector<std::string>> results;

public:
	std::vector<std::vector<std::string>> solveNQueens(int n) {

		std::vector<std::string> matrix(n, std::string(n, '.'));

		solveNQueenHelper(matrix, 0, 0, n);

		return results;

	}
};
