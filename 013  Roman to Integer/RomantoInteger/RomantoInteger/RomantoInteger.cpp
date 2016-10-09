#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	Solution(string n):s(n){}

    int romanToInt(string s)
	{
        int result=0;
		int index=0;
		int first_data=0;
		int second_data=0;
		int third_data=0;


		while(index < s.size())
		{
			switch(s[index])
			{
			case 'I':	third_data = 1;break;
			case 'V':	third_data = 5;break;
			case 'X':	third_data = 10;break;
			case 'L':	third_data = 50;break;
			case 'C':	third_data = 100;break;
			case 'D':	third_data = 500;break;
			case 'M':	third_data = 1000;break;
			default:;
			}
			if ((first_data == 0) || (second_data == 0))
			{
				first_data = second_data;
				second_data = third_data;
			}
			else
			{
				if (first_data < second_data)
				{
					first_data = second_data-first_data;
					second_data = 0;
				}
				else if (second_data < third_data)
				{
					second_data = third_data-second_data;
					third_data = 0;
				}
				

				result = result+first_data+second_data;
				first_data = 0;
				second_data = third_data;
				third_data = 0;
			}
			index ++;
		}
		if (first_data < second_data)
		{
			first_data = second_data-first_data;
			second_data = 0;
		}

		result = result+first_data+second_data;
		return result;
    }
private:
	string s;
};

int main()
{
	/*
	I:			1
	II:			2
	III:		3
	IIII:		4
	V:			5
	VI:			6
	VII:		7
	VIII:		8
	IX:			9
	X:			10
	L:			50
	C:			100
	D:			500
	M:			1000
	*/
	Solution s("");
	int result = s.romanToInt("DCXXI");//621
	//int result = s.romanToInt("MCMXCVI");//1996
	//int result = s.romanToInt("MCMLXXX");//1980
	//int result = s.romanToInt("MCMLXX");//1970
	//int result = s.romanToInt("MMCDXXV");//2425
	//int result = s.romanToInt("MMCCCXCIX");//2399
	return 0;
}