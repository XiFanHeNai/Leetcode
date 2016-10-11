#include <iostream>

using namespace std;


class Solution {
public:
	Solution (string temps,int n):s(temps),numRows(n){};
	string convert(string s, int numRows) 
	{
		unsigned int index=0;
		int row_count=0;
		int index_row=0;
		string s1(s);

		if (((unsigned int)numRows >=  s1.size()) || (numRows <= 1))
		{
			return s1;
		}
		int period = 2*numRows-2;
		while (row_count<numRows)
		{
			while(index < s.size())
			{
				if (index%period == row_count)
				{				
					s1[index_row++] = s[index];
					if ((row_count > 0) && (row_count < numRows-1) && (index+2*row_count < s.size()))
						s1[index_row++] = s[index+2*row_count];


				}
				++index;
			}
			row_count++;
			index=0;
		}
		return s1;
    }
private:
	string s;
	int numRows;
};

int main()
{
	string s("ABCD");
	Solution s1(s,3);
	string result = s1.convert(s,3);

	cout << "Hello World !!! \n" << endl;

	return 0;
}