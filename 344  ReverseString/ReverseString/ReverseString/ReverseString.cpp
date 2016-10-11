#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	Solution (string str):s(str){}
	string reverseString(string s) 
	{
        char temp_char;
		string result(s);
		int index=0;
		while(index < s.size()-index)
		{
			temp_char = result[index];
			result[index] = result[s.size()-index-1];
			result[s.size()-index-1] = temp_char;
			index ++;
		}

		return result;
	}
private:
	string s;
};


int main()
{
	Solution s("hello");
	string result;
	result = s.reverseString("");
	cout << "Hello World !!! \n" << endl;
	return 0;
}