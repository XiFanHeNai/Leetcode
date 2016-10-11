#include <iostream>

using namespace std;

class Solution {
public:
	Solution(int n):x(n){};
    int reverse(int x)
	{
		unsigned int a=0;
		if ( (x>-10) && (x<10) )
			return x;

		unsigned int b = unsigned int ((x>=0)?x:-x);
		while(b>0)
		{
			a = 10*(a)+(b%10);
			b=b/10;

			if ((b>0) && ((a > 0x7fffffff/10)||(b > 0x7fffffff-a*10)) )
				return 0;
		}
		return (x>=0)?(int)a:-(int)a;
    }
private:
	int x;
};

int main()
{
	Solution s(0);
	int result = s.reverse(-2147483412);//-2143847412
	//int result = s.reverse(2147483647);
	//int result = s.reverse(-10);
	cout << "Hello World !!! \n " << endl;
	return 0;
}