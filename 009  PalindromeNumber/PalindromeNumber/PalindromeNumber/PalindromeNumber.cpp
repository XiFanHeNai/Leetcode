#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	Solution(int n):x(n){}
    bool isPalindrome(int x)
	{
        if (x<0)
			return false;
		else if (x<10 && x>=0)
			return true;
		else
		{
			//先求出输入参数的位数
			int b=0;
			int a=x;
			while(a > 0)
			{
				if ( (b>0x7fffffff/10) || ((b == 0x7fffffff/10)&&((a%10)>0x7fffffff-b*10)) )
					return false;
				b=b*10+(a%10);
				a=a/10;
			}
			if (x == b)
				return true;
			else
				return false;
		}
    }
private:
	int x;
};


int main()
{
	Solution s(0);
	//int result = s.isPalindrome(212);-2147483648
	//int result = s.isPalindrome(0x7fffffff);
	int result = s.isPalindrome(-2147483648);
}