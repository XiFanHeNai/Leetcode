#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	Solution(){target=0;}

    vector<int> twoSum(vector<int>& nums, int target)
	{
        vector<int> result(2,0);
		unsigned int  index=0;
		map<int,int> hmap;
		unsigned int first_num;
		for (index=0;index < nums.size();++index)
		{
			if (hmap.count(nums[index]) == 0)//表中没有该值
				hmap.insert(pair<int,int>(nums[index],index));

			
			if (hmap.count(target-nums[index]) == 1)
			{
				first_num = hmap[target-nums[index]];

				if (first_num < index)
				{
					result[0] = first_num;
					result[1] = index;
					return result;
				}
			}
		}
		return result;
    }
private:
	vector<int> v;
	int target;
};


int main()
{
	int a[]={3,2,3};
	int target = 6;
	vector<int> v1(a,a+sizeof(a)/sizeof(int));
	vector<int> v2;
	Solution s1;
	v2 = s1.twoSum(v1,target);
	return 0;
}