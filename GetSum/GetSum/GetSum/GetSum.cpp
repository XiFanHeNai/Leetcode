#include <iostream>

using namespace std;

class Solution {
public:
	Solution(int m,int n)
	{
		a=m;
		b=n;
	}

    int getSum(int a, int b) {
        int sum=0,temp_sum=0;
		unsigned int flag=0;
		int add_a = a;
		int add_b = b;
		int carry=0;
		unsigned char index=0;
		if (a == 0)
			return b;
		if (b == 0)
			return a;

		sum=0;
		carry=0;
		for (index=0;index<32;index++)
		{
			add_a = (a>>index)&0x01;
			add_b = (b>>index)&0x01;
			temp_sum = ((~add_a)&add_b) | (add_a&(~add_b));
			temp_sum = ((~temp_sum)&carry) | (temp_sum&(~carry));
			carry = (add_a&add_b) | (add_b&carry) | (add_a&carry);

			sum = sum | temp_sum<<index;
		}

		return sum;
    }
private:
	int a;
	int b;
	/*
	int add_once(int add_a, int add_b)
	{
		int sum=0;
		int temp_a = add_a&0x1;
		int temp_b = add_b&0x1;
		return ((~temp_a)&temp_b) | (temp_a&(~temp_b));

	}
	*/
	
};


int main()
{
	class Solution s1(0,0);
	int sum;
	sum = s1.getSum(7,-5);
	cout << sum <<endl;

	cout << "Hello World \n" << endl;
}