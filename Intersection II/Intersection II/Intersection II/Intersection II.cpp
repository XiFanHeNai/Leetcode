#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
	Solution(vector<int>& n1, vector<int>& n2)
	{
		nums1 = n1;
		nums2 = n2;
	}

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> sta_nums1(nums1),sta_nums2(nums2);
		vector<int> result( (nums1.size() >= nums2.size())? nums1.size():nums2.size() );

		int index_nums1=0;
		int index_nums2=0;
		int result_len=0;

		//统计数组nums1
		int temp_index,count;
		while(index_nums1 < nums1.size())
		{
			count=0;
			for (temp_index=0;temp_index<nums1.size();temp_index++)
			{
				if (nums1[index_nums1] == nums1[temp_index])
				{
					count ++;
				}
			}
			sta_nums1[index_nums1] = count;
			index_nums1 ++;
		}

		//统计数组nums2并删除nums2和结果中的重复值
		//如果N在之前的统计中已经出现过，则当前不再统计
		int length=0;
		vector<int> new_nums2(nums2);
		while(index_nums2 < nums2.size())
		{
			count=0;
			int index_before=0;

			while( (index_before < index_nums2) && (nums2[index_before] != nums2[index_nums2]) )
				index_before ++;
			 if (index_before == index_nums2)
			 {
				for (temp_index=0;temp_index<nums2.size();temp_index++)
				{
					if (nums2[index_nums2] == nums2[temp_index])
					{
						count ++;
					}
				}
				new_nums2[length] = nums2[index_nums2];
				sta_nums2[length] = count;	 
				length ++;
			 }
			index_nums2 ++;
		}
		sta_nums2.resize(length);
		new_nums2.resize(length);


		//开始比较
		result_len=0;
		index_nums1=0;
		int index_newn2=0;
		int index_result=0;
		while(index_newn2 < new_nums2.size())
		{
			 while( (index_nums1 < nums1.size()) && (new_nums2[index_newn2] != nums1[index_nums1]))
				 index_nums1 ++;

			if (index_nums1 < nums1.size()) 
			{
				if (sta_nums2[index_newn2] <= sta_nums1[index_nums1])
				{
					result_len += sta_nums2[index_newn2];
					while(index_result < result_len)
					{
						result[index_result] = new_nums2[index_newn2];
						index_result ++;
					}
				}
				else
				{
					result_len += sta_nums1[index_nums1];
					while(index_result < result_len)
					{
						result[index_result] = new_nums2[index_newn2];
						index_result ++;
					}
				}
			}
			 index_newn2 ++;
			 index_nums1 = 0 ;
		}

		result.resize( result_len );

		return result;
    }
private:
	vector<int> nums1;
	vector<int> nums2;
};



void main()
{
	//int a1[] = {61,24,20,58,95,53,17,32,45,85,70,20,83,62,35,89,5,95,12,86,58,77,30,64,46,13,5,92,67,40,20,38,31,18,89,85,7,30,67,34,62,35,47,98,3,41,53,26,66,40,54,44,57,46,70,60,4,63,82,42,65,59,17,98,29,72,1,96,82,66,98,6,92,31,43,81,88,60,10,55,66,82,0,79,11,81};
	//int a2[] = {5,25,4,39,57,49,93,79,7,8,49,89,2,7,73,88,45,15,34,92,84,38,85,34,16,6,99,0,2,36,68,52,73,50,77,44,61,48};
	int a1[] = {2,3,1,1,2,3,1,2,2};
	//int a2[] = {2,3,1,3,1,2,2};
	vector<int> v1(a1,a1+(sizeof(a1)/sizeof(int)));
	//vector<int> v2(a2,a2+(sizeof(a2)/sizeof(int)));
	//vector<int> v1;
	vector<int> v2;
	vector<int> result;
	Solution s1(v1,v2);
	result = s1.intersect(v1,v2);
	cout << "Hello World !!" << endl;

}