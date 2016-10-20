#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	Solution(){}
    int lengthOfLastWord(string s) 
	{
		if ((s.size() == 0) || (s.size() == 1 && s[0] == ' '))
			return 0;
		else if (s.size() == 1)
			return 1;
		else
		{
			int length=0;
			int index=0;
			while (index++ < s.size())
			{
				if (index < s.size()) 
				{
					if (s[index-1] == ' ' && s[index] != ' ')
						length=0;
					else if (s[index-1] != ' ')
						length++;
				}
				else
				{
					if (s[index-1] == ' ')
						return length;
					else
						return length+1;
				}
			}
			return length;
		}
    }
private:
	string s;
};

int main(void)
{
	string str(" a ");
	Solution s;
	int result = s.lengthOfLastWord(str);
	return 0;
}