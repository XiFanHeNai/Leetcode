#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	Solution(){}
    string addBinary(string a, string b) {
        if (a.size() == 0)
			return b;
		else if (b.size() == 0)
			return a;
		else
		{
			string longer_str = (a.size() >= b.size())?a:b;
			string shorter_str = (a.size() < b.size())?a:b;

			string result = longer_str;
			unsigned int index=0;
			char carry=0;
			unsigned int longer_length=longer_str.size();
			unsigned int shorter_length=shorter_str.size();

			while(index++ < longer_length)
			{
				if (index-1 < shorter_length)
				{
					if (longer_str[longer_length-index] == '1' && shorter_str[shorter_length-index] == '1')
					{
						result[longer_length-index] = (carry == '1')? '1':'0';
						carry = '1';
					}
					else if (longer_str[longer_length-index] == '0' && shorter_str[shorter_length-index] == '0')
					{
						result[longer_length-index] = (carry == '1')? '1':'0';
						carry = '0';
					}
					else 
					{
						result[longer_length-index] = (carry == '1')? '0':'1';
						carry = (carry == '1')? '1':'0';
					}
				}
				else
				{
					/* 需要按照长度区分两个输入的数据，以便于后续处理特殊情况 */
					if (longer_str[longer_length-index] == '1' && carry == '1')
					{
						result[longer_length-index] = '0';
						carry = '1';
					}
					else
					{
						result[longer_length-index] = (carry == '1')? '1':result[longer_length-index];
						carry = '0';
						break;
					}
				}
				
			}
			if (carry == '1')
				result.insert(0,"1");
			return result;
		}
    }
private:
	string a;
	string b;
};


int main(void)
{
	string a("1");
	string b("1");
	Solution s;
	string result = s.addBinary(a,b);
	return 0;
}