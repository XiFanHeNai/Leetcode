#include <iostream>

using namespace std;

class Solution {
public:
	Solution(int n):num(n){}

    bool isPowerOfFour(int num) {
        if ((num>0) && ((num & (num-1)) == 0) && ((num & 0x55555555) != 0))
			return true;
		else
			return false;
    }
private:
	int num;
};


int main()
{
	Solution s(4);
	bool result = s.isPowerOfFour(-4);
	cout << "Hello World !!! \n" << endl;
	return 0;
}