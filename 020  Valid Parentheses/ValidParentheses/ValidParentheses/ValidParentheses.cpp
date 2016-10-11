#include <iostream>

using namespace std;

class Solution {
public:
	Solution(string str):s(str){}
    bool isValid(string s)
    {
        int len=0;
		int index=0;

		if (s.size()%2 != 0)
			return false;
		else
		{
			string str;
			while(index++ < s.size())
			{
				if ( (len  == 0) && ((s[index-1] == ')') || (s[index-1] == ']') || (s[index-1] == '}')) )
					return false;
				else 
				{
					if ((s[index-1] == '(') || (s[index-1] == '[') || (s[index-1] == '{'))
					{
						len++;
						str.resize(len);
						str[len-1] = s[index-1];
					}
					else
					{
						if ( ((s[index-1] == ')')&&(str[len-1] == '('))||
							 ((s[index-1] == ']')&&(str[len-1] == '['))||
							 ((s[index-1] == '}')&&(str[len-1] == '{')) )
						{
							len --;
							str.resize(len);
						}
						else
							return false;
					}
				}
			}		
			if (len == 0)
				return true;
			else
				return false;
		}
    }
private:
	string s;
};

int main()
{
	//char a[] = "{}()[]";
	//char a[] = "{[()]((}}[]}";
	//char a[] = "{}()[";
	//char a[] = "{[()]}";
	char a[] = "";
	string str(a);
	Solution s(str);

	bool result = s.isValid(str);
	return 0;
}
