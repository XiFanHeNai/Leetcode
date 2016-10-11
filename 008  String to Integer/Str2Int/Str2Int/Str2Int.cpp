#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	Solution(string s):str(s){};
	
	int myAtoi(string str) 
	{
        int result=0;

		unsigned int index=0;
		int flag=1;
		while( (index<str.size()) && (str[index] == ' ') )	index++;
		if (index == str.size())	return 0;//排除所有的空格，如果输入只有空格返回0

		if ((str[index] == '-') || (str[index] == '+') )
		{
			flag = (str[index] == '-') ? -1:1;
			index++;
		}

		{
			
			while( (index<str.size()) && (str[index] <= '9') && (str[index] >= '0') )//确定是数据
			{
				if ((flag == 1) &&
					((result > 0x7fffffff/10) ||
						((result == 0x7fffffff/10) && (7 < (str[index]-'0')))
					))
						return 0x7fffffff;

				if ((flag == -1) && (result != 0) &&
					((result < ((int)0x80000000)/10) ||
						((result == ((int)0x80000000)/10) && (8 < (int)(str[index]-'0')))
					))
					return 0x80000000;
				result = result*10 + flag*(str[index]-'0');
				index++;
			}
			
		}
		return result;
    }
private:
	string str;

};


/*
class Solution {
public:
	Solution(string s):str(s){};

    int myAtoi(string str) 
    {
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i++] == '-'); 
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (base >  0x7fffffff / 10 || (base == 0x7fffffff / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return 0x7fffffff;
            else return 0x80000000;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
    }
private:
	string str;
};
*/
int main()
{
	Solution s("  -1A2");
	//int result = s.myAtoi("-0013");
	//int result = s.myAtoi("1");
	//int result = s.myAtoi("-0");
	//int result = s.myAtoi("-2147483648");
	//int result = s.myAtoi("-2147483647");
	int result = s.myAtoi("      -11919730356x");
	cout << "Hello World !!! \n" << endl;
	return 1;
}