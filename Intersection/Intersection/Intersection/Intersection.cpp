#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	Solution(vector<int> n1, vector<int> n2)
	{
		nums1 = n1;
		nums2 = n2;
	}
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> temp_result(nums1.size());
		vector<int> result((nums1.size()>nums2.size())? nums1.size():nums2.size());//取较长的数组的长度作新建结果数组
		int index_temp=0;//index in temp_result
		int index_num1=0;//index in num1
		int index_num2=0;//index in num2
		int len=0;

		if ((nums1.size() == 0) 
			|| (nums2.size() == 0))//其中一个为空，则直接返回空
		{
			result.resize(0);
			return result;
		}

		
		while(index_num1 < nums1.size())
		{
			while(index_num2 < nums2.size())
			{
				if ((nums1[index_num1] == nums2[index_num2]))
				{
					if (len == 0)
					{
						temp_result[0] = nums1[index_num1];
						len++;
					}
					else
					{
						index_temp=0;
						while((index_temp < len) && (temp_result[index_temp] != nums2[index_num2])) //剔除已存在的潜在交点
							index_temp++;

						if (index_temp == len)//发现新的潜在交点
						{
							temp_result[index_temp] = nums2[index_num2];
							len++;
						}
					}
				}
				index_num2++;
			}
			index_num2=0;
			index_num1++;
		}
		result = temp_result;
		result.resize(len);
		return result;
    }
private:
	vector<int> nums1;
	vector<int> nums2;
};
int main()
{
	//int a1[] = {2};
	//int a1[]={1};
	//vector<int> v1(a1,a1+(sizeof(a1)/sizeof(int))) ;
	vector<int> v1(0);
	int a2[] = {2};
	//int a2[]={1};
	vector<int> v2(a2,a2+(sizeof(a2)/sizeof(int))) ;


	Solution s1(v1,v2);
	vector<int> result = s1.intersection(v1,v2);
	int index=0;
	for (index=0;index<result.size();index++)
		cout << result[index] << endl;


	cout << "Hello World \n" << endl;
	return 0;
}
