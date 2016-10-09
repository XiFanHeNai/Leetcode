#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	Solution(){};
    string longestCommonPrefix(vector<string>& strs) 
	{

        int index=0;
		
		string result;
		if (strs.size() == 0)
			return result;
		else if (strs.size() == 1)
			return strs[0];
		else
		{
			int min_len=strs[0].size();
			result = strs[0];
			while(index++ < strs.size())
			{
				if (strs[index-1].size() == 0)
					return strs[index-1];

				if (min_len > strs[index-1].size())
				{
					min_len = strs[index-1].size();
					result.resize(min_len);
				}
			}

			int n=0;
			index=0;
			while(index++ < strs.size())
			{
				n=0;
				while((n < min_len) && (strs[index-1][n] == result[n])) n++;
			
				if (n<min_len)
					result.resize(n);

			}

			return result;
		}
    }
private:
	vector<string> str;
};

int main()
{
	//string str_array[] = {"manual","man","manufactory","max",""};
	string str_array[] = {"a","b"};
	Solution s;
	vector<string> str_vector(str_array,str_array+sizeof(str_array)/sizeof(string));
	//vector<string> str_vector;
	string result = s.longestCommonPrefix(str_vector);
	return 0;
}