#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
	int single_data(vector<int> &nums)
	{
		int index=0,temp=0;
		while (index++<nums.size())
		{
			temp ^= nums[index-1];
		}
		return temp;
	}
};

int main()
{
	int a[]={1,3,2,4,5,7,1,3,2,4,5,7,21};
	vector<int> temp_v(a,a+sizeof(a)/sizeof(a[0]));
	vector<int> &v(temp_v);
	solution s;
	int result = s.single_data(v);
	cout << "the result is : " << result << endl; 
	cout << "Hello World" << endl;
	return 0;
}