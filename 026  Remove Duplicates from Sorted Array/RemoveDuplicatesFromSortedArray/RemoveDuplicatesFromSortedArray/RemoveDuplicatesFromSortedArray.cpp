#include <iostream>
<<<<<<< HEAD
#include <vector>

using namespace std;

/*
class Solution {
public:
	Solution(vector<int>& n):nums(n){}
    int removeDuplicates(vector<int>& nums) 
	{
        if (nums.size() == 0)
			return 0;
		else
		{
			unsigned int length = nums.size();
			unsigned int index=0;
			while(index++ < nums.size()-1)
			{
				if (nums[index] == nums[index-1])
					length --;
				
			}
			return length;
		}
    }
private:
	vector<int>& nums;
};
*/
int main(void)
{
	int a[] = {1,1,2};
	vector<int> v(a,a+(sizeof(a)/sizeof(a[0])));
	
	vector<int>&v_temp=v;
	Solution s(v_temp);
	int result = s.removeDuplicates(v_temp);
=======

using namespace std;

int main(void)
{
>>>>>>> origin/master
	return 0;
}
