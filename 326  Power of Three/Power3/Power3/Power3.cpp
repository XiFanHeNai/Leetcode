#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	Solution(int t):n(t){}

    bool isPowerOfThree(int n) 
	{
        double power_largest = log((double)(0x7FFFFFFF)) / log(3.0);
		if ( ((unsigned int)pow(3.0,(double)(unsigned int)power_largest) % n) == 0 )
			return true;
		else
			return false;
    }
private:
	int n;
};

int main()
{
	Solution s(9);
	bool result = s.isPowerOfThree(81);
	cout << "Hello World !!! \n" << endl;
	return 0;
}