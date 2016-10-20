#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	Solution(vector<vector<char>>& b):board(b){}
	bool isValidSudoku(vector<vector<char>>& board) {
		//vector<vector<int>> test(9,9);
		for (int row=0;row<9;row++)
		{
			vector<bool> row_valid(9,false);
			vector<bool> col_valid(9,false);
			vector<bool> grid_valid(9,false);
			for(int col=0;col<9;col++)
			{
				if (board[row][col] != '.')
				{
					// check the valid of one row
					if (row_valid[board[row][col] - '1'] == true)
						return false;
					else
						row_valid[board[row][col]- '1'] = true;
				}

				if (board[col][row] != '.')
				{
					// check the valid of one col
					if (col_valid[board[col][row] - '1'] == true)
						return false;
					else
						col_valid[board[col][row]- '1'] = true;
				}

				if (board[row/3*3+col/3][row%3*3+col%3] != '.')
				{
					// check the valid of one grid				
					if (grid_valid[board[row/3*3+col/3][row%3*3+col%3] - '1'] == true)
						return false;
					else
						grid_valid[board[row/3*3+col/3][row%3*3+col%3] - '1'] = true;
					//test[row][col] = row%3*3+col%3;

				}

			}
		}
		return true;
	}
private:
	vector<vector<char>>& board;
};

int main(void)
{
	string str[9] ={".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
	vector<vector<char>> temp_v(9,9);
	for (int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			temp_v[i][j] = str[i][j];
	vector<vector<char>>& v=temp_v;
	Solution s(v);
	bool result = s.isValidSudoku(v);
	return 0;
}